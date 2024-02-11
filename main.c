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

int main(void)
{
	int pid;

	pid = fork();
	waitpid(pid, NULL, 0);
	if (pid == 0)
	{
		printf("I am the child process\n");
	}
	else
	{
		printf("I am the parent process\n");
	}
}