#include "push_swap.h"

void	check_digit_string2(char **str)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!str)
		return ;
	while (str[++j])
	{
		while (str[j][++i])
		{
			if ((ft_strcmp(str[j], "-v") == 0) && j == 0)
				break ;
			if ((ft_strcmp(str[j], "-") == 0) || (!ft_isdigit(str[j][i])
						&& !(i == 0 && str[j][i] == '-')))
			{
				ft_putstr_fd("Error\n", 2);
				free_string_args2(str);
				exit(EXIT_FAILURE);
			}
		}
		i = -1;
	}
}

void	check_digit_args2(int ac, char **av, int flag)
{
	int		i;
	int		k;

	i = 1 + flag;
	k = -1;
	while (i < ac)
	{
		while (av[i][++k])
		{
			if (ft_strcmp(av[i], "-") == 0)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			else if (!ft_isdigit(av[i][k]) && !(k == 0 && av[i][k] == '-'))
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		k = -1;
		i++;
	}
}

void	free_string_args2(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
