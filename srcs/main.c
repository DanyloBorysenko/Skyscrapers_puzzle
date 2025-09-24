#include "skyscrapers.h"

int	main(int argc, char **argv)
{
	int	val_res;
	char **tips;
	int	size;
	int	is_solved;
	char **final_brd;

	val_res = validate(argc, argv);
	if (val_res == 0)
	{
		printf("Error\n");
		return (0);
	}
	size = get_size(argv[1]);
	if (size == 0)
	{
		printf("Error");
		return (0);
	}
	tips = get_tips(argv[1], size);
	final_brd = get_empt_brd(size);
	is_solved = solve(tips, final_brd, size);
	if (is_solved == 1)
	{
		print_brd(final_brd, size);
	}
	else
		printf("Error\n");
	free_brd(final_brd, size);
	free_brd(tips, 4);
	return (0);
}
