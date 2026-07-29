#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>

int	parse_expr(char **s);
int	parse_term(char **s);
int	parse_factor(char **s);

void error_end()
{
	write(1, "Unexpected end of input\n", 24);
	exit (1);
}

void error_token(char c)
{
	write(1, "Unexcpected token '", 18);
	write(1, &c, 1);
	write(1, "\n", 2);
	exit(1);
}
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
int parse_number(char **s)
{
	int value;

	if (!**s)
		error_end();
	if (!is_digit(**s))
		error_token(**s);
	value = **s - '0';
	(*s)++;
	return (value);
}

int parse_factor(char **s)
{
	int value;

	if (!**s)
		error_end();
	if (**s == '(')
	{
		(*s)++;
		value = parse_expr(s);
		if (**s == '\0')
			error_end();
		if (**s != ')')
			error_token(**s);
		(*s)++;
		return (value);
	}
	return (parse_number(s));
}

int parse_term(char **s)
{
	int value;

	value = parse_factor(s);
	while (**s == '*')
	{
		(*s)++;
		value *= parse_factor(s);
	}
	return (value);
}

int parse_expr(char **s)
{
	int value;

	value = parse_term(s);
	while (**s == '+')
	{
		(*s)++;
		value += parse_term(s);
	}
	return (value);
}

int main(int argc, char **argv)
{
	char *s;
	if (argc != 2)
		return 1;
	s = argv[1];
	if (*s == '\0')
		error_end();
	printf("%d\n", parse_expr(&s));
	if (*s != '\0')
		error_token(*s);
	return 0;
}

