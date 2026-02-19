#include <unistd.h>

int is_space(char c)
{
	if (c == 32 || c == '\t')
		return 1;
	return 0;
}

int is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return c;
}

char to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return c;
}

int main(int argc, char **argv)
{
	int i;
	int j;
	if (argc < 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		char c;
		while (i < argc)
		{
			j = 0;
			/*if (is_letter(argv[i][j]))
			{
				c = to_upper(argv[i][j]);
				write(1, &c, 1);
				i++;
			}*/
			while(argv[i][j])
			{
				if (j == 0 && is_letter(argv[i][j]))
				{
					c = to_upper(argv[i][j]);
					write(1, &c, 1);
				}
				else if (argv[i][j - 1] && (argv[i][j- 1] == 32 || argv[i][j - 1] == 9 )  && is_letter(argv[i][j]))
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
	}
	return 0;

}
