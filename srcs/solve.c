#include "skyscrapers.h"

int	is_row_unq(char **arr, int row_ind, int size)
{
	char	unq_dig[size];
	int	unq_dig_count;

	unq_dig_count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[row_ind][i] == '0')
			continue;
		for (int j = 0; j < unq_dig_count; j++)
		{
			if (arr[row_ind][i] == unq_dig[j])
			{
				return (0);
			}
		}
		unq_dig[unq_dig_count] = arr[row_ind][i];
		unq_dig_count++;
	}
	return (1);
}

int	is_col_unq(char **arr, int col_ind, int size)
{
	char	unq_dig[size];
	int	unq_dig_count;

	unq_dig_count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i][col_ind] == '0')
			continue;
		for (int j = 0; j < unq_dig_count; j++)
		{
			if (arr[i][col_ind] == unq_dig[j])
			{
				return (0);
			}
		}
		unq_dig[unq_dig_count] = arr[i][col_ind];
		unq_dig_count++;
	}
	return (1);
}

int	solve(char **tips)
{
	printf("first 4 tips from main : %s\n", tips[0]);
	printf("first 4 tips from main : %s\n", tips[1]);
	printf("first 4 tips from main : %s\n", tips[2]);
	printf("first 4 tips from main : %s\n", tips[3]);
	char **final_brd = get_empt_brd(3);
	printf("Is row unique? %d\n", is_col_unq(final_brd, 0, 3));
	print_brd(final_brd, 3);
	free_brd(final_brd, 3);
	return (0);
}