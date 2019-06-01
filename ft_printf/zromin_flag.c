#include "ft_printf.h"

t_args	handle_minus(t_args list)
{
	int		pre_pad;
	int		pad;
	char	*pad_wid;
	int		i;

	pre_pad = ft_strlen(list.modif);
	pad = list.pad_l - pre_pad;
	if (pad > 0)
	{
		pad_wid = ft_strnew(pad + 1);
		i = -1;
		while (++i < pad)
			pad_wid[i] = ' ';
		list.modif_clean = ft_strjoin(list.modif, pad_wid);
		free(list.modif);
		list.modif = ft_strdup(list.modif_clean);
		free(list.modif_clean);
		free(pad_wid);
	}
	return (list);
}

t_args	handle_0_pad_2(t_args list, int i, char *pad_wid, int pad)
{
	if (list.dot == '.' && (list.prec < list.pad_l)
			&& (!(list.data_type[0] == 'f')))
	{
		while (++i < pad)
			pad_wid[i] = ' ';
	}
	else
	{
		while (++i < pad)
			pad_wid[i] = '0';
	}
	list.modif_clean = ft_strjoin(pad_wid, list.modif);
	free(list.modif);
	list.modif = ft_strdup(list.modif_clean);
	free(list.modif_clean);
	if (list.hash == '#' && (list.data_type[0] == 'x'
				|| list.data_type[0] == 'X') && list.dot == '.'
			&& (list.prec < list.pad_l))
		return (list);
	if (list.hash == '#' && (ft_strcmp(list.data_type, "x") == 0
				|| ft_strcmp(list.data_type, "X") == 0))
		list = handle_0prec_x(list, pad_wid);
	free(pad_wid);
	return (list);
}

t_args	handle_0_pad(t_args list)
{
	int		pre_pad;
	int		pad;
	char	*pad_wid;
	int		i;

	pre_pad = ft_strlen(list.modif);
	pad = list.pad_l - pre_pad;
	pad_wid = 0;
	i = -1;
	if (pad > 0)
	{
		pad_wid = ft_strnew(pad + 1);
		if (list.plus == '+' || list.plus == '-' || list.space == ' ')
		{
			if (list.plus == '+' || list.plus == '-')
				pad_wid[0] = list.plus;
			else if (list.space == ' ')
				pad_wid[0] = ' ';
			ft_memmove(list.modif, list.modif + 1, pre_pad);
			i++;
			pad++;
		}
		list = handle_0_pad_2(list, i, pad_wid, pad);
	}
	return (list);
}
