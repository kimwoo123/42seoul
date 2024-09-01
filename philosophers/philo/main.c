/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:44:05 by wooseoki          #+#    #+#             */
/*   Updated: 2023/06/10 18:41:30 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (is_valid_input(argc, argv) == FALSE)
	{
		printf("please input positive int less than 100000000\n");
		return (0);
	}
	if (set_var(&philo, &data, argv) == FAIL)
	{
		printf("variable setting fail\n");
		return (0);
	}
	control_thread(philo, data);
	clear_memory(philo);
}
