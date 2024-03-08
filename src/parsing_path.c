/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:36:30 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/08 22:33:49 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/main.h"

static void	parse_path(t_pipex *pipex, char *env)
{
	char	*path;

	path = ft_strdup(env + 5);
	if (!path)
		exit_error(pipex);
	pipex->path = ft_split(path, ':');
	if (!pipex->path)
		exit_error(pipex);
	free(path);
}

void	save_path(t_pipex *pipex, char **env)
{
	size_t	i;

	i = 0;
	if (!env || !env[0])
		set_sysbin(pipex);
	else
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], "PATH=", 5) == 0)
			{
				if (env[i][5] == 0)
					set_sysbin(pipex);
				else
					parse_path(pipex, env[i]);
				return ;
			}
			i++;
		}
	}
	if (!pipex->path)
		set_sysbin(pipex);
}
