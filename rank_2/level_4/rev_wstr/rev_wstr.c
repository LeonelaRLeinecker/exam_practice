#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int is_space(char c)
{
	if (c == 32 || c == 9)
		return 1;
	return 0;
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



int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}


int start_word(char *str, int current_potition)
{
	int i = current_potition;

	while(str[i])
	{
		if (str[i] && !is_space(str[i]))
			return i;
		else if (str[i - 1] && is_space(str[i - 1]) && !is_space(str[i]))
			return i;
		i++;
	}
	return -1;
}


int end_word(char *str, int start)
{
	int i = start;
	
	while(str[i])
	{
		if (str[i + 1] == '\0' || is_space(str[i + 1]))
			return i;
		i++;
	}
	return -1;
}

char *ft_strcpy(char *str, int start, int end)
{
	int len = end + start + 1;
	char *res = malloc(sizeof(char) * len);
	int j = 0;
	
	while(str[start] && !is_space(str[start]) && start <= end)
	{
		res[j] = str[start];
		start++;
		j++;
	}
	res[j] = '\0';
	return (res);
}


char **ft_split(char *str)
{
	char **matrix = malloc(sizeof(char *) * 100);
	int i = 0;
	int j = 0;
	int start;
	int end;

	while(str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
		{

			start = start_word(str, i);
			end = end_word(str, start);
			matrix[j] = ft_strcpy(str, start, end);
			i = end;
			j++;
		}
		i++;

	}
	matrix[j] = NULL;
	return (matrix);	

}


void print_array(char **matrix)
{
	int i = 0;
	while(matrix[i])
	{
		ft_putstr(matrix[i]);
		write(1, "\n", 1);
		i++;

	}
}


void rev_wstr(char **matrix)
{
	int i = 0;
	while(matrix[i])
		i++;
	i--;
	while(i >= 0)
	{
		ft_putstr(matrix[i]);
		write(1, " ", 1);
		i--;
	}
}


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char **result = ft_split(argv[1]);		
		rev_wstr(result);
	}
	write(1, "\n", 1);
	return 0;
}
