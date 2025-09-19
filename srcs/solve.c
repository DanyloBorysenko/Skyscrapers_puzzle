#include "skyscrapers.h"

int	solve(char **tips)
{
	printf("first 4 tips from main : %s\n", tips[0]);
	printf("first 4 tips from main : %s\n", tips[1]);
	printf("first 4 tips from main : %s\n", tips[2]);
	printf("first 4 tips from main : %s\n", tips[3]);
	char **final_brd = get_empt_brd(4);
	print_brd(final_brd, 4);
	free_brd(final_brd, 4);
	return (0);
}