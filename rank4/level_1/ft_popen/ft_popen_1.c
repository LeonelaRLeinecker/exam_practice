#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int	ft_popen_1(const char *file, char *const argv[], char type)
{
	int		fd[2];
	pid_t	pid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
			{
				close(fd[0]);
				close(fd[1]);
				exit(1);
			}
		}
		else
		{
			if (dup2(fd[0], STDIN_FILENO) == -1)
			{
				close(fd[0]);
				close(fd[1]);
				exit(1);
			}
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(1);
	}
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	close(fd[0]);
	return (fd[1]);
}

int main()
{
	int fd;
	char buf[1024];
	ssize_t n;
	fd = ft_popen_1("ls", (char *const []){"ls", NULL}, 'r');
	if (fd == -1)
		return (1);
	while ((n = read(fd, buf, sizeof(buf))) > 0)
		write(1, buf, n);
	close (fd);
	return 0;
}
