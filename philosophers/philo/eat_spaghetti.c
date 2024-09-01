/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_spaghetti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:49:48 by wooseoki          #+#    #+#             */
/*   Updated: 2023/05/22 16:25:10 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_fork_state(t_philo *philo, t_fork *fork)
{
	while (get_end_state(philo) == FALSE)
	{
		if (pthread_mutex_lock(&(fork->key)) != 0)
			return (FAIL);
		if (fork->state == DOWN)
		{
			if (pthread_mutex_unlock(&(fork->key)) != 0)
				return (FAIL);
			return (DOWN);
		}
		if (pthread_mutex_unlock(&(fork->key)) != 0)
			return (FAIL);
		usleep(70);
	}
	return (FAIL);
}

static int	set_fork_state(t_fork *fork, int state)
{
	if (pthread_mutex_lock(&(fork->key)) != 0)
		return (FAIL);
	fork->state = state;
	if (pthread_mutex_unlock(&(fork->key)) != 0)
		return (FAIL);
	return (SUCCESS);
}

static int	put_fork(t_philo *philo, int fork_index)
{
	t_fork	*fork;

	fork = &(philo->data->forks[fork_index]);
	if (set_fork_state(fork, DOWN) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	take_fork(t_philo *philo, int fork_index)
{
	t_fork	*fork;

	fork = &(philo->data->forks[fork_index]);
	if (get_fork_state(philo, fork) == FAIL)
		return (FAIL);
	if (set_fork_state(fork, UP) == FAIL)
		return (FAIL);
	if (print_philo_state(philo, "has taken a fork") == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	eat_spaghetti(t_philo *philo)
{
	if (take_fork(philo, philo->left_hand) == FAIL)
		return (FAIL);
	if (take_fork(philo, philo->right_hand) == FAIL)
		return (FAIL);
	if (print_philo_state(philo, "is eating") == FAIL)
		return (FAIL);
	if (set_lastmeal_info(philo) == FAIL)
		return (FAIL);
	if (spend_time(philo->data->time_to_eat) == FAIL)
		return (FAIL);
	if (put_fork(philo, philo->right_hand) == FAIL)
		return (FAIL);
	if (put_fork(philo, philo->left_hand) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
