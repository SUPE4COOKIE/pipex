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
#include <stdio.h>

char	**get_env(char **env)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
}

int main(int ac, char **av, char **env)
{
	t_pipex pipex;

	if (ac != 5)
		return (write(2, "Error\n", 6)), 0;
	pipex.infile = open(av[1], O_RDONLY);
	if (!pipex.infile)
		return (write(2, "Error\n", 6)), 0;
	pipex.outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!pipex.outfile)
		return (write(2, "Error\n", 6)), 0;
}