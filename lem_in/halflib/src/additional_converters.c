#include "libft.h"

void	print_errno(t_flag *all)
{
	char	*tmp;

	tmp = strerror(errno);
	ft_strcat2(tmp, all);
	all->space = 0;
}

void	get_charwriten(t_flag *all)
{
	int		*ptr;

	ptr = va_arg(all->ap, int *);
	*ptr = all->buffer_index;
}
