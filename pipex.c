/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:03:41 by dlom              #+#    #+#             */
/*   Updated: 2023/09/02 18:15:58 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		perror("Wrong input: number of arguments is not 5. :()");
	if (pipe(fd) == -1)
		perror("Error on opening the pipe. :(.");
	pid1 = fork();
	if (pid1 == -1)
		perror("Error when forking pid1. :(");
	if (pid1 == 0)
		somefunctionTOBEDONE();
	waitpid(pid1, 0, 0);
	pid2 = fork();
	if (pid2 == -1)
		perror("Error when forking pid2. :(");
	if (pid2 == 0)
		somefunctionTOBEDONE();
	waitpid(pid2, 0, 0);
	return(0);
}
