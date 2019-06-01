#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int total;
	int signe;

	total = 0;
	while (ft_isspace(*nptr))
		nptr++;
	signe = (*nptr == '-') ? -1 : 1;
	nptr = (*nptr == '-' || *nptr == '+') ? nptr + 1 : nptr;
	while (ft_isdigit(*nptr))
		total = total * 10 + *nptr++ - 48;
	return (total * signe);
}
