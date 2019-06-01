#include "fillit.h"

void	ft_store_valid_tetri(int stock_x[], int stock_y[], t_tetrimino **tet)
{
	static int			tetri_count = 0;
	int					i;
	int					status;

	i = -1;
	status = 0;
	while (++i < 4)
	{
		tet[0][tetri_count].x[i] = stock_x[i];
		tet[0][tetri_count].y[i] = stock_y[i];
		tet[0][tetri_count].status = AVAILABLE;
	}
	tet[0][tetri_count + 1].status = LAST;
	tetri_count++;
}

char	**ft_fillit(t_tetrimino *file)
{
	char	**square;
	int		i;
	int		j;
	int		end;
	int		nb_tetrimino;

	nb_tetrimino = 0;
	while (file[nb_tetrimino].status != LAST)
		nb_tetrimino++;
	i = ft_sqrt(4 * nb_tetrimino) - 1;
	end = 0;
	while (!end)
	{
		if (!(square = ft_init_square(++i)))
			return (NULL);
		end = ft_algo(&square, file, i, 0);
		j = -1;
		if (!end)
		{
			while (++j < i)
				free(square[j]);
			free(square);
		}
	}
	return (square);
}

void	ft_usage(void)
{
	ft_putendl("usage: ./fillit target_file");
	exit(EXIT_SUCCESS);
}

void	ft_square_del(char **square)
{
	int	i;
	int	j;

	i = ft_strlen(square[0]);
	j = -1;
	while (++j < i)
		free(square[j]);
	free(square);
}
