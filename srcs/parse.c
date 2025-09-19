#include "skyscrapers.h"

char *del_sps(char *str)
{
	char	*res;
	int	dig_count;
	int	i;
	int	j;

	dig_count = 16;
	res = malloc((dig_count + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

char *get_dup(char *src, int start_ind)
{
	char 	*dup;
	int		i;

	dup = malloc(5 *sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		dup[i] = src[start_ind + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char **get_tips(char **args)
{
	char	**tips;
	char	*digits;
	int	i;
	int	j;

	digits = del_sps(args[1]);
	tips = malloc(4 * sizeof(char *));
	if (!tips)
		return (NULL);
	i = 0;
	j = 0;
	while (i < 4)
	{
		tips[i] = get_dup(digits, j);
		i++;
		j += 4;
	}
	free(digits);
	return (tips);
}
