#include "skyscrapers.h"

int	main(int argc, char **argv)
{
	int	val_res;
	char **tips;

	val_res = validate(argc, argv);
	if (val_res == -1)
	{
		printf("Error\n");
		return (0);
	}
	tips = get_tips(argv);
	solve(tips);
	free_brd(tips, 4);
	return (0);
}
