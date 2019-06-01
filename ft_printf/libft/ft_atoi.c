#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	size_t	neg;
	size_t	inside;

	inside = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		inside = (inside * 10) + str[i] - 48;
		i++;
	}
	return (inside * neg);
}
