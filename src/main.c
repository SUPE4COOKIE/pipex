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

#include "../includes/libft.h"
#include "../includes/main.h"

void	exit_error(t_pipex	*pipex)
{
	if (pipex)
		free_pipex(pipex);
	perror("pipex");
	exit(1);
}

void	open_files(t_pipex *pipex, char **av)
{
	pipex->files_fd[0] = open(av[1], O_RDONLY);
	pipex->files_fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->files_fd[0] == -1)
	{
		free(pipex->cmd[0]);
		perror(av[1]);
		pipex->cmd[0] = NULL;
	}
	if (pipex->files_fd[1] == -1)
	{
		free(pipex->cmd[1]);
		perror(av[4]);
		pipex->cmd[1] = NULL;
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	check_args(ac);
	init_null_pipex(&pipex);
	save_path(&pipex, env);
	save_cmds(&pipex, av);
	save_args(&pipex, av);
	open_files(&pipex, av);
	get_cmd_path(&pipex);
	pipex_parent(&pipex);
	if (pipex.files_fd[0] != -1)
		close(pipex.files_fd[0]);
	if (pipex.files_fd[1] != -1)
		close(pipex.files_fd[1]);
	free_pipex(&pipex);
	return (0);
}
