/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_luis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <lleineck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:24 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/03/05 17:17:54 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ft_strncmp(char* s1, char* s2, int size)
{
	int i = 0;
	while(i < size && (s1[i] && s2[i]))
	{
		if (s1[i]!=s2[i])
			return(1);
		i ++;
	}
	return(0);
}



int main(int argc, char **argv)
{
	if (argc!=2 || argv[1] == NULL)
		return(1);
	char buf[100000000001];

	int i=0;
	int size = strlen(argv[1]);
	int bytes_read = read(0, buf, 1000);
	if (bytes_read < 0)
		return(perror("read fail"), 1);
	buf[bytes_read]= '\0';
	while(buf[i])
	{
		if (ft_strncmp(&buf[i], argv[1], size))
		{
			write(1, &buf[i], 1);
			i++;
		}
		else
		{
			for (int j=0; j<size; j++)
				write(1, "*", 1);
			i += size;
		}
	}
	return(0);
}
