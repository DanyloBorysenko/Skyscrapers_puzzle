#include "skyscrapers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	val_res;
	char **tips;

	val_res = validate(argc, argv);
	if (val_res == 0)
	{
		tips = get_tips(argv);
		printf("first tip is : %s\n", tips[0]);
		printf("second tip is : %s\n", tips[1]);
		printf("third tip is : %s\n", tips[2]);
		printf("fith tip is : %s\n", tips[3]);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
