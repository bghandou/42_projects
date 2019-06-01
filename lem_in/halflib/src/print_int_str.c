#include "libft.h"

void	print_int_str(int *tab, size_t len)
{
	if (!tab)
		return ;
	while (len--)
	{
		ft_putnbr(*tab);
		ft_putchar('\n');
		tab++;
	}
}
