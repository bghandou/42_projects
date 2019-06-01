#include "ft_printf.h"

t_args	check_type_3(t_args list, const char *restrict format, va_list ap)
{
	if (*format == 'X')
	{
		list = xcap_case(list, ap);
		return (list);
	}
	else if (*format == '%')
	{
		list = perc_case(list);
		return (list);
	}
	else if (!(*format == 'c' || *format == 's' || *format == 'p'
				|| *format == 'p' || *format == 'f' || *format == '%'))
		error_fctn(list);
	return (list);
}

t_args	check_type_2(t_args list, const char *restrict format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
	{
		list = di_case(list, ap);
		return (list);
	}
	else if (*format == 'o')
	{
		list = o_case(list, ap);
		return (list);
	}
	else if (*format == 'u')
	{
		list = u_case(list, ap);
		return (list);
	}
	else if (*format == 'x')
	{
		list = xsmall_case(list, ap);
		return (list);
	}
	list = check_type_3(list, format, ap);
	return (list);
}

t_args	check_type_1(t_args list, const char *restrict format, va_list ap)
{
	list = check_type_2(list, format, ap);
	if (*format == 'c')
	{
		list = c_case(list, ap);
		return (list);
	}
	else if (*format == 's')
	{
		list = s_case(list, ap);
		return (list);
	}
	else if (*format == 'p')
	{
		list = p_case(list, ap);
		return (list);
	}
	else if (*format == 'f')
	{
		list = f_case(list, ap);
		return (list);
	}
	return (list);
}

t_args	check_prec_flag(const char *format, t_args list, int *add, va_list ap)
{
	int		i;
	int		len;
	char	*prc_l;

	i = 0;
	len = 0;
	if (format[i] == '.')
	{
		list.dot = '.';
		if (format[++i] == '*')
		{
			i++;
			list.prec = va_arg(ap, int);
			*add += 2;
			return (list);
		}
	}
	while (ft_isdigit(format[i + len]))
		len++;
	prc_l = ft_strnew(len);
	ft_strncpy(prc_l, &format[i], len);
	list.prec = ft_atoi(prc_l);
	*add += len + i;
	free(prc_l);
	return (list);
}

t_args	padding_length(t_args list, const char *format,
		int *add, va_list ap)
{
	int		len;
	char	*pad_l;

	len = 0;
	pad_l = 0;
	if (list.star == '*')
	{
		if (list.pad_l < 0)
		{
			list.pad_l *= -1;
			return (list);
		}
		list = check_prec_flag(&format[len], list, add, ap);
		return (list);
	}
	while (ft_isdigit(format[len]))
		len++;
	pad_l = ft_strnew(len);
	ft_strncpy(pad_l, format, len);
	list.pad_l = ft_atoi(pad_l);
	free(pad_l);
	*add += len;
	list = check_prec_flag(&format[len], list, add, ap);
	return (list);
}
