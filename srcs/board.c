#include "skyscrapers.h"

char **get_empt_brd(int	size)
{
	char **board;
	int	i;
	int	j;

	board = malloc(size * sizeof(char *));
	if (!board)
		return (NULL);
	i = 0;
	while (i < size)
	{
		board[i] = malloc((size + 1) * sizeof(char));
		if (!board[i])
			return (NULL);
		j = 0;
		while (j < size)
		{
			board[i][j] = '0';
			j++;
		}
		board[i][j] = '\0';
		i++;
	}
	return (board);
}

void print_brd(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, arr[i], size);
		write(1, "\n", 1);
		i++;
	}
}

void free_brd(char **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
