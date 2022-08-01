// SOURCE: https://www.youtube.com/watch?v=_n2hE2gyPxU&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=29

// gcc thread_pool.c && ./a.out

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define THREAD_COUNT 4

#define TASK_QUEUE_SIZE 256
#define TASK_COUNT 100

#define TASK_DELAY_SECONDS 1

typedef void	(*t_task_routine)(int , int);

typedef struct s_task
{
	t_task_routine	routine;
	int arg1;
	int arg2;
}				t_task;

t_task			task_queue[256];
int				task_count = 0;

pthread_mutex_t	mutex_queue;
pthread_cond_t	cond_queue;

static void	perr_n_die(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

static void	execute_task(t_task *task)
{
	int	result;

	task->routine(task->arg1, task->arg2);
}

static void	enqueue_task(t_task task)
{
	pthread_mutex_lock(&mutex_queue);
	task_queue[task_count] = task;
	task_count++;
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
	task_count--;
	return (task);
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

static void	spawn_worker_threads(pthread_t threads[])
{
	int	i;
	int	result;

	i = 0;
	while (i < THREAD_COUNT)
	{
		result = pthread_create(&threads[i], NULL, &run_worker_thread, NULL);
		if (result != 0)
			perr_n_die("Unable to create required worker thread.");
		i++;
	}
}

static void	sum(int	a, int b)
{
	int	__sum;

	sleep(TASK_DELAY_SECONDS);
	__sum = a + b;
	printf("%d + %d = %d\n===\n", a, b, __sum);
}

static void	product(int	a, int b)
{
	int	__product;

	sleep(TASK_DELAY_SECONDS);
	__product = a * b;
	printf("%d * %d = %d\n===\n", a, b, __product);
}

static void	enqueue_tasks(void)
{
	int	a;
	int	b;
	int	i;

	i = 0;
	while (i < TASK_COUNT)
	{
		enqueue_task(
			(t_task){
				.routine = (i % 2 == 0) ? &sum : &product,
				.arg1 = rand() % 100,
				.arg2 = rand() % 100
			});
		i++;
	}
}

static void	join_worker_threads(pthread_t threads[])
{
	int	i;
	int	result;

	i = 0;
	while (i < THREAD_COUNT)
	{
		result = pthread_join(threads[i], NULL);
		if (result != 0)
			perr_n_die("Unable to join required worker thread.");
		i++;
	}
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
	pthread_t	threads[THREAD_COUNT];

	init();
	spawn_worker_threads(threads);
	enqueue_tasks();
	join_worker_threads(threads);
	cleanup();
	return (EXIT_SUCCESS);
}
