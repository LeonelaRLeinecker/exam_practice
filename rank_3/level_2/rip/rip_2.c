#include <stdio.h>

int invalid(char *s)
{
	int i = 0;
	int open = 0;
	int close = 0;

	while(s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}

void result(char *s, int remove, int del, int pos)
{
	if (del > remove)
		return;

	if (remove == del)
	{
		if (!invalid(s))
			puts(s);
		return;
	}
	/*while(s[pos])
	{
		if (s[pos] == '(' || s[pos] == ')')
		{
			char c = s[pos];
			s[pos] = ' ';
			result(s, remove, del + 1, pos + 1);
			s[pos] = c;
		}
		pos++;
	}*/
	for (int i = pos; s[i]; i++)
	{
		if (s[i] != '(' && s[i] != ')')
			continue;
		if (s[i] != pos && s[i] == s[i-1])
			continue;
		char c = s[i];
		s[i] = ' ';
		result(s, remove, del + 1, i + 1);
		s[i] = c;
	}	
}

int main(int argc, char **argv)
{
	if (argc == 2)
		result(argv[1], invalid(argv[1]), 0, 0);
	return (argc != 2);
}

