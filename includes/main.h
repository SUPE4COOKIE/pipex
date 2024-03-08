/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:16:43 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/08 18:10:02 by mwojtasi         ###   ########.fr       */
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
void	free_pipex(t_pipex *pipex);
char	**ft_split_args(char const *str, char sep);
void	exit_error(t_pipex	*pipex);
void	check_args(int ac);
void	save_args(t_pipex *pipex, char **av);
void	save_cmds(t_pipex *pipex, char **av);
int		in_cmd(t_pipex *pipex);
int		out_cmd(t_pipex *pipex);
int		pipex_parent(t_pipex *pipex);
void	save_path(t_pipex *pipex, char **env);
int		get_cmd_path(t_pipex *pipex);
void	init_null_pipex(t_pipex *pipex);
void	set_sysbin(t_pipex *pipex);
#endif
