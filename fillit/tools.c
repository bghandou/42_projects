#include "fillit.h"

char	**ft_init_square(int i)
{
	char	**square;
	int		j;
	int		k;

	j = -1;
	k = -1;
	if (!(square = (char **)malloc((i + 1) * sizeof(char *))))
		return (NULL);
	square[i] = NULL;
	while (++j < i)
	{
		if (!(square[j] = (char *)malloc((i + 1) * sizeof(char))))
			return (NULL);
		while (++k < i)
			square[j][k] = '.';
		square[j][k] = '\0';
		k = -1;
	}
	return (square);
}

void	ft_print_2dtable(char **tab)
{
	int i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		ft_putendl(tab[i]);
}

int		ft_return(t_tetrimino *file)
{
	int	i;

	i = -1;
	while (file[++i].status != LAST)
		if (file[i].status == AVAILABLE)
			return (0);
	return (1);
}

int		ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}
