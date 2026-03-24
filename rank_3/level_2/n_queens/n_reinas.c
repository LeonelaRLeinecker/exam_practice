#include <unistd.h>
#include <stdlib.h>


int abs (int x)
{
	if (x < 0)
		return (-x);
	return x;
}


void print(int *board, int n)
{
	for (int i = 0; i < n; i++)
	{
		char c = board[i] + 48;
		write(1, &c, 1);
		if (i < n - 1)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}


int is_safe(int *board, int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		if (board[i] == row)
			return 0;
		if (abs(board[i] - row) == abs(i - col))
			return 0;
	}
	return 1;
}

void solve(int *board, int col, int n)
{
	if (col == n)
	{
		print(board, n);
		return;
	}
	for (int row = 0; row < n; row++)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, n);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n = atoi(argv[1]);
		int *board = malloc(sizeof(int) * n);
		if (!board)
			return 1;
		solve(board, 0, n);
		free(board);
	}
	return 0;
}
