#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int	ft_strncmp(char *s1, char *s2, int size)
{
	int i = 0;

	while((s1[i] && s2[i]) && i < size)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (i < size)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	char buf[1000];
	if (argc != 2 || argv[1][0] == '\0')
	      return 1;
	int i = 0;
	ssize_t bytes_read;
	int size = strlen(argv[1]);
	while ((bytes_read = read(0, &buf[i], 1)) > 0)
	{
		i++;
	}
	if (bytes_read < 0)
			return (1);
	buf[i] = '\0';
	i = 0;
	while (buf[i])
	{
		if (ft_strncmp(&buf[i], argv[1], size))
		{
			write(1, &buf[i], 1);
			i++;
		}
		else
		{
			for (int j = 0; j < size; j++)
				write(1, "*", 1);
			i +=size;
		}
	}
	return 0;
}
