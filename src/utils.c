/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:44:29 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/08 20:39:44 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/main.h"

void	init_null_pipex(t_pipex *pipex)
{
	pipex->path = NULL;
	pipex->args[0] = NULL;
	pipex->args[1] = NULL;
	pipex->cmd[0] = NULL;
	pipex->cmd[1] = NULL;
	pipex->pipe_fd[0] = 0;
	pipex->pipe_fd[1] = 0;
	pipex->files_fd[0] = 0;
	pipex->files_fd[1] = 0;
	pipex->pid[0] = -2;
	pipex->pid[1] = -2;
}

static	void	free_pipex_elem(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->path && pipex->path[i])
	{
		free(pipex->path[i]);
		i++;
	}
	if (pipex->path)
		free(pipex->path);
	i = 0;
	while (pipex->args[0] && pipex->args[0][i])
	{
		free(pipex->args[0][i]);
		i++;
	}
	if (pipex->args[0])
		free(pipex->args[0]);
	i = 0;
	while (pipex->args[1] && pipex->args[1][i])
	{
		free(pipex->args[1][i]);
		i++;
	}
}

void	free_pipex(t_pipex *pipex)
{
	free_pipex_elem(pipex);
	if (pipex->args[1])
		free(pipex->args[1]);
	if (pipex->cmd[0])
		free(pipex->cmd[0]);
	if (pipex->cmd[1])
		free(pipex->cmd[1]);
}

void	set_sysbin(t_pipex *pipex)
{
	pipex->path = malloc(sizeof(char *) * 2);
	if (!pipex->path)
		exit_error(pipex);
	pipex->path[0] = ft_strdup("/bin");
	if (!pipex->path[0])
		exit_error(pipex);
	pipex->path[1] = NULL;
}
