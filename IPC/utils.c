/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:31:23 by wooseoki          #+#    #+#             */
/*   Updated: 2023/01/24 17:59:14 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *arg, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = parse_cmd(arg);
	if (!cmd)
		error_exit("command not found\n", arg, 127);
	path = search_path(cmd[0], envp);
	if (!path)
	{
		free_cmd(cmd);
		error_exit("command not found\n", arg, 127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_cmd(cmd);
		free(path);
		error_exit("exec fail\n", NULL, 1);
	}
}

char	**parse_cmd(char *str)
{
	char	**result;
	char	c;
	size_t	index;

	c = in_quote(str);
	if (c == '.')
	{
		result = (char **)malloc(sizeof(char *) * 2);
		result[0] = ft_strdup(str);
		result[1] = NULL;
		return (result);
	}
	else if (c)
	{
		result = ft_split(str, c);
		index = 0;
		while (result[0][index])
		{
			if (result[0][index] == ' ')
				result[0][index] = '\0';
			index++;
		}
		return (result);
	}
	return (ft_split(str, ' '));
}

char	in_quote(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\'')
			return ('\'');
		else if (str[index] == '\"')
			return ('\"');
		else if (str[index] == '.')
			return ('.');
		index++;
	}
	return ('\0');
}

char	*search_path(char *cmd, char **envp)
{
	int		index;
	char	**path_list;
	char	*temp;
	char	*path;

	path_list = find_path(envp);
	index = 0;
	while (path_list[index])
	{
		temp = ft_strjoin(path_list[index], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(path, X_OK))
		{
			free_path_list(path_list);
			return (path);
		}
		index++;
	}
	if (path_list)
		free_path_list(path_list);
	if (!access(cmd, X_OK))
		return (cmd);
	return (NULL);
}

char	**find_path(char **envp)
{
	int		index;

	index = 0;
	while (envp[index])
	{
		if (!ft_strncmp(envp[index], "PATH=", 5))
			return (ft_split(&envp[index][5], ':'));
		index++;
	}
	return (NULL);
}
