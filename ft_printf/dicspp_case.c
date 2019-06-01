#include "ft_printf.h"

t_args	s_case(t_args list, va_list ap)
{
	if (!(list.data_mod))
		list.s = va_arg(ap, char*);
	list.data_type = "s\0";
	return (list);
}

t_args	c_case(t_args list, va_list ap)
{
	if (!(list.data_mod))
		list.c = va_arg(ap, int);
	list.data_type = "c\0";
	return (list);
}

t_args	di_case(t_args list, va_list ap)
{
	unsigned long long	comp;

	comp = 0;
	if (!(list.data_mod))
		list.i = va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "h") == 0)
		list.i = (short)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "hh") == 0)
		list.i = (signed char)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "l") == 0)
		list.i = va_arg(ap, long);
	else if (ft_strcmp(list.data_mod, "ll") == 0)
		list.i = va_arg(ap, long long);
	if (list.i < 0)
		list.plus = '-';
	if ((unsigned long long)list.i == -9223372036854775808uLL)
		list.modif = ft_strdup("-9223372036854775808");
	else
		list.modif = ft_itoa(list.i);
	list.data_type = "i\0";
	return (list);
}

t_args	p_case(t_args list, va_list ap)
{
	char	*str;

	str = NULL;
	list.i = va_arg(ap, intmax_t);
	str = ft_itoa_base(list.i, 16);
	list.data_type = "p\0";
	list.modif = "0x\0";
	list.modif = ft_strjoin(list.modif, str);
	free(str);
	return (list);
}

t_args	perc_case(t_args list)
{
	list.modif = ft_strdup("%");
	list.data_type = "%\0";
	return (list);
}
