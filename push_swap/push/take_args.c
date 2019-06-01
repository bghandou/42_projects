#include "push_swap.h"

t_stack	*create_list(int nbr)
{
	t_stack	*newlist;

	if (!(newlist = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	newlist->nbr = nbr;
	newlist->pstn = 0;
	newlist->buck = 0;
	newlist->ismax = 0;
	newlist->mx_exp = 0;
	newlist->next = NULL;
	return (newlist);
}

t_stack	*add_list(int nbr)
{
	t_stack	*new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	new->nbr = nbr;
	new->pstn = 0;
	new->buck = 0;
	new->ismax = 0;
	new->mx_exp = 0;
	new->next = NULL;
	return (new);
}

int		invalid_atoi(const char *str, t_stack **head, int *i, int neg)
{
	size_t	inside;
	t_stack	*nul_ptr;

	inside = 0;
	nul_ptr = NULL;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		inside = (inside * 10) + str[*i] - 48;
		if (inside >= 2147483648 && neg == 1)
			free_nodes_er(head, &nul_ptr, 1);
		else if (inside > 2147483648 && neg == -1)
			free_nodes_er(head, &nul_ptr, 1);
		*i += 1;
	}
	return (inside * neg);
}

int		ft_atoi_swp(const char *str, t_stack **head)
{
	int		i;
	size_t	neg;

	i = 0;
	neg = 1;
	if (!str)
		return (0);
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (invalid_atoi(str, head, &i, neg));
}
