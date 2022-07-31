// SOURCE: https://www.youtube.com/watch?v=_n2hE2gyPxU&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=29

// gcc thread_pool_scheduler.c && ./a.out

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define WORKER_THREAD_COUNT 8
#define SCHEDULER_THREAD_COUNT 6

#define SCHEDULER_DELAY_SECONDS 3

#define TASK_QUEUE_SIZE 256
#define TASK_DELAY_SECONDS 2

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

	ascii_time = malloc(TIME_BUFFER_SIZE);
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

static void	*run_worker_thread(void *_args)
{
	t_task	task;

	while (true)
	{
		pthread_mutex_lock(&mutex_queue);
		wait_for_task();
		task = dequeue_task();
		pthread_mutex_unlock(&mutex_queue);
		execute_task(&task);
	}
}

static void	*run_scheduler_thread(void *_args)
{
	t_task	task;

	while (true)
	{
		enqueue_task(new_task());
		sleep(SCHEDULER_DELAY_SECONDS);
	}
}

static void	spawn_threads(pthread_t threads[], t_thread_routine routine,
		int thread_count)
{
	int	i;
	int	result;

	i = 0;
	while (i < thread_count)
	{
		result = pthread_create(&threads[i], NULL, routine, NULL);
		if (result != 0)
			perr_n_die("Unable to create required thread.");
		i++;
	}
}

static void	join_threads(pthread_t threads[], int thread_count)
{
	int	i;
	int	result;

	i = 0;
	while (i < thread_count)
	{
		result = pthread_join(threads[i], NULL);
		if (result != 0)
			perr_n_die("Unable to join required thread.");
		i++;
	}
}

static void	spawn_worker_threads(pthread_t threads[])
{
	spawn_threads(threads, &run_worker_thread, WORKER_THREAD_COUNT);
}

static void	join_worker_threads(pthread_t threads[])
{
	join_threads(threads, WORKER_THREAD_COUNT);
}

static void	spawn_scheduler_threads(pthread_t threads[])
{
	spawn_threads(threads, &run_scheduler_thread, SCHEDULER_THREAD_COUNT);
}

static void	join_scheduler_threads(pthread_t threads[])
{
	join_threads(threads, SCHEDULER_THREAD_COUNT);
}

static void	init(void)
{
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
	pthread_t	worker_threads[WORKER_THREAD_COUNT];
	pthread_t	scheduler_threads[WORKER_THREAD_COUNT];

	init();
	spawn_worker_threads(worker_threads);
	spawn_scheduler_threads(scheduler_threads);
	join_scheduler_threads(worker_threads);
	join_worker_threads(worker_threads);
	cleanup();
	return (EXIT_SUCCESS);
}
