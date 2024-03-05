/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:28:35 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/02/11 04:28:35 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	exit_error(t_pipex	pipex)
{
	(void)pipex;
	free_pipex(&pipex);
	write(2, "Error\n", 6);
	exit(1);
}

void	save_path(t_pipex *pipex, char **env)
{
	size_t	i;
	char	*path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(env[i] + 5);
			pipex->path = ft_split(path, ':');
			free(path);
			return ;
		}
		i++;
	}
	exit_error(*pipex);
}

void	save_cmds(t_pipex *pipex, char **av)
{
	size_t	i;

	i = 0;
	if (!av[2] || !av[3])
		exit_error(*pipex);
	pipex->cmd[0] = malloc(sizeof(char) * ft_strlen(av[2]) + 1);
	pipex->cmd[1] = malloc(sizeof(char) * ft_strlen(av[3]) + 1);
	while (av[2][i] && av[2][i] != ' ')
	{
		pipex->cmd[0][i] = av[2][i];
		i++;
	}
	pipex->cmd[0][i] = 0;
	i = 0;
	while (av[3][i] && av[3][i] != ' ')
	{
		pipex->cmd[1][i] = av[3][i];
		i++;
	}
	pipex->cmd[1][i] = 0;
}

void	save_args(t_pipex *pipex, char **av)
{
	pipex->args[0] = ft_split_args(av[2], ' ');
	pipex->args[1] = ft_split_args(av[3], ' ');
}

int	get_cmd_path(t_pipex *pipex)
{
	size_t	i;
	size_t	j;
	char	*ex_path;


	j = 0;
	while (j < 2)
	{
		i = 0;
		if (pipex->cmd[j])
		{
			while (pipex->path[i])
			{
				ex_path = ft_strjoin(pipex->path[i], "/");
				ex_path = ft_strjoin(ex_path, pipex->cmd[j]);
				if (access(ex_path, F_OK) == 0 && access(ex_path, X_OK) == 0)
				{
					free(pipex->cmd[j]);
					pipex->cmd[j] = ex_path;
					break ;
				}
				free(ex_path);
				i++;
			}
		}
		j++;
	}
	if (access(pipex->cmd[0], F_OK) != 0 || access(pipex->cmd[0], X_OK) != 0)
	{
		write(2, "Error1\n", 7);
		pipex->cmd[0] = NULL;
	}
	if (access(pipex->cmd[1], F_OK) != 0 || access(pipex->cmd[1], X_OK) != 0)
	{
		write(2, "Error2\n", 7);
		pipex->cmd[1] = NULL;
	}
	return (1);
}

int in_cmd(t_pipex *pipex)
{
	dup2(pipex->files_fd[0], STDIN_FILENO);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	close(pipex->files_fd[0]);
	close(pipex->files_fd[1]);
	execve(pipex->cmd[0], pipex->args[0], NULL);
	exit_error(*pipex);
	return 1;
}

int out_cmd(t_pipex *pipex)
{
	dup2(pipex->files_fd[1], STDOUT_FILENO);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	close(pipex->files_fd[0]);
	close(pipex->files_fd[1]);
	execve(pipex->cmd[1], pipex->args[1], NULL);
	exit_error(*pipex);
	return 1;
}

int	pipex_parent(t_pipex *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
		exit_error(*pipex);
	if (pipex->cmd[0])
	{
		pipex->pid[0] = fork();
		if (pipex->pid[0] == -1)
			exit_error(*pipex);
		if (pipex->pid[0] == 0)
			in_cmd(pipex);
	}
	if (pipex->cmd[1])
	{
		pipex->pid[1] = fork();
		if (pipex->pid[1] == -1)
			exit_error(*pipex);
		if (pipex->pid[1] == 0)
			out_cmd(pipex);
	}
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	waitpid(pipex->pid[0], NULL, 0);
	waitpid(pipex->pid[1], NULL, 0);
	return (1);
}

void check_args(int ac)
{
	if (ac != 5)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void free_pipex(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->path[i])
	{
		free(pipex->path[i]);
		i++;
	}
	free(pipex->path);
	i = 0;
	while (pipex->args[0][i])
	{
		free(pipex->args[0][i]);
		i++;
	}
	free(pipex->args[0]);
	i = 0;
	while (pipex->args[1][i])
	{
		free(pipex->args[1][i]);
		i++;
	}
	free(pipex->args[1]);
	free(pipex->cmd[0]);
	free(pipex->cmd[1]);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	t_pipex	pipex;

	check_args(ac);
	pipex.cmd[0] = NULL;
	pipex.cmd[1] = NULL;
	save_path(&pipex, env);
	save_cmds(&pipex, av);
	save_args(&pipex, av);
	pipex.files_fd[0] = open(av[1], O_RDONLY);
	pipex.files_fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.files_fd[0] == -1)
		pipex.cmd[0] = NULL;
	if (pipex.files_fd[1] == -1)
		pipex.cmd[1] = NULL;
	get_cmd_path(&pipex);
	pipex_parent(&pipex);
	close(pipex.files_fd[0]);
	close(pipex.files_fd[1]);
	free_pipex(&pipex);
	return (0);
}