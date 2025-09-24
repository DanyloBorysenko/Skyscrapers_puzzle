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

int	check_unq_row(char **arr, int row_ind, int size)
{
	char unq_dgs[size];
	int	unq_dig_count;

	unq_dig_count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[row_ind][i] == '0')
			continue;
		for (int j = 0; j < unq_dig_count; j++)
		{
			if (arr[row_ind][i] == unq_dgs[j])
				return (0);

		}
		unq_dgs[unq_dig_count] = arr[row_ind][i];
		unq_dig_count++;
	}
	return (1);
}

int	check_unq_col(char **arr, int col_ind, int size)
{
	char unq_dgs[size];
	int	unq_dig_count;

	unq_dig_count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i][col_ind] == '0')
			continue;
		for (int j = 0; j < unq_dig_count; j++)
		{
			if (arr[i][col_ind] == unq_dgs[j])
				return (0);

		}
		unq_dgs[unq_dig_count] = arr[i][col_ind];
		unq_dig_count++;
	}
	return (1);
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

