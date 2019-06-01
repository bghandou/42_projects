#include "ft_printf.h"

t_args	handle_prec_string(t_args list)
{
	if (list.data_type[0] == '%')
		return (list);
	list.modif_clean = ft_strdup(list.modif);
	free(list.modif);
	list.modif = ft_strnew(list.prec + 1);
	ft_strncpy(list.modif, list.modif_clean, list.prec);
	return (list);
}

t_args	handle_space(t_args list)
{
	char	*stock;
	int		len;

	if (ft_isdigit(list.modif[0]) == 1)
	{
		len = ft_strlen(list.modif);
		stock = ft_strnew(len + 2);
		stock[0] = list.space;
		list.modif_clean = ft_strjoin(stock, list.modif);
		free(list.modif);
		list.modif = ft_strdup(list.modif_clean);
		free(list.modif_clean);
		free(stock);
	}
	return (list);
}

t_args	handle_plus(t_args list)
{
	char	*stock;
	int		len;

	len = ft_strlen(list.modif);
	stock = ft_strnew(len + 2);
	if (list.modif[0] != '-')
		stock[0] = list.plus;
	else
		list.plus = '-';
	list.modif_clean = ft_strjoin(stock, list.modif);
	free(list.modif);
	list.modif = ft_strdup(list.modif_clean);
	free(list.modif_clean);
	free(stock);
	return (list);
}

void	parse_flags(t_args *list)
{
	if (!list->modif)
		print_string(list);
	if (list->plus == '+')
		*list = handle_plus(*list);
	if (list->space == ' ' && list->plus != '+')
		*list = handle_space(*list);
	if (list->dot == '.' && (ft_strcmp(list->data_type, "s") == 0
				|| list->data_type[0] == '%'))
		*list = handle_prec_string(*list);
	if (list->dot == '.' && (!(ft_strcmp(list->data_type, "s") == 0
					|| list->data_type[0] == '%')))
		*list = handle_prec(*list);
	if (list->minus == '-')
		*list = handle_minus(*list);
	if (list->zero == '0' && list->minus != '-')
		*list = handle_0_pad(*list);
	if (list->pad_l > 0 && (!(list->minus == '-' || list->zero == '0')))
		*list = handle_leftpad(*list);
	print_string(list);
}

void	prepare_modif(t_args *list)
{
	if (ft_strcmp(list->data_type, "c") == 0)
	{
		list->modif = ft_strnew(2);
		list->modif[0] = list->c;
		if (list->c == 0)
		{
			list->data_type = "cn\0";
			if (list->minus != '-')
				list->char_cnt += 1;
		}
	}
	else if (ft_strcmp(list->data_type, "s") == 0)
	{
		if (list->s == NULL)
			list->modif = ft_strdup("(null)");
		else
			list->modif = ft_strdup(list->s);
	}
	parse_flags(list);
}
