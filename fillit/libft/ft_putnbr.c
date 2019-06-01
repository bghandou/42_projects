#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if ((n / 10) > 0)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}
