#include <unistd.h>
#include <stdio.h>

int is_space(char c)
{
	if (c == 32 || c == 9)
		return 1;
	return 0;
}

void epur_str(char *str)
{
	int i = 0;
	int flag = 0;
	while(str[i])
	{
		if (!is_space(str[i]))
		{
			write(1, &str[i], 1);
			i++;
		}
		if (flag == 1 && is_space(str[i]))
		{
			write(1, " ", 1);
			i++;
		}
		while (is_space(str[i]))
			i++;
		flag = 1;
	}
}


int main(int argc, char **argv)
{
	if (argc == 2)
	{

		epur_str(argv[1]);

	}
	write(1, "\n", 1);
	return 0;
}
