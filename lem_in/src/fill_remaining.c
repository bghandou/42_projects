#include "lem_in.h"

void	fill_remaining(int *table, long ant_nb)
{
	size_t	i;
	int		sum;

	i = 0;
	sum = 0;
	if (table == NULL)
		return ;
	while (table[i] != INT_MIN)
		sum += table[i++];
	if (sum == (int)ant_nb)
		return ;
	else
	{
		i = 0;
		sum = (int)ant_nb - sum;
		while (sum > 0 && table[i] != INT_MIN)
		{
			if (table[i] != 0)
			{
				table[i] = table[i] + 1;
				sum--;
			}
			i++;
		}
	}
}

void	check_startend(int *table, long ant_nb, t_node *start)
{
	int		i;
	int		j;
	int		flag;

	i = -1;
	j = 0;
	flag = 0;
	if (start->links)
	{
		while (start->links[++i])
		{
			if (start->links[i]->role == END)
				flag = 1;
		}
		i = -1;
		while (start->links[++i] && flag == 1 && table)
		{
			if (start->links[i]->role == END)
				table[j++] = ant_nb;
			else if (start->flux[i] == 1)
				table[j++] = 0;
		}
	}
}
