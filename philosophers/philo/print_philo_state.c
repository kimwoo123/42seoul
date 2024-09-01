/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:59:25 by wooseoki          #+#    #+#             */
/*   Updated: 2023/06/10 17:34:27 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_str(char *result, char *timestamp, \
		char *philo_id, char *message)
{
	size_t	r_index;
	size_t	s_index;

	r_index = 0;
	s_index = 0;
	while (timestamp[s_index])
		result[r_index++] = timestamp[s_index++];
	result[r_index++] = ' ';
	s_index = 0;
	while (philo_id[s_index])
		result[r_index++] = philo_id[s_index++];
	result[r_index++] = ' ';
	s_index = 0;
	while (message[s_index])
		result[r_index++] = message[s_index++];
	result[r_index] = '\n';
}

static size_t	sum_len(char *a, char *b, char *c)
{
	return (ft_strlen(a) + ft_strlen(b) + ft_strlen(c) + 3);
}

static void	print_state(t_philo *philo, char *message, size_t str_size)
{
	if (get_end_state(philo) == FALSE)
	{
		if (pthread_mutex_lock(&(philo->data->key)) != 0)
			return ;
		if (philo->data->is_end == FALSE)
			write(1, message, str_size);
		if (pthread_mutex_unlock(&(philo->data->key)) != 0)
			return ;
	}
}

static int	make_format(t_philo *philo, unsigned long diff, char *state)
{
	char	*timestamp;
	char	*philo_id;
	char	*result;
	size_t	total_len;

	timestamp = ft_itoa(diff);
	philo_id = ft_itoa(philo->id + 1);
	total_len = sum_len(timestamp, philo_id, state);
	result = (char *)malloc(total_len);
	if (result == NULL || timestamp == NULL || philo_id == NULL)
	{
		free(timestamp);
		free(philo_id);
		free(result);
		return (FAIL);
	}
	join_str(result, timestamp, philo_id, state);
	print_state(philo, result, total_len);
	free(timestamp);
	free(philo_id);
	free(result);
	return (SUCCESS);
}

int	print_philo_state(t_philo *philo, char *message)
{
	t_time	now;
	t_time	diff;

	if (get_time(&now) == FAIL)
		return (FAIL);
	diff = now - philo->data->start_time;
	if (make_format(philo, diff, message) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
