/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:03:41 by dlom              #+#    #+#             */
/*   Updated: 2023/09/02 22:15:55 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closepipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	child_one(int *fd, char *argv[], char *envp[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		perror("Error when opening fd in child_one");
	if (close(fd[0]) == -1)
		perror("Error when closing fd[0] for read in child_one");
	if (dup2(fd[0], STDOUT_FILENO) == -1)
		perror("Error with first dup2 in child_one");
	if (dup2(fd, STDIN_FILENO))
		perror("Error with second dup2 in child_one");
	execute(argv[2], envp);
	close(fd);
}

void	child_two(int *fd, char *argv[], char *envp[])
{

}

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
		child_one(fd, argv, envp);
	waitpid(pid1, 0, 0);
	pid2 = fork();
	if (pid2 == -1)
		perror("Error when forking pid2. :(");
	if (pid2 == 0)
		child_two(fd, argv, envp);
	waitpid(pid2, 0, 0);
	return(0);
}
