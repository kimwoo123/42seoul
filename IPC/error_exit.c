/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:34:41 by wooseoki          #+#    #+#             */
/*   Updated: 2023/01/22 17:27:15 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path_list(char **path_list)
{
	int	index;

	index = 0;
	while (path_list[index])
	{
		if (path_list[index])
			free(path_list[index]);
		index++;
	}
	free(path_list);
}

void	free_cmd(char **cmd)
{
	int	index;

	index = 0;
	while (cmd[index])
	{
		if (cmd[index])
			free(cmd[index]);
		index++;
	}
	free(cmd);
}

void	ft_putstr(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	write(2, str, index);
}

void	error_exit(char *message, char *file, int code)
{
	ft_putstr("pipex: ");
	if (file)
	{
		ft_putstr(file);
		ft_putstr(": ");
	}
	if (message)
		ft_putstr(message);
	exit(code);
}
