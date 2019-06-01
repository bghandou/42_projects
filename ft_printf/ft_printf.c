#include "ft_printf.h"

t_args	stock_modifiers(t_args list, const char *format, int *flag)
{
	if (*format == 'h' && *flag == 2)
	{
		free(list.data_mod);
		list.data_mod = ft_strdup("hh");
	}
	else if (*format == 'h' && *flag == 0)
	{
		*flag = 2;
		list.data_mod = ft_strdup("h");
	}
	else if (*format == 'l' && *flag == 1)
	{
		free(list.data_mod);
		list.data_mod = ft_strdup("ll");
	}
	else if (*format == 'l' && *flag == 0)
	{
		*flag = 1;
		list.data_mod = ft_strdup("l");
	}
	else if (*format == 'L')
		list.data_mod = ft_strdup("L");
	return (list);
}

void	initialize_structure(t_args *list, const char *restrict format)
{
	list->s = NULL;
	list->c = 0;
	list->i = 0;
	list->u = 0;
	list->f = 0;
	list->plus = 0;
	list->hash = 0;
	list->space = 0;
	list->dot = 0;
	list->star = 0;
	list->zero = 0;
	list->minus = 0;
	list->pad_l = 0;
	list->prec = 0;
	list->data_mod = NULL;
	list->data_type = NULL;
	list->modif = NULL;
	list->modif_clean = NULL;
	list->x = NULL;
	if (!format)
		error_fctn(*list);
}

int		primary_flags_2(const char *restrict format, va_list ap,
	t_args *list, int len)
{
	while (!(format[len] > '0' && format[len] <= '9'))
	{
		if (format[len] == '*')
		{
			list->pad_l = va_arg(ap, int);
			if (list->pad_l < 0)
				list->minus = '-';
			list->star = '*';
		}
		else if (format[len] == '#')
			list->hash = '#';
		else if (format[len] == '+')
			list->plus = '+';
		else if (format[len] == '-')
			list->minus = '-';
		else if (format[len] == '0')
			list->zero = '0';
		else if (format[len] == ' ')
			list->space = ' ';
		else
			break ;
		len++;
	}
	return (len);
}

int		primary_flags(const char *restrict format, va_list ap, t_args *list)
{
	int		len;
	int		flag;

	len = 0;
	flag = 0;
	list->data_mod = NULL;
	len = primary_flags_2(&format[len], ap, list, len);
	*list = padding_length(*list, &format[len], &len, ap);
	if (format[len] == 'h' || format[len] == 'l' || format[len] == 'L')
	{
		*list = stock_modifiers(*list, &format[len], &flag);
		len++;
	}
	if ((format[len] == 'l' && format[len - 1] == 'l')
			|| (format[len] == 'h' && format[len - 1] == 'h'))
	{
		*list = stock_modifiers(*list, &format[len], &flag);
		len++;
	}
	*list = check_type_1(*list, &format[len], ap);
	prepare_modif(list);
	return (len);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		len;
	t_args	list;

	len = 0;
	list.char_cnt = 0;
	va_start(ap, format);
	while (format[len] != '\0')
	{
		initialize_structure(&list, format);
		if (format[len] == '%' && format[len + 1] != '%')
		{
			len++;
			len += primary_flags(&format[len], ap, &list) + 1;
		}
		else
		{
			list.char_cnt += 1;
			if (format[len] == '%' && format[len + 1] == '%')
				len++;
			ft_putchar(format[len++]);
		}
	}
	va_end(ap);
	return (list.char_cnt);
}
