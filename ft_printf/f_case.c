#include "ft_printf.h"

void	f_case_5(t_args *list, size_t exp, int flag, size_t len)
{
	char	*dec;
	int		count;

	len = 0;
	count = 0;
	flag = 0;
	while (exp > 2)
	{
		exp /= 10;
		flag++;
	}
	dec = ft_strnew(list->prec);
	while (count++ < (list->prec - flag))
	{
		dec[len] = '0';
		len++;
	}
	dec[len] = '\0';
	len += ft_strlen(list->modif);
	list->modif_clean = ft_strdup(list->modif);
	free(list->modif);
	list->modif = ft_strjoin(list->modif_clean, dec);
	free(list->modif_clean);
	list->modif[len] = '\0';
	free(dec);
}

int		f_case_4(t_args *list, int flag, intmax_t conv, size_t exp)
{
	char	*dec;

	dec = ft_itoa((list->f - conv) * exp);
	if (ft_strcmp(dec, "0") == 0)
		return (flag);
	if ((intmax_t)((list->f - conv) * (exp * 10)) % 10 >= 5)
		flag = 2;
	list->modif_clean = ft_strjoin(list->modif, dec);
	free(list->modif);
	list->modif = ft_strdup(list->modif_clean);
	free(list->modif_clean);
	free(dec);
	return (flag);
}

size_t	f_case_3(t_args *list, size_t len, intmax_t conv, size_t exp)
{
	int			count;
	intmax_t	check;
	int			flag;

	count = 0;
	flag = 0;
	ft_strcat(list->modif, ".\0");
	if (exp >= 10)
		exp /= 10;
	while (count < list->prec && count < 19)
	{
		check = (list->f - conv) * exp;
		if (check != 0)
		{
			flag = 1;
			list->modif[len++] = '\0';
		}
		if (check == 0 && flag == 0)
			list->modif[++len] = '0';
		check = (list->f - conv) * exp;
		exp *= 10;
		count++;
	}
	return (exp);
}

void	f_case_2(t_args *list, va_list ap, intmax_t *conv, size_t *len)
{
	char	*dec;

	dec = 0;
	if (!(list->data_mod))
		list->f = va_arg(ap, double);
	else if (ft_strcmp(list->data_mod, "L") == 0)
		list->f = va_arg(ap, long double);
	if (list->f < 0)
		list->plus = '-';
	*conv = list->f;
	dec = ft_itoa(*conv);
	*len = ft_strlen(dec);
	list->data_type = "f\0";
	list->modif = ft_strnew(*len + 1 + list->prec + 6);
	list->modif_clean = ft_itoa(*conv);
	ft_strcpy(list->modif, list->modif_clean);
	free(list->modif_clean);
	free(dec);
}

t_args	f_case(t_args list, va_list ap)
{
	intmax_t	conv;
	size_t		len;
	size_t		exp;
	intmax_t	check;
	int			flag;

	exp = 1;
	check = 0;
	flag = 0;
	f_case_2(&list, ap, &conv, &len);
	if (list.dot != '.')
	{
		list.prec = 6;
		list.dot = '.';
	}
	if (list.dot == '.' && list.prec > 0)
		exp = f_case_3(&list, len, conv, exp);
	if (exp > 1 && list.f != 0)
		flag = f_case_4(&list, flag, conv, exp);
	if (flag == 2 && list.modif[ft_strlen(list.modif) - 1] != '9')
		list.modif[ft_strlen(list.modif) - 1] += 1;
	if (list.prec > 19)
		f_case_5(&list, exp, flag, check);
	return (list);
}
