#include "fillit.h"

void	ft_error_exit(void)
{
	ft_putendl("error");
	exit(EXIT_SUCCESS);
}

int		ft_check_valid_board_2(char *stock)
{
	int			count_d;
	int			count_h;
	int			count_n;
	int			i;
	static int	loop;

	count_d = 0;
	count_h = 0;
	count_n = 0;
	i = -1;
	loop++;
	if (loop > 27)
		ft_error_exit();
	while (stock[++i] != '\0' && (i < 19))
	{
		if (stock[i] == '.')
			count_d++;
		else if (stock[i] == '#')
			count_h++;
		else if (stock[i] == '\n' && ((i % 5) == 4))
			count_n++;
	}
	if (count_h != 4)
		ft_error_exit();
	return (count_d + count_h + count_n);
}

void	ft_check_valid_board_1(char *stock, t_tetrimino **tet)
{
	int			t_cnt;

	t_cnt = 0;
	t_cnt = ft_check_valid_board_2(stock);
	if (t_cnt != 19)
		ft_error_exit();
	ft_map_coordinates(stock, tet);
	if ((stock[t_cnt] != '\n' || stock[t_cnt] != '\0') &&
			(!((stock[t_cnt + 1] == '\n') || (stock[t_cnt + 1] == '\0'))))
		ft_error_exit();
	if (stock[t_cnt + 1] == '\n' && stock[t_cnt + 2] == '\0')
		ft_error_exit();
	ft_memmove(stock, stock + 21, ft_strlen(stock));
	if (stock[0] != '\0')
		ft_check_valid_board_1(stock, tet);
}

void	ft_stock_feed(char *feed, int ret, t_tetrimino **tet)
{
	static char stock[600];
	static int	size;
	int			i;

	i = -1;
	size += ret;
	if (size > 546)
		ft_error_exit();
	if (stock[0] == '\0')
		ft_strcpy(stock, feed);
	else
		ft_strcat(stock, feed);
	if (ret == 0)
		ft_check_valid_board_1(stock, tet);
}
