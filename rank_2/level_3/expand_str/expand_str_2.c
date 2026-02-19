#include <unistd.h>

int is_space(char c)
{
	if (c == 32 || c == 9)
		return 1;
	return 0;
}

void expand_str(char *str)
{
	int i = 0;
	int first_word = 1;

	while(str[i])
	{
		while(str[i] && is_space(str[i]))
			i++;
		if (!first_word)
		{
			write(1, "   ", 3);
		}
		if (str[i])
		{
			while(str[i] && !is_space(str[i]))
			{
				write(1, &str[i], 1);
				i++;
			}
			while (is_space(str[i]))
				i++;
			first_word = 0;
		}
	}
}


int main(int argc, char *argv)
{
	if (argc == 2)
	{
		expand_str(argv[1]);
	}
	write(1, "\n", 1);
	return 0;
}
