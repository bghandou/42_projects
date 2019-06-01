#include "ft_printf.h"

void	error_fctn(t_args list)
{
	if (list.modif != NULL)
		free(list.modif);
	if (list.data_mod != NULL)
		free(list.data_mod);
	if (list.x != NULL)
		free(list.x);
	ft_putendl(" >>>> ERROR : unrecognized format");
	exit(EXIT_SUCCESS);
}

void	print_string(t_args *list)
{
	list->char_cnt += ft_strlen(list->modif);
	ft_putstr(list->modif);
	if (ft_strcmp(list->data_type, "cn") == 0)
		ft_putchar(list->c);
	ft_strdel(&list->modif);
	if (list->x != NULL)
		free(list->x);
	if (list->data_mod != NULL)
		free(list->data_mod);
}

t_args	handle_0prec_x(t_args list, char *pad_wid)
{
	size_t	i;

	i = -1;
	if (list.data_type[0] == 'X')
	{
		list.modif_clean = ft_strjoin("0X\0", pad_wid);
		free(list.modif);
		list.modif = ft_strjoin(list.modif_clean, list.x);
		free(list.modif_clean);
	}
	else if (list.data_type[0] == 'x')
	{
		list.modif_clean = ft_strjoin("0x\0", pad_wid);
		free(list.modif);
		list.modif = ft_strjoin(list.modif_clean, list.x);
		free(list.modif_clean);
	}
	return (list);
}
