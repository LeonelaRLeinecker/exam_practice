/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <lleineck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:28:32 by lleineck          #+#    #+#             */
/*   Updated: 2026/03/13 19:54:52 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_subset(int *subset, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i)
			printf(" ");
		printf("%d", subset[i]);
	}
	printf("\n");
}

void	solve(int *set, int n, int target, int index, int *subset, int size, int sum)
{
	if (index == n)
	{
		if (sum == target)
			print_subset(subset, size);
		return;
	}
	solve(set, n, target, index + 1, subset, size, sum);
	subset[size] = set[index];
	solve(set, n, target, index + 1, subset, size + 1, sum + set[index]);
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return 0;
	int target = atoi(argv[1]);
	int n = argc - 2;
	int *set = malloc(sizeof(int) * n);
	int *subset = malloc(sizeof(int) * n);
	if (!set || !subset)
		return 1;
	for (int i = 0; i < n; i++)
		set[i] = atoi(argv[i + 2]);
	solve(set, n, target, 0, subset, 0, 0);
	free(set);
	free(subset);
}
