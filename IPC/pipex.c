/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:29:34 by wooseoki          #+#    #+#             */
/*   Updated: 2023/01/24 19:01:42 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		error_exit("argument error\n", NULL, 1);
	set_pipe(argv, envp);
	return (0);
}

void	set_pipe(char **argv, char **envp)
{
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error_exit("pipe error\n", NULL, 1);
	input_process(argv, pipe_fd, envp);
	output_process(argv, pipe_fd, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
}

void	input_process(char **argv, int *pipe_fd, char **envp)
{
	int		input_fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork error\n", NULL, 1);
	if (!pid)
	{
		close(pipe_fd[0]);
		input_fd = open(argv[1], O_RDONLY, 0644);
		if (input_fd == -1)
			error_exit("No such file or directory\n", argv[1], 1);
		if (dup2(input_fd, STDIN_FILENO) == -1 || \
				dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit("dup fail\n", NULL, 1);
		execute_cmd(argv[2], envp);
		close(pipe_fd[1]);
	}
}

void	output_process(char **argv, int *pipe_fd, char **envp)
{
	int		output_fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork error\n", NULL, 1);
	if (!pid)
	{
		close(pipe_fd[1]);
		output_fd = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (output_fd == -1)
			error_exit("No such file or directory\n", argv[4], 1);
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1 || \
				dup2(output_fd, STDOUT_FILENO) == -1)
			error_exit("dup2 fail\n", NULL, 1);
		execute_cmd(argv[3], envp);
		close(pipe_fd[0]);
	}
}
