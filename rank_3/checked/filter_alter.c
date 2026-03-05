/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_alter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:01:22 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/11/13 16:46:59 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, int size)
{
	int i = 0;

	while ((s1[i] && s2[i]) && i < size)
	{
		if (s1[i] != s2[i])
			return 1;
		i++;
	}
	return 0;
}

int	main(int ac, char **av)
{
	char buf[100000];
	if (ac != 2 || av[1] == NULL)
		return 1;
	int i = 0;
	ssize_t bytes_read = 1;
	int size = strlen(av[1]);
	while (bytes_read > 0)
	{
		bytes_read = read(0, &buf[i], 1);
		if (bytes_read < 0)
			return (1);
		i++;
	}
	buf[i] = '\0';
	i = 0;
	while(buf[i])
	{
		if (ft_strncmp(&buf[i], av[1], size))
		{
			write(1, &buf[i], 1);
			i++;
		}
		else
		{
			for (int j = 0; j < size; j++)
				write(1, "*", 1);
			i += size;
		}
	}
	return 0;
}
