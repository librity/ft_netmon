/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:46:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/01 16:52:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <monitoring.h>

void	execute_task(t_task *task)
{
	int	result;

	sleep(TASK_DELAY_SECONDS);
	result = task->a + task->b;
	tdebug("%s: %d + %d = %d\n", task->time, task->a, task->b, result);
	free(task->time);
}

void	log_task_count(void)
{
	tdebug("task_count: %d\n", task_count);
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
		.time = get_readable_time(),
		.a = rand() % 100,
		.b = rand() % 100};
	return (new);
}
