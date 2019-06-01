#include "ft_printf.h"

t_args	handle_prec_2(t_args list, int adjst, int len)
{
	char	*ad_pad;

	ad_pad = ft_strnew(adjst + 1);
	len = -1;
	if (list.plus == '+' || list.plus == '-' || list.space == ' ')
	{
		if (list.plus == '+' || list.plus == '-')
			ad_pad[0] = list.plus;
		else if (list.space == ' ')
			ad_pad[0] = ' ';
		ft_memmove(list.modif, list.modif + 1, ft_strlen(list.modif));
		len++;
		adjst++;
	}
	while (++len < adjst)
		ad_pad[len] = '0';
	list.modif_clean = ft_strjoin(ad_pad, list.modif);
	free(list.modif);
	list.modif = ft_strdup(list.modif_clean);
	free(list.modif_clean);
	if (list.hash == '#' && (ft_strcmp(list.data_type, "x") == 0
				|| ft_strcmp(list.data_type, "X") == 0))
		list = handle_0prec_x(list, ad_pad);
	free(ad_pad);
	return (list);
}

t_args	handle_prec_3(t_args list)
{
	free(list.modif);
	list.modif = ft_strdup("");
	return (list);
}

t_args	handle_prec(t_args list)
{
	int		len;
	int		adjst;
	int		i;

	len = 0;
	i = 0;
	while (list.modif[i++] != '\0')
	{
		if (ft_isdigit(list.modif[i - 1]) || ft_isalpha(list.modif[i - 1]))
			len++;
	}
	adjst = list.prec - len;
	if (list.hash == '#' && (ft_strcmp(list.data_type, "x") == 0
				|| ft_strcmp(list.data_type, "X") == 0))
		adjst += 2;
	if (list.prec == 0 && list.modif[0] == '0'
			&& (!(list.data_type[0] == 'o' && list.hash == '#')))
	{
		list = handle_prec_3(list);
		return (list);
	}
	if (adjst > 0)
		list = handle_prec_2(list, adjst, len);
	return (list);
}

t_args	handle_leftpad(t_args list)
{
	int		pre_pad;
	int		pad;
	char	*pad_wid;
	int		i;

	pre_pad = (ft_strlen(list.modif) == 0
			&& (ft_strcmp(list.data_type, "cn") == 0))
		? 1 : ft_strlen(list.modif);
	pad = list.pad_l - pre_pad;
	if (pad > 0)
	{
		pad_wid = ft_strnew(pad + 1);
		i = -1;
		while (++i < pad)
			pad_wid[i] = ' ';
		list.modif_clean = (list.modif != NULL)
			? ft_strjoin(pad_wid, list.modif) : ft_strdup(pad_wid);
		free(list.modif);
		list.modif = ft_strdup(list.modif_clean);
		free(list.modif_clean);
		free(pad_wid);
	}
	return (list);
}
