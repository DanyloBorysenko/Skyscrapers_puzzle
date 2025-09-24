#include "skyscrapers.h"

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

int	upd_nmb(char *ptr, char new_nmb)
{
	if (*ptr == '0' || *ptr == new_nmb)
	{
		*ptr = new_nmb;
		return (0);
	}
	return (1);
}

int	put_max_numb(int tip_ind, int j, char **final_brd, int size)
{
	char numb;
	char *ptr;

	numb = size + '0';
	if (tip_ind == 0 || tip_ind == 1)
	{
		if (tip_ind == 0)
		{
			ptr = &final_brd[0][j];
		} else {
			ptr = &final_brd[size - 1][j];
		}
	} else {
		if (tip_ind == 2)
		{
			ptr = &final_brd[j][0];
		} else {
			ptr = &final_brd[j][size - 1];
		}
	}
	return upd_nmb(ptr, numb);
}

int	put_all_numb(int tip_ind, int j, char **final_brd, int size)
{
	int	iss_count;

	iss_count = 0;
	if (tip_ind == 0 || tip_ind == 1)
	{
		if (tip_ind == 0)
		{
			for (int i = 0; i < size; i++)
			{
				iss_count += upd_nmb(&final_brd[i][j], (i + 1) + '0');
			}
		} else {
			for (int i = size - 1; i >= 0; i--)
			{
				iss_count += upd_nmb(&final_brd[i][j], (size - i) + '0');
			}
		}
	} else {

		if (tip_ind == 2)
		{
			for (int i = 0; i < size; i++)
			{
				iss_count += upd_nmb(&final_brd[j][i], (i + 1) + '0');
			}
		} else {
			for (int i = size - 1; i >= 0; i--)
			{
				iss_count += upd_nmb(&final_brd[j][i], (size - i) + '0');
			}
		}
	}
	return (iss_count);
}

int	use_rules(char **tips, int size)
{
	char **empt_brd;
	int	iss_count;

	iss_count = 0;
	empt_brd = get_empt_brd(size);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (tips[i][j] == '1')
			{
				iss_count += put_max_numb(i, j, empt_brd, size);
			}
			if (tips[i][j] == size + '0')
			{
				iss_count += put_all_numb(i, j, empt_brd, size);
			}
		}
	}
	return (iss_count);
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
	int iss_count;

	res = 0;
	iss_count = use_rules(tips, size);
	if (iss_count > 0)
	{
		printf("Wrong rules\n");
		return (0);
	}
	res = put_numb(tips, final_board, size, 0);
	return (res);
	return (0);
}