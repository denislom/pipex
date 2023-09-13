/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:03:41 by dlom              #+#    #+#             */
/*   Updated: 2023/09/13 23:24:08 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
https://dev.to/herbievine/42-a-comprehensive-guide-to-pipex-5165

 pipe fork dup exec explained 
https://www.youtube.com/watch?v=pO1wuN3hJZ4

CodeVault: pipe | explained very well
https://www.youtube.com/watch?v=6xbLgZpOBi8

CodeVault: How to execute another program (*envp[] explained)
https://youtu.be/OVFEWSP7n8c?feature=shared
https://learn.microsoft.com/en-us/cpp/c-language/
arguments-to-main?view=msvc-170
http://www.crasseux.com/books/ctutorial/Environment-variables.html

*/

void	closepipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	child_one(int *fd, char *argv[], char *envp[])
{
	int	cfd;

	cfd = open(argv[1], O_RDONLY);
	if (cfd == -1)
		perror("Error when opening fd in child_one");
	if (close(fd[0]) == -1)
		perror("Error when closing fd[0] for read in child_one");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("Error with first dup2 in child_one");
	if (dup2(cfd, STDIN_FILENO))
		perror("Error with second dup2 in child_one");
	execute(argv[2], envp);
	close(cfd);
}

void	child_two(int *fd, char *argv[], char *envp[])
{
	int	cfd;

	cfd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (cfd == -1)
		perror("Error when opening fd in child_two.");
	if (close(fd[1]) == -1)
		perror("Error when closing fd[1] in child_two.");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("Erro with first dup2 in child_two.");
	if (dup2(cfd, STDOUT_FILENO) == -1)
		perror("Error with second dup2 in child_two.");
	execute(argv[3], envp);
	close(cfd);
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
	closepipe(fd);
	waitpid(pid2, 0, 0);
	return (0);
}
