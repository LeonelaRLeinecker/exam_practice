#include <unistd.h>

int is_space(char c)
{
	if (c == 32 || c == 9)
	{
		return 1;
	}
	return 0;
}

int is_letter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return 1;
	}
	return 0;
}

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return c;
}

char to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c -32;
	}
	return c;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		write(1, "\n", 1);
	int i = 1;
	while(i < argc)
	{
		int j = 0;
		char c;
		while(argv[i][j])
		{
			if (argv[i][j + 1] && is_space(argv[i][j + 1]) && is_letter(argv[i][j]))
			{
				c = to_upper(argv[i][j]);
				write(1, &c, 1);
			}
			else if (argv[i][j + 1] == '\0' && is_letter(argv[i][j]))
			{
				c = to_upper(argv[i][j]);
				write(1, &c, 1);
			}
			else
			{
				c = to_lower(argv[i][j]);
				write(1, &c, 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return 0;
}
