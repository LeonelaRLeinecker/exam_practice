#include "rip.h"

int is_balanced(char *s)
{
	int i = 0;
	int count = 0;
	while(s[i])
	{
		if (s[i] == '(')
			count++;
		else if (s[i] == ')')
		{
			count--;
			if (count < 0)
				return 0;
		}

		i++;
	}
	return (count == 0);
}



void search_and_count(char *s, int *left, int *right)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == '(')
			(*left)++;
		else if (s[i] == ')')
		{
			if (*left > 0)
				(*left)--;
			else
				(*right)++;
		}
		i++;
	}
}
void print(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	solve(char *s, int index, int left, int right)
{
	if (!s[index])
	{
		if (is_balanced(s))
			print(s);
		return;
	}

	if (s[index] == '(')
	{
		if (left > 0)
		{
			s[index] = ' ';
			solve(s, index + 1, left - 1, right);
			s[index] = '(';
		}
		solve(s, index + 1, left, right);
	}
	else if (s[index] == ')')
	{
		if (right > 0)
		{
			s[index] = ' ';
			solve(s, index + 1, left, right - 1);
			s[index] = ')';
		}
		solve(s, index + 1, left, right);
	}
	else 
		solve(s, index + 1, left, right);

}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		
		int left = 0;
		int right = 0;

		search_and_count(argv[1], &left, &right);
		solve(argv[1], 0, left, right);

	}
	write(1, "\n", 1);
	return 0;
}
