/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:21:47 by wooseoki          #+#    #+#             */
/*   Updated: 2023/01/24 19:05:03 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

void	free_cmd(char **cmd);
void	free_path_list(char **path_list);
void	set_pipe(char **argv, char **envp);
void	error_exit(char *message, char *file, int code);
void	execute_cmd(char *arg, char **envp);
void	input_process(char **argv, int *pipe_fd, char **envp);
void	output_process(char **argv, int *pipe_fd, char **envp);
char	in_quote(char *str);
char	*search_path(char *cmd, char **envp);
char	**find_path(char **envp);
char	**parse_cmd(char *str);
int		main(int argc, char **argv, char **envp);
#endif
