#include "fillit.h"

int		ft_abs(int a)
{
	return ((a < 0) ? -(a) : (a));
}

void	ft_count_neighbor(int stock_x[], int stock_y[], t_tetrimino **tet)
{
	int		i;
	int		j;
	int		res_x;
	int		res_y;
	int		near;

	i = -1;
	j = -1;
	res_x = 0;
	res_y = 0;
	near = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			res_x = ft_abs((stock_x[i] + 3) - (stock_x[j] + 3));
			res_y = ft_abs((stock_y[i] + 3) - (stock_y[j] + 3));
			if ((res_x == 1 && res_y == 0) || (res_x == 0 && res_y == 1))
				near++;
		}
	}
	if (near < 6)
		ft_error_exit();
	ft_store_valid_tetri(stock_x, stock_y, tet);
}

void	ft_normalize_coord(int stock_x[], int stock_y[], t_tetrimino **tet)
{
	int				i;
	int				norm_x;
	int				norm_y;

	i = -1;
	norm_x = stock_x[0];
	norm_y = stock_y[0];
	while (++i < 4)
	{
		stock_x[i] -= norm_x;
		stock_y[i] -= norm_y;
	}
	ft_count_neighbor(stock_x, stock_y, tet);
}

void	ft_map_coordinates(char *stock, t_tetrimino **tet)
{
	int		i;
	int		pos;
	int		stock_x[4];
	int		stock_y[4];

	i = -1;
	pos = 0;
	while (++i <= 19)
	{
		if (stock[i] == '#')
		{
			stock_x[pos] = i % 5;
			stock_y[pos++] = i / 5;
		}
	}
	ft_normalize_coord(stock_x, stock_y, tet);
}
