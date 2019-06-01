#include "libft.h"

void	ft_putnbr_base(int n, int base)
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
	if ((n / base) > 0)
		ft_putnbr(n / base);
	ft_putchar(n % base + 48);
}
