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
	// TODO: free all the mallocs
	ft_printf("Error\n");
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
	// add "" support
	pipex->args[0] = ft_split(av[2], ' ');
	pipex->args[1] = ft_split(av[3], ' ');
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_pipex	pipex;

	save_path(&pipex, env);
	save_cmds(&pipex, av);
	save_args(&pipex, av);
	pipex.infile = av[1];
	pipex.outfile = av[4];
	pipex.fd[0] = open(pipex.infile, O_RDONLY);
	pipex.fd[1] = open(pipex.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.fd[0] == -1 || pipex.fd[1] == -1)
		exit_error(pipex);
	return (0);
}