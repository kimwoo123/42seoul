/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:36:09 by wooseoki          #+#    #+#             */
/*   Updated: 2023/05/24 15:11:01 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	spend_time(t_time need_time)
{
	t_time	now;
	t_time	start;

	if (get_time(&start) == -1)
		return (FAIL);
	while (1)
	{
		if (get_time(&now) == -1)
			return (FAIL);
		if ((now - start) >= need_time)
			break ;
		usleep(100);
	}
	return (SUCCESS);
}

int	get_time(t_time *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (FAIL);
	*time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (SUCCESS);
}

int	get_end_state(t_philo *philo)
{
	int	ret;

	if (pthread_mutex_lock(&(philo->data->key)) != 0)
		return (FAIL);
	ret = philo->data->is_end;
	if (pthread_mutex_unlock(&(philo->data->key)) != 0)
		return (FAIL);
	return (ret);
}

int	set_lastmeal_info(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->key)) != 0)
		return (FAIL);
	if (get_time(&(philo->last_meal)) == FAIL)
		return (FAIL);
	philo->meal_count++;
	if (pthread_mutex_unlock(&(philo->key)) != 0)
		return (FAIL);
	return (SUCCESS);
}
