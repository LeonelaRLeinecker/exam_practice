#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

int	picoshell(char **cmds[])
{
	int	fd[2];
	pid_t	pid;
	int	prev_fd;
	int	i;

	i = 0;
	prev_fd = -1;
	if (!cmds|| !*cmds)
		return 1;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) < 0)
		{
		//	if (prev_fd != -1)
		//		close(prev_fd);
			return (1);
		}
		pid = fork();
		if (pid == -1)
		{
		//	if (prev_fd != -1)
		//		close(prev_fd);
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			return 1;
		}
		if (pid == 0)
		{
			//if (i == 0)
			//	dup2(fd[1], STDOUT_FILENO);
			if (prev_fd != -1)
			{
				//dup2(prev_fd, STDIN_FILENO) == -1;
				if (dup2(prev_fd, STDIN_FILENO) == -1)
					exit(1);
				close(prev_fd);
			}
			if (cmds[i + 1])
			{
				//dup2(fd[1], STDOUT_FILENO);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[0]);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
/*		if (pid > 0)
		{
			if (prev_fd != -1)
				close(prev_fd);
			if (cmds[i + 1])
			{
				prev_fd = fd[0];
				close(fd[1]);

			}
			else
			{
				prev_fd = -1;
			}
		}*/
		if  (prev_fd != -1)
			close(prev_fd);
		if (cmds[i + 1])
		{
			close(fd[1]);
			prev_fd = fd[0];
		}
		else
			prev_fd = -1;
		i++;
	}
	int status;
	int exit_code = 0;
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit_code = 1;
		else if (!WIFEXITED(status))
			exit_code = 1;

	}
/*	if (prev_fd != 1)
	{
		close(prev_fd);
	}*/
	return (exit_code);

}


