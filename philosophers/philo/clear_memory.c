/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:40:47 by wooseoki          #+#    #+#             */
/*   Updated: 2023/05/22 15:49:30 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutex(t_philo *philo)
{
	int		index;
	int		head_count;
	t_fork	*forks;

	index = 0;
	head_count = philo->data->number_of_philos;
	forks = philo->data->forks;
	while (index < head_count)
	{
		pthread_mutex_destroy(&(forks[index].key));
		index++;
	}
	pthread_mutex_destroy(&(philo->key));
	pthread_mutex_destroy(&(philo->data->key));
}

static void	free_memory(t_philo *philo)
{
	t_fork	*forks;

	forks = philo->data->forks;
	free(forks);
	free(philo);
}

void	clear_memory(t_philo *philo)
{
	destroy_mutex(philo);
	free_memory(philo);
}
