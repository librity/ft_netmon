// SOURCE: https://www.youtube.com/watch?v=_n2hE2gyPxU&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=29

// gcc thread_pool_cancel.c && ./a.out

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define RUNTIME_SECONDS 5

#define WORKER_THREAD_COUNT 20
#define SCHEDULER_THREAD_COUNT 2

#define THREAD_EXIT_OK 0
#define THREAD_RUNNING 1
#define THREAD_ERR 2

#define SCHEDULER_DELAY_SECONDS 15

#define TASK_QUEUE_SIZE 256
#define TASK_DELAY_SECONDS 1

#define TIME_BUFFER_SIZE 26

typedef struct s_task
{
	char		*time;
	int			a;
	int			b;
}				t_task;

t_task			task_queue[TASK_QUEUE_SIZE];
int				task_count = 0;

typedef void	*(*t_thread_routine)(void *);

pthread_t		workers[WORKER_THREAD_COUNT];
int				worker_returns[WORKER_THREAD_COUNT];

pthread_t		schedulers[SCHEDULER_THREAD_COUNT];
int				scheduler_returns[SCHEDULER_THREAD_COUNT];

pthread_mutex_t	queue_mutex;
pthread_cond_t	queue_cond;

void	die(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

char	*get_tsafe_ascii_time(void)
{
	time_t		rawtime;
	struct tm	timeinfo;
	void		*result;
	char		*ascii_time;
	char		*endline;

	time(&rawtime);

	result = localtime_r(&rawtime, &timeinfo);
	if (result == NULL)
		die("Unable to convert rawtime to calendar time.");

	ascii_time = malloc(ASCTIME_STRING_SIZE);
	result = asctime_r(&timeinfo, ascii_time);
	if (result == NULL)
	{
		free(ascii_time);
		die("Unable to convert calendar time to a human-readable string.");
	}

	endline = strstr(ascii_time, "\n");
	if (endline != NULL)
		*endline = '\0';

	return (ascii_time);
}

void	execute_task(t_task *task)
{
	int	result;

	sleep(TASK_DELAY_SECONDS);
	result = task->a + task->b;
	printf("%s: %d + %d = %d\n", task->time, task->a, task->b, result);
	free(task->time);
}

void	log_task_count(void)
{
	printf("task_count: %d\n", task_count);
}

void	increase_task_count(void)
{
	task_count++;
	log_task_count();
}

void	decrease_task_count(void)
{
	task_count--;
	log_task_count();
}

void	enqueue_task(t_task task)
{
	pthread_mutex_lock(&queue_mutex);
	task_queue[task_count] = task;
	increase_task_count();
	pthread_mutex_unlock(&queue_mutex);
	pthread_cond_signal(&queue_cond);
}

void	wait_for_task(void)
{
	while (task_count == 0)
		pthread_cond_wait(&queue_cond, &queue_mutex);
}

t_task	dequeue_task(void)
{
	t_task	task;
	int		i;

	task = task_queue[0];
	i = 0;
	while (i < task_count - 1)
	{
		task_queue[i] = task_queue[i + 1];
		i++;
	}
	decrease_task_count();
	return (task);
}

t_task	new_task(void)
{
	t_task	new;

	new = (t_task){
		.time = get_tsafe_ascii_time(),
		.a = rand() % 100,
		.b = rand() % 100};
	return (new);
}

void	disable_cancellation(void)
{
	int set_result;

	set_result = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	if (set_result != 0)
		die("Unable to disable cancellation state of thread.");
}

void	enable_cancellation(void)
{
	int set_result;

	set_result = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if (set_result != 0)
		die("Unable to enable cancellation state of thread.");
}

void	switch_deffered(void)
{
	int set_result;

	set_result = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	if (set_result != 0)
		die("Unable to switch cancelability type of thread to deffered.");
}

void	switch_async(void)
{
	int set_result;

	set_result = pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	if (set_result != 0)
		die("Unable to switch cancelability type of thread to asynchronous.");
}

int	*find_thread_status(pthread_t threads[],
				int returns[],
				int thread_count)
{
	pthread_t id;
	int	i;

	id = pthread_self();
	i = 0;
	while (i < thread_count)
	{
		if (id == threads[i])
			return (returns + i);
		i++;
	}
	return (NULL);
}

int	*find_status_or_exit(pthread_t threads[],
				int returns[],
				int thread_count)
{
	int 	*return_writer;

	return_writer = find_thread_status(threads, returns, thread_count);
	if (return_writer == NULL)
	{
		printf("Closing scheduler thread %lu: Unable to find return writer pointer.\n", pthread_self());
		pthread_exit(NULL);
	}
	return (return_writer);
}

int	*find_worker_return_writer(void)
{
	return (find_status_or_exit(workers, worker_returns, WORKER_THREAD_COUNT));
}

void	exit_worker_cleanly(void *_arg)
{
	int 	*return_writer;

	return_writer = find_worker_return_writer();
	*return_writer = THREAD_EXIT_OK;
	printf("Exiting worker thread %lu: thread termination activated.\n", pthread_self());
	pthread_mutex_unlock(&queue_mutex);
}

void	init_worker(void)
{
	int 	*return_writer;

	disable_cancellation();
	return_writer = find_worker_return_writer();
	*return_writer = THREAD_RUNNING;
	enable_cancellation();
}

void	*run_worker(void *_args)
{
	t_task	task;

	init_worker();
	pthread_cleanup_push(&exit_worker_cleanly, NULL);

	while (true)
	{
		pthread_mutex_lock(&queue_mutex);
		wait_for_task();
		task = dequeue_task();
		pthread_mutex_unlock(&queue_mutex);
		execute_task(&task);
	}

	pthread_cleanup_pop(NULL);
    return NULL;
}

int	*find_scheduler_return_writer(void)
{
	return (find_status_or_exit(schedulers, scheduler_returns, SCHEDULER_THREAD_COUNT));
}

void	exit_scheduler_cleanly(void *_arg)
{
	int 	*return_writer;

	return_writer = find_scheduler_return_writer();
	*return_writer = THREAD_EXIT_OK;
	printf("Exiting scheduler thread %lu: thread termination activated.\n", pthread_self());
	pthread_mutex_unlock(&queue_mutex);
}

void	init_scheduler(void)
{
	int 	*return_writer;

	disable_cancellation();
	return_writer = find_scheduler_return_writer();
	*return_writer = THREAD_RUNNING;
	enable_cancellation();
}


void	*run_scheduler(void *_args)
{
	init_scheduler();
	pthread_cleanup_push(&exit_scheduler_cleanly, NULL);

	while (true)
	{
		enqueue_task(new_task());
		sleep(SCHEDULER_DELAY_SECONDS);
	}

	pthread_cleanup_pop(NULL);
	return NULL;
}

void	spawn_threads(pthread_t threads[],
		t_thread_routine routine,
		int thread_count,
		char *fmt)
{
	int	i;
	int	result;

	i = 0;
	while (i < thread_count)
	{
		result = pthread_create(&threads[i], NULL, routine, NULL);
		if (result != 0)
			die("Unable to create required thread.");
		printf(fmt, threads[i]);
		i++;
	}
}

void	join_threads(pthread_t threads[],
				int returns[],
				int thread_count,
				char *fmt)
{
	int	i;
	int	result;

	i = 0;
	while (i < thread_count)
	{
		result = pthread_join(threads[i], NULL);
		if (result != 0)
			die("Unable to join required thread.");
		printf(fmt, threads[i], returns[i]);
		i++;
	}
}

# define SPAWN_WORKER_FMT "Created worker thread with id %lu.\n"
void	spawn_workers(void)
{
	spawn_threads(workers, &run_worker, WORKER_THREAD_COUNT, SPAWN_WORKER_FMT);
}

# define JOIN_WORKER_FMT "Joined worker thread %lu with return status %d.\n"
void	join_workers(void)
{
	join_threads(workers, worker_returns, WORKER_THREAD_COUNT, JOIN_WORKER_FMT);
}

# define SPAWN_SCHEDULER_FMT "Created scheduler thread with id %lu.\n"
void	spawn_schedulers(void)
{
	spawn_threads(schedulers, &run_scheduler, SCHEDULER_THREAD_COUNT, SPAWN_SCHEDULER_FMT);
}

# define JOIN_SCHEDULER_FMT "Joined scheduler thread %lu with return status %d.\n"
void	join_schedulers(void)
{
	join_threads(schedulers, scheduler_returns, SCHEDULER_THREAD_COUNT, JOIN_SCHEDULER_FMT);
}

void	init(void)
{
	srand(time(NULL));
	pthread_mutex_init(&queue_mutex, NULL);
	pthread_cond_init(&queue_cond, NULL);
}

void	cleanup(void)
{
	pthread_mutex_destroy(&queue_mutex);
	pthread_cond_destroy(&queue_cond);
}

void	cancel_threads(pthread_t threads[], int thread_count, char *fmt)
{
	int	i;
	int	result;

	i = 0;
	while (i < thread_count)
	{
		result = pthread_cancel(threads[i]);
		if (result != 0)
			die("Unable to send required cancel signal to thread.");
		printf(fmt, threads[i]);
		i++;
	}
}

# define CANCEL_WORKER_FMT "Sending cancel signal to worker thread %lu.\n"
void	cancel_workers(void)
{
	cancel_threads(workers, WORKER_THREAD_COUNT, CANCEL_WORKER_FMT);
}

# define CANCEL_SCHEDULER_FMT "Sending cancel signal to scheduler thread %lu.\n"
void	cancel_schedulers(void)
{
	cancel_threads(schedulers, SCHEDULER_THREAD_COUNT, CANCEL_SCHEDULER_FMT);
}

int	main(int arc, char *argv[])
{
	init();
	spawn_workers();
	spawn_schedulers();

	sleep(RUNTIME_SECONDS);
	printf("Cancelling all threads.\n");
	cancel_schedulers();
	cancel_workers();

	join_schedulers();
	join_workers();
	cleanup();
	return (EXIT_SUCCESS);
}
