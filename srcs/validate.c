#include "skyscrapers.h"

int	validate(int args_count, char **args)
{
	int	digit_count;
	int	i;

	if (args_count != 2)
		return (-1);
	digit_count = 0;
	i = 0;
	while (args[1][i])
	{
		if(args[1][i] >= '1' && args[1][i] <= '4')
			digit_count++;
		else if(args[1][i] != ' ')
			return (-1);
		i++;
	}
	if (digit_count != 16)
		return (-1);
	return (0);
}
