/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:16:43 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/07 22:18:30 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_pipex
{
	pid_t	pid[2];
	int		pipe_fd[2];
	int		files_fd[2];
	char	**path;
	char	*cmd[2];
	char	**args[2];
}				t_pipex;
void			free_pipex(t_pipex *pipex);
char			**ft_split_args(char const *str, char sep);

#endif
