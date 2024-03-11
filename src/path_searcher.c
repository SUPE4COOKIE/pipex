/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_searcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:40:42 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/11 16:41:06 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/main.h"

static int	is_full_path(char *str)
{
	if (ft_strnstr(str, "/", ft_strlen(str)))
		if (access(str, F_OK) == 0 && access(str, X_OK) == 0)
			return (1);
	return (0);
}

static	void	cmd_no_path(t_pipex *pipex)
{
	char	*tmp;

	if (!pipex->path)
	{
		if (!is_full_path(pipex->cmd[0]))
		{
			tmp = ft_strjoin(pipex->cmd[0], ": command not found\n");
			if (!tmp)
				exit_error(pipex);
			write(2, tmp, ft_strlen(tmp));
			free(tmp);
			free(pipex->cmd[0]);
			pipex->cmd[0] = NULL;
		}
		if (!is_full_path(pipex->cmd[1]))
		{
			tmp = ft_strjoin(pipex->cmd[1], ": command not found\n");
			if (!tmp)
				exit_error(pipex);
			write(2, tmp, ft_strlen(tmp));
			free(tmp);
			free(pipex->cmd[1]);
			pipex->cmd[1] = NULL;
		}
	}
}

static	void	cmd_not_found(t_pipex *pipex)
{
	char	*tmp;

	if (pipex->cmd[0] && (access(pipex->cmd[0], F_OK) != 0 \
		|| access(pipex->cmd[0], X_OK) != 0))
	{
		tmp = ft_strjoin(pipex->cmd[0], ": command not found\n");
		if (!tmp)
			exit_error(pipex);
		write(2, tmp, ft_strlen(tmp));
		free(tmp);
		free(pipex->cmd[0]);
		pipex->cmd[0] = NULL;
	}
	if (pipex->cmd[1] && (access(pipex->cmd[1], F_OK) != 0 \
		|| access(pipex->cmd[1], X_OK) != 0))
	{
		tmp = ft_strjoin(pipex->cmd[1], ": command not found\n");
		if (!tmp)
			exit_error(pipex);
		write(2, tmp, ft_strlen(tmp));
		free(tmp);
		free(pipex->cmd[1]);
		pipex->cmd[1] = NULL;
	}
}

static	int	cmd_for_path(t_pipex *pipex, char *path, size_t j)
{
	char	*tmp;
	char	*ex_path;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		exit_error(pipex);
	ex_path = ft_strjoin(tmp, pipex->cmd[j]);
	if (!ex_path)
		exit_error(pipex);
	free(tmp);
	if (access(ex_path, F_OK) == 0 && access(ex_path, X_OK) == 0)
	{
		free(pipex->cmd[j]);
		pipex->cmd[j] = ex_path;
		return (1);
	}
	free(ex_path);
	return (0);
}

int	get_cmd_path(t_pipex *pipex)
{
	size_t	i;
	size_t	j;

	cmd_no_path(pipex);
	j = 0;
	while (j < 2)
	{
		i = 0;
		if (pipex->cmd[j] && !is_full_path(pipex->cmd[j]))
		{
			while (pipex->path[i])
			{
				if (cmd_for_path(pipex, pipex->path[i], j))
					break ;
				i++;
			}
		}
		j++;
	}
	cmd_not_found(pipex);
	return (1);
}
