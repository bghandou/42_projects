#include "ft_printf.h"

t_args	xsmall_case(t_args list, va_list ap)
{
	if (!(list.data_mod))
		list.u = va_arg(ap, unsigned int);
	else if (ft_strcmp(list.data_mod, "h") == 0)
		list.u = (unsigned short)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "hh") == 0)
		list.u = (unsigned char)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "l") == 0)
		list.u = va_arg(ap, unsigned long);
	else if (ft_strcmp(list.data_mod, "ll") == 0)
		list.u = va_arg(ap, unsigned long long);
	list.x = ft_itoa_basemax(list.u, 16);
	list.data_type = "x\0";
	if (list.hash == '#' && list.u != 0)
	{
		list.modif = "0x\0";
		list.modif = ft_strjoin(list.modif, list.x);
	}
	else if (list.hash == '#' && list.u != 0 && list.zero == '0')
	{
		list.modif = ft_strdup(list.x);
		list.pad_l -= 2;
	}
	else
		list.modif = ft_strdup(list.x);
	return (list);
}

t_args	xcap_case_2(t_args list, va_list ap)
{
	if (!(list.data_mod))
		list.u = va_arg(ap, unsigned int);
	else if (ft_strcmp(list.data_mod, "h") == 0)
		list.u = (unsigned short)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "hh") == 0)
		list.u = (unsigned char)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "l") == 0)
		list.u = va_arg(ap, unsigned long);
	else if (ft_strcmp(list.data_mod, "ll") == 0)
		list.u = va_arg(ap, unsigned long long);
	list.x = ft_itoa_basemax(list.u, 16);
	list.data_type = "X\0";
	return (list);
}

t_args	xcap_case(t_args list, va_list ap)
{
	int		i;

	i = 0;
	list = xcap_case_2(list, ap);
	while (list.x[i] != '\0')
	{
		if (list.x[i] >= 97 && list.x[i] <= 102)
			list.x[i] -= 32;
		i++;
	}
	if (list.hash == '#' && list.u != 0)
	{
		list.modif = "0X\0";
		list.modif = ft_strjoin(list.modif, list.x);
	}
	else if (list.hash == '#' && list.u != 0 && list.zero == '0')
	{
		list.modif = ft_strdup(list.x);
		list.pad_l -= 2;
	}
	else
		list.modif = ft_strdup(list.x);
	return (list);
}

t_args	o_case(t_args list, va_list ap)
{
	if (!(list.data_mod))
		list.u = va_arg(ap, unsigned int);
	else if (ft_strcmp(list.data_mod, "h") == 0)
		list.u = (unsigned short)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "hh") == 0)
		list.u = (unsigned char)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "l") == 0)
		list.u = va_arg(ap, unsigned long);
	else if (ft_strcmp(list.data_mod, "ll") == 0)
		list.u = va_arg(ap, unsigned long long);
	list.data_type = "o\0";
	if (list.hash == '#' && list.u != 0)
	{
		list.modif = "0\0";
		list.modif = ft_strjoin(list.modif, ft_itoa_basemax(list.u, 8));
	}
	else
	{
		list.modif = ft_itoa_basemax(list.u, 8);
	}
	return (list);
}

t_args	u_case(t_args list, va_list ap)
{
	if (!(list.data_mod))
		list.u = va_arg(ap, unsigned int);
	else if (ft_strcmp(list.data_mod, "h") == 0)
		list.u = (unsigned short)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "hh") == 0)
		list.u = (unsigned char)va_arg(ap, int);
	else if (ft_strcmp(list.data_mod, "l") == 0)
		list.u = va_arg(ap, unsigned long);
	else if (ft_strcmp(list.data_mod, "ll") == 0)
		list.u = va_arg(ap, unsigned long long);
	list.data_type = "u\0";
	list.modif = ft_itoa_basemax(list.u, 10);
	return (list);
}
