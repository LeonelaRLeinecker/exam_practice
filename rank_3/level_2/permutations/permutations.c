#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp; 
}

void sort(char *str)
{
	int i = 0;
	while (str[i])
	{
		int j = i + 1;
		while(str[j])
		{
			if (str[i] > str[j])
				swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void permute(char *str, char *result, int *used, int pos, int size)
{
	int i = 0;
	if (pos == size)
	{
		result[size] = '\0';
		puts(result);
		return ;
	}

	while( i < size)
	{
		if (!used[i])
		{
			used[i] = 1;
			result[pos] = str[i];
			permute(str, result, used, pos + 1, size);
			used[i] = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int size = 0;
	while(argv[1][size])
		size++;
	sort(argv[1]);
	char *result = calloc(size + 1, sizeof(char));
	int *used = calloc(size, sizeof(int));
	permute(argv[1], result, used, 0, size);
	free(result);
	free(used);
	return 0;
}
