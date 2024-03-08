/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:36:30 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/08 18:10:46 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/main.h"

void	save_path(t_pipex *pipex, char **env)
{
	size_t	i;
	char	*path;

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
				{
					path = ft_strdup(env[i] + 5);
					if (!path)
						exit_error(pipex);
					pipex->path = ft_split(path, ':');
					if (!pipex->path)
						exit_error(pipex);
					free(path);
				}
				return ;
			}
			i++;
		}
	}
	if (!pipex->path)
		set_sysbin(pipex);
}