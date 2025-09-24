#include "skyscrapers.h"

int	get_size(char *str)
{
	int	dig_count;

	dig_count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			continue;
		dig_count++;
	}
	if (dig_count % 4 != 0 || dig_count > 36)
	{
		printf("wrong digits count\n");
		return (0);
	}
	return (dig_count / 4);
}

char *del_sps(char *str, int size)
{
	char	*res;
	int	dig_count;
	int	i;
	int	j;

	dig_count = size * 4;
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

char *get_dup(char *src, int start_ind, int size)
{
	char 	*dup;
	int		i;

	dup = malloc((size + 1) *sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = src[start_ind + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char **get_tips(char *arg, int size)
{
	char	**tips;
	char	*digits;
	int	i;
	int	j;

	digits = del_sps(arg, size);
	tips = malloc(4 * sizeof(char *));
	if (!tips)
		return (NULL);
	i = 0;
	j = 0;
	while (i < 4)
	{
		tips[i] = get_dup(digits, j, size);
		i++;
		j += size;
	}
	free(digits);
	return (tips);
}
