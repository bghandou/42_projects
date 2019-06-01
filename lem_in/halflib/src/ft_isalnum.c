#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c) ? 1 : 0);
}

int	ft_isalphanum_base(int c, int base, int maj)
{
	char	verif;
	int		iteration;

	verif = 48;
	iteration = 0;
	while (iteration++ <= base)
	{
		if (c == verif)
			return (1);
		verif++;
		if (verif == 59)
			verif = maj ? 'A' : 'a';
	}
	return (0);
}
