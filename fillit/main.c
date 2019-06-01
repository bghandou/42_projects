#include "fillit.h"

int	main(int ac, char **av)
{
	t_tetrimino	*stock_tetri;
	int			ret;
	int			fd;
	char		**square;
	char		buf[BUFF_SIZE + 1];

	ret = 0;
	if (ac != 2)
		ft_usage();
	fd = open(av[1], O_RDONLY);
	if (!(stock_tetri = (t_tetrimino *)malloc(27 * sizeof(t_tetrimino))))
		return (0);
	if (read(fd, buf, 0) == -1)
		ft_error_exit();
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_stock_feed(buf, ret, &stock_tetri);
	}
	buf[ret] = '\0';
	ft_stock_feed(buf, ret, &stock_tetri);
	ft_print_2dtable(square = ft_fillit(stock_tetri));
	ft_square_del(square);
	free(stock_tetri);
	return (0);
}
