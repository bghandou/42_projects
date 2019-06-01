#include "libft.h"

static int	get_size(size_t nb, int prec)
{
	int size;

	size = 0;
	nb == 0 ? size++ : 0;
	while (nb > 0 || (prec-- > 3 && size < 9))
	{
		size++;
		nb /= 16;
	}
	return (size);
}

static void	printer(size_t nb, t_flag *all)
{
	int		index;
	char	tmp[15];

	ft_bzero2(tmp, 15);
	index = get_size(nb, all->precision) - 1;
	if (nb == 0)
	{
		all->precision == 0 ? ft_strcat2("0x", all) : 0;
		all->precision != 0 ? ft_strcat2("0x0", all) : 0;
		while (all->precision-- - 2 >= 0 && index < 10)
			ft_charcat2('0', all);
		return ;
	}
	while (nb > 0 || all->precision-- > 3)
	{
		if (nb % 16 <= 9)
			tmp[index-- + 2] = nb % 16 + '0';
		else
			tmp[index-- + 2] = nb % 16 + 'a' - 10;
		nb /= 16;
	}
	tmp[0] = '0';
	tmp[1] = 'x';
	ft_strcat2(tmp, all);
}

void		ft_ptoa(size_t nb, t_flag *all)
{
	int size;

	size = get_size(nb, all->precision) + 2;
	while (!all->minus && all->minsize-- > size)
		ft_charcat2(all->zero ? '0' : ' ', all);
	printer(nb, all);
	while (all->minus && all->minsize-- > size)
		ft_charcat2(' ', all);
}
