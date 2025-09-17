#include "skyscrapers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	val_res;

	val_res = validate(argc, argv);
	printf("val res is : %d\n", val_res);
	return (0);
}
