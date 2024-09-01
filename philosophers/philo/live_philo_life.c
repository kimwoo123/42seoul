/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:02:34 by wooseoki          #+#    #+#             */
/*   Updated: 2023/06/10 18:06:42 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	do_thinking(t_philo *philo)
{
	if (print_philo_state(philo, "is thinking") == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	fall_asleep(t_philo *philo)
{
	if (print_philo_state(philo, "is sleeping") == FAIL)
		return (FAIL);
	if (spend_time(philo->data->time_to_sleep) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

void	live_philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
	{
		if (do_thinking(philo) == FAIL)
			return ;
		if (spend_time(philo->data->time_to_eat * 0.8) == FAIL)
			return ;
	}
	while (TRUE)
	{
		if (eat_spaghetti(philo) == FAIL)
			break ;
		if (fall_asleep(philo) == FAIL)
			break ;
		if (do_thinking(philo) == FAIL)
			break ;
	}
}
