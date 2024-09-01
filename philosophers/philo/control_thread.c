/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:37:58 by wooseoki          #+#    #+#             */
/*   Updated: 2023/05/22 15:55:47 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	control_thread(t_philo *philo, t_data data)
{
	int	index;

	index = 0;
	while (index < data.number_of_philos)
	{
		if (pthread_create(&(philo[index].thread_id), NULL, \
			(void *)live_philo_life, &(philo[index])) != 0)
			return ;
		++index;
	}
	start_monitoring(philo);
	index = 0;
	while (index < data.number_of_philos)
	{
		pthread_join(philo[index].thread_id, NULL);
		++index;
	}
}
