/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:37:43 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/21 17:43:51 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/main.h"

int	in_cmd(t_pipex *pipex)
{
	if (dup2(pipex->files_fd[0], STDIN_FILENO) == -1)
		exit_error(pipex);
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
		exit_error(pipex);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (pipex->files_fd[0] != -1)
		close(pipex->files_fd[0]);
	if (pipex->files_fd[1] != -1)
		close(pipex->files_fd[1]);
	execve(pipex->cmd[0], pipex->args[0], NULL);
	perror("pipex");
	return (1);
}

int	out_cmd(t_pipex *pipex)
{
	if (dup2(pipex->files_fd[1], STDOUT_FILENO) == -1)
		exit_error(pipex);
	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
		exit_error(pipex);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (pipex->files_fd[0] != -1)
		close(pipex->files_fd[0]);
	if (pipex->files_fd[1] != -1)
		close(pipex->files_fd[1]);
	execve(pipex->cmd[1], pipex->args[1], NULL);
	perror("pipex");
	return (1);
}

int	pipex_parent(t_pipex *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
		exit_error(pipex);
	if (pipex->cmd[0])
	{
		pipex->pid[0] = fork();
		if (pipex->pid[0] == -1)
			exit_error(pipex);
		if (pipex->pid[0] == 0)
			in_cmd(pipex);
	}
	if (pipex->cmd[1])
	{
		pipex->pid[1] = fork();
		if (pipex->pid[1] == -1)
			exit_error(pipex);
		if (pipex->pid[1] == 0)
			out_cmd(pipex);
	}
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (pipex->cmd[0])
		waitpid(pipex->pid[0], NULL, 0);
	if (pipex->cmd[1])
		waitpid(pipex->pid[1], NULL, 0);
	return (1);
}
