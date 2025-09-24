#include "skyscrapers.h"

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

int	check_row_left(char **arr, int row_ind, int size, char rule)
{
	char	max;
	int	count;
	char	vis_count;

	vis_count = '0';
	count = 0;
	max = '0';
	for (int i = 0; i < size; i++)
	{
		if (arr[row_ind][i] != '0')
			count++;
		if (arr[row_ind][i] > max)
		{
			max = arr[row_ind][i];
			vis_count++;
		}
	}
	if (count == size)
		return (vis_count == rule);
	return (vis_count <= rule);
}

int	check_row_right(char **arr, int row_ind, int size, char rule)
{
	char	max;
	int	count;
	char	vis_count;

	vis_count = '0';
	count = 0;
	max = '0';
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[row_ind][i] != '0')
			count++;
		if (arr[row_ind][i] > max)
		{
			max = arr[row_ind][i];
			vis_count++;
		}
	}
	if (count == size)
		return (vis_count == rule);
	return (1);
}

int	check_col_top(char **arr, int col_ind, int size, char rule)
{
	char	max;
	int	count;
	char	vis_count;

	vis_count = '0';
	count = 0;
	max = '0';
	for (int i = 0; i < size; i++)
	{
		if (arr[i][col_ind] != '0')
			count++;
		if (arr[i][col_ind] > max)
		{
			max = arr[i][col_ind];
			vis_count++;
		}
	}
	if (count == size)
		return (vis_count == rule);
	return (vis_count <= rule);
}

int	check_col_bottom(char **arr, int col_ind, int size, char rule)
{
	char	max;
	int	count;
	char	vis_count;

	vis_count = '0';
	count = 0;
	max = '0';
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i][col_ind] != '0')
			count++;
		if (arr[i][col_ind] > max)
		{
			max = arr[i][col_ind];
			vis_count++;
		}
	}
	if (count == size)
		return (vis_count == rule);
	return (1);
}

int	put_numb(char **tips, char **final_board, int size, int index)
{
	int	row_ind;
	int	col_ind;
	int	is_numb_fit;

	if (index == (size * size))
			return (1);
	for (int j = 1; j <= size; j++)
	{
		is_numb_fit = 0;
		row_ind = index / size;
		col_ind = index % size;
		final_board[row_ind][col_ind] = j + '0';
		is_numb_fit += check_unq_row(final_board, row_ind, size);
		is_numb_fit += check_unq_col(final_board, col_ind, size);
		if (is_numb_fit == 2)
		{
			is_numb_fit += check_row_left(final_board, row_ind, size, tips[2][row_ind]);
			is_numb_fit += check_row_right(final_board, row_ind, size, tips[3][row_ind]);
			is_numb_fit += check_col_top(final_board, col_ind, size, tips[0][col_ind]);
			is_numb_fit += check_col_bottom(final_board, col_ind, size, tips[1][col_ind]);
		}
		printf("\n");
		if (is_numb_fit == 6)
		{
			if (put_numb(tips, final_board, size, index + 1) == 1)
				return (1);
		}
		final_board[row_ind][col_ind] = '0';
	}
	return (0);
}

int	solve(char **tips, char **final_board, int size)
{
	int	res;

	res = 0;
	// use_tips(tips, final_board, size);
	res = put_numb(tips, final_board, size, 0);
	return (res);
	return (0);
}