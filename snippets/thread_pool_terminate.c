// SOURCE: https://www.youtube.com/watch?v=_n2hE2gyPxU&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=29

// gcc thread_pool_terminate.c && ./a.out

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define RUNTIME_SECONDS 20

#define WORKER_THREAD_COUNT 8
#define SCHEDULER_THREAD_COUNT 6

#define THREAD_EXIT_OK 0
#define THREAD_RUNNING 1
#define THREAD_ERR 2

#define SCHEDULER_DELAY_SECONDS 1

#define TASK_QUEUE_SIZE 256
#define TASK_DELAY_SECONDS 5

#define TIME_BUFFER_SIZE 26

typedef struct s_task
{
	char		*time;
	int			a;
	int			b;
}				t_task;

t_task			task_queue[256];
int				task_count = 0;

typedef void	*(*t_thread_routine)(void *);

pthread_t		workers[WORKER_THREAD_COUNT];
int				worker_returns[WORKER_THREAD_COUNT];

pthread_t		schedulers[SCHEDULER_THREAD_COUNT];
int				scheduler_returns[SCHEDULER_THREAD_COUNT];

bool			exit_threads = false;

pthread_mutex_t	mutex_queue;
pthread_cond_t	cond_queue;

static void	perr_n_die(char *message)
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
		perr_n_die("Unable to convert rawtime to calendar time.");

	ascii_time = malloc(ASCTIME_STRING_SIZE);
	result = asctime_r(&timeinfo, ascii_time);
	if (result == NULL)
	{
		free(ascii_time);
		perr_n_die("Unable to convert calendar time to a human-readable string.");
	}

	endline = strstr(ascii_time, "\n");
	if (endline != NULL)
		*endline = '\0';

	return (ascii_time);
}

static void	execute_task(t_task *task)
{
	int	result;

	sleep(TASK_DELAY_SECONDS);
	result = task->a + task->b;
	printf("%s: %d + %d = %d\n", task->time, task->a, task->b, result);
	free(task->time);
}

static void	log_task_count(void)
{
	printf("task_count: %d\n", task_count);
}

static void	increase_task_count(void)
{
	task_count++;
	log_task_count();
}

static void	decrease_task_count(void)
{
	task_count--;
	log_task_count();
}

static void	enqueue_task(t_task task)
{
	pthread_mutex_lock(&mutex_queue);
	task_queue[task_count] = task;
	increase_task_count();
	pthread_mutex_unlock(&mutex_queue);
	pthread_cond_signal(&cond_queue);
}

static void	wait_for_task(void)
{
	while (task_count == 0)
		pthread_cond_wait(&cond_queue, &mutex_queue);
}

static t_task	dequeue_task(void)
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

static t_task	new_task(void)
{
	t_task	new;

	new = (t_task){
		.time = get_tsafe_ascii_time(),
		.a = rand() % 100,
		.b = rand() % 100};
	return (new);
}

static int	*find_return_writer(pthread_t threads[],
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

static int	*find_worker_return_writer(void)
{
	return (find_return_writer(workers, worker_returns, WORKER_THREAD_COUNT));
}

static void	*init_worker(int **return_writer)
{
	*return_writer = find_worker_return_writer();
	if (*return_writer == NULL)
	{
		printf("Closing worker thread %lu: Unable to find return writer pointer.\n", pthread_self());
		pthread_exit(NULL);
	}
	**return_writer = THREAD_RUNNING;
}

static void	*exit_worker_cleanly(int *return_writer)
{
	printf("Exiting worker thread %lu: thread termination activated.\n", pthread_self());
	*return_writer = THREAD_EXIT_OK;
	pthread_exit(NULL);
}

static void	*run_worker(void *_args)
{
	int 	*return_writer;
	t_task	task;

	init_worker(&return_writer);
	while (true)
	{
		if (exit_threads)
			exit_worker_cleanly(return_writer);
		pthread_mutex_lock(&mutex_queue);
		wait_for_task();
		task = dequeue_task();
		pthread_mutex_unlock(&mutex_queue);
		execute_task(&task);
	}
}

static int	*find_scheduler_return_writer(void)
{
	return (find_return_writer(schedulers, scheduler_returns, SCHEDULER_THREAD_COUNT));
}

static void	*init_scheduler(int **return_writer)
{
	*return_writer = find_scheduler_return_writer();
	if (*return_writer == NULL)
	{
		printf("Closing scheduler thread %lu: Unable to find return writer pointer.\n", pthread_self());
		return ;
	}
	**return_writer = THREAD_RUNNING;
}

static void	*exit_scheduler_cleanly(int *return_writer)
{
	printf("Exiting scheduler thread %lu: thread termination activated.\n", pthread_self());
	*return_writer = THREAD_EXIT_OK;
	pthread_exit(NULL);
}

static void	*run_scheduler(void *_args)
{
	int 	*return_writer;

	init_scheduler(&return_writer);
	while (true)
	{
		if (exit_threads)
			exit_scheduler_cleanly(return_writer);
		enqueue_task(new_task());
		sleep(SCHEDULER_DELAY_SECONDS);
	}
}

static void	spawn_threads(pthread_t threads[],
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
			perr_n_die("Unable to create required thread.");
		printf(fmt, threads[i]);
		i++;
	}
}

static void	join_threads(pthread_t threads[],
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
			perr_n_die("Unable to join required thread.");
		printf(fmt, threads[i], returns[i]);
		i++;
	}
}

# define SPAWN_WORKER_FMT "Created worker thread with id %lu.\n"
static void	spawn_workers(void)
{
	spawn_threads(workers, &run_worker, WORKER_THREAD_COUNT, SPAWN_WORKER_FMT);
}

# define JOIN_WORKER_FMT "Joined worker thread %lu with return status %d.\n"
static void	join_workers(void)
{
	join_threads(workers, worker_returns, WORKER_THREAD_COUNT, JOIN_WORKER_FMT);
}

# define SPAWN_SCHEDULER_FMT "Created scheduler thread with id %lu.\n"
static void	spawn_schedulers(void)
{
	spawn_threads(schedulers, &run_scheduler, SCHEDULER_THREAD_COUNT, SPAWN_SCHEDULER_FMT);
}

# define JOIN_SCHEDULER_FMT "Joined scheduler thread %lu with return status %d.\n"
static void	join_schedulers(void)
{
	join_threads(schedulers, scheduler_returns, SCHEDULER_THREAD_COUNT, JOIN_SCHEDULER_FMT);
}

static void	init(void)
{
	srand(time(NULL));
	pthread_mutex_init(&mutex_queue, NULL);
	pthread_cond_init(&cond_queue, NULL);
}

static void	cleanup(void)
{
	pthread_mutex_destroy(&mutex_queue);
	pthread_cond_destroy(&cond_queue);
}

int	main(int arc, char *argv[])
{
	init();
	spawn_workers();
	spawn_schedulers();

	sleep(RUNTIME_SECONDS);
	exit_threads = true;

	join_schedulers();
	join_workers();
	cleanup();
	return (EXIT_SUCCESS);
}
