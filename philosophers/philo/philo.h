/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:36:06 by wooseoki          #+#    #+#             */
/*   Updated: 2023/05/24 15:14:17 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include "struct.h"

size_t	ft_strlen(const char *str);
char	*ft_itoa(t_time number);
void	control_thread(t_philo *philo, t_data data);
void	clear_memory(t_philo *philo);
void	live_philo_life(void *arg);
void	start_monitoring(t_philo *philo);
int		get_end_state(t_philo *philo);
int		spend_time(t_time need_time);
int		set_var(t_philo **philo, t_data *data, char **argv);
int		eat_spaghetti(t_philo *philo);
int		get_time(t_time *start_time);
int		set_lastmeal_info(t_philo *philo);
int		is_valid_input(int argc, char **argv);
int		print_philo_state(t_philo *philo, char *message);
#endif
