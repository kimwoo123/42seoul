/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:28:32 by wooseoki          #+#    #+#             */
/*   Updated: 2023/06/10 17:52:44 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define INVALID 0
# define FALSE 0
# define TRUE 1
# define DOWN 0
# define UP 1
# define FAIL -1
# define SUCCESS 1
# define INT_LIMIT 100000000

typedef unsigned long long	t_time;

typedef struct s_fork
{
	int				state;
	pthread_mutex_t	key;
}	t_fork;

typedef struct s_data
{
	pthread_mutex_t		key;
	int					minimum_meal_count;
	int					number_of_philos;
	int					is_end;
	t_time				time_to_sleep;
	t_time				time_to_die;
	t_time				time_to_eat;
	t_time				start_time;
	t_fork				*forks;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	key;
	pthread_t		thread_id;
	t_time			last_meal;
	int				meal_count;
	int				id;
	int				left_hand;
	int				right_hand;
	t_data			*data;
}	t_philo;
#endif
