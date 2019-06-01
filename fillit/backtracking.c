#include "fillit.h"

int		ft_check(char **square, int i, t_tetrimino current, int position)
{
	int	j;
	int	line;
	int	column;

	line = position / i;
	column = position % i;
	j = -1;
	while (++j < 4)
	{
		if (line + current.y[j] < 0 || line + current.y[j] >= i ||
				column + current.x[j] >= i || column + current.x[j] < 0
				|| square[line + current.y[j]][column + current.x[j]] != '.')
			return (0);
	}
	return (1);
}

char	**ft_fill_square(char **square, t_tetrimino *cur, int pos, char letter)
{
	int line;
	int column;
	int i;
	int	j;

	j = -1;
	i = ft_strlen(square[0]);
	line = pos / i;
	column = pos % i;
	while (++j < 4)
		square[line + cur->y[j]][column + cur->x[j]] = letter;
	cur->status = PLACED;
	return (square);
}

char	**ft_erase_square(char **square, int i, char letter)
{
	int	j;
	int	k;

	j = -1;
	k = -1;
	while (++j < i)
	{
		while (++k < i)
			if (square[j][k] == letter)
				square[j][k] = '.';
		k = -1;
	}
	return (square);
}

int		ft_algo2(char ***square, t_tetrimino *file, int i, int position)
{
	int	first;
	int	pos_tmp;

	first = 0;
	pos_tmp = position;
	while (file[first].status == PLACED)
		first++;
	if (file[first].status == LAST)
		return (1);
	while (!ft_check(square[0], i, file[first], pos_tmp) && pos_tmp < i * i)
		pos_tmp++;
	if (pos_tmp == i * i)
		return (0);
	square[0] = ft_fill_square(square[0], file + first, pos_tmp, first + 65);
	if (pos_tmp == position ? ft_algo(square, file, i, position) :
			ft_algo(square, file, i, position))
		return (1);
	square[0] = ft_erase_square(square[0], i, first + 65);
	file[first].status = AVAILABLE;
	return (ft_algo2(square, file, i, pos_tmp + 1));
}

int		ft_algo(char ***square, t_tetrimino *file, int i, int position)
{
	int	algo2;

	position = 0;
	if (position == (i * i))
		return (ft_return(file));
	algo2 = ft_algo2(square, file, i, position);
	return (algo2);
}
