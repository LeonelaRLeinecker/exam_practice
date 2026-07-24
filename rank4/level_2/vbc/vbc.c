#include "VCB_H"

int is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return 1;
	return 0;
}

int	ft_atoi(char *argv)
{
	int i = 0;
	int res = 0;
	
	if (is_space(argv[i]))
		i++;
	while (argv[i])
	{ 
		res =  res * 10 + (argv[i] - 48);
		i++;
	}
	return (res);
}

int sum(char c, int next, int res)
{
	if (c == '+')
		res += next;
	return (res);
}

int multi(char c, int next, int res)
{
	if (c == *)
		res *= next;
	return (res);
}

int last_close_parenthesis(char *str)
{
	int i = 0;

	while(str[i])
	{
		if (str[i] == ')')
			return (i);
		i++;
	}
	return (-1);
}

int last_open_parenthesis(char *str)
{
	int i = 0;
	int pos = 0;

	while (str[i])
	{
		if (str[i] == '(')
			pos = i;
		i++;
	}
	return (pos);
}
//mi idea es tener la posicion del ultimo parentesis abierto y el primero cerrado para priorizar esa ejecucion. 

