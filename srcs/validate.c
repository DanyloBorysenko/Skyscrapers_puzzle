#include "skyscrapers.h"

int	validate(int args_count, char **args)
{
	if (args_count != 2)
	{
		printf("Only one argument is allowed\n");
		return (0);
	}
	for (int i = 0; args[1][i] != '\0'; i++)
	{
		if (args[1][i] == ' ')
			continue;
		if (args[1][i] < '1' || args[1][i] > '9')
		{
			printf("Argument must contain only digits\n");
			return (0);
		}
	}

	return (1);
}
