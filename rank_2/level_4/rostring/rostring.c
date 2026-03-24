#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_space(char c)
{
	if (c == 32 || c == 9)
		return 1;
	return 0;
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

void ft_putstr(char *str)
{
	int i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}


int start_word(char *str, int current_potition)
{
	int i = current_potition;

	while(str[i])
	{
		if (str[i] && !is_space(str[i]))
			return i;
		else if(str[i - 1] && is_space(str[i - 1]) && !is_space(str[i]))
			return i;
		i++;
	}
	return -1;
}

int end_word(char *str, int start)
{
	int i = start;

	while(str[i] && !is_space(str[i]))
	{
		i++;
	}
	return (i -1);
}


char *ft_strcpy(char *str, int start, int end)
{
	int len = end - start + 1;
	int i = 0;
	char *res = malloc(sizeof(char) * len + 1);

	if (!res)
		return (NULL);

	while(str[start] && !is_space(str[start]) && start <= end)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char **ft_split(char *str)
{
	int i = 0;
	char **matrix = malloc(sizeof(char *) * 100);
	int j = 0;
	int start;
	int end;

	if(!matrix)
		return NULL;

	while(str[i])
	{
		while(str[i] && is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
		{
			start = start_word(str, i);
			end = end_word(str, start);
			if (start == -1 || end == -1)
				break;
			matrix[j] = ft_strcpy(str, start, end);
			j++;
			i = end + 1;
		}
	}
	matrix[j] = NULL;
	return (matrix);
}

void print_matrix(char **matrix)
{
	int i = 0;
	while(matrix[i])
	{
		ft_putstr(matrix[i]);
		write(1, "\n", 1);
		i++;
	}
}

void rostring(char **matrix)
{
		int i = 0;
		int len = 0;
		while (matrix[len])
				len++;
		if (len > 1)
		{
				if (i == 0)
						i++;
				while(matrix[i])
				{
						ft_putstr(matrix[i]);
						write(1, " ", 1);
						i++;
				}
		}
		ft_putstr(matrix[0]);
}


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char **result = ft_split(argv[1]);
		print_matrix(result);
		rostring(result);
	}
	write(1, "\n", 1);
	return 0;
}
