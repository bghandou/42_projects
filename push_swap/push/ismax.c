#include "push_swap.h"

void	ismax(t_stack **head_a)
{
	t_stack		*tmp;
	intmax_t	stock;

	stock = -2147483648;
	tmp = *head_a;
	while (tmp)
	{
		if ((tmp->nbr > stock) && (tmp->ismax != 2))
			stock = tmp->nbr;
		tmp = tmp->next;
	}
	tmp = *head_a;
	while (tmp)
	{
		if ((stock == tmp->nbr) && (tmp->ismax != 2))
			tmp->ismax = 1;
		tmp = tmp->next;
	}
}

int		count_nodes(t_stack **head)
{
	t_stack	*tmp;
	int		count;

	tmp = *head;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void	define_pstn(t_stack **head_a)
{
	int		nodes;
	t_stack	*tmp;

	tmp = *head_a;
	nodes = count_nodes(head_a) - 1;
	ismax(head_a);
	while (tmp)
	{
		if (tmp->ismax != 1)
			tmp = tmp->next;
		else if (tmp->ismax == 1)
		{
			tmp->pstn = nodes;
			tmp->ismax = 2;
			nodes--;
			ismax(head_a);
			tmp = *head_a;
		}
	}
}

int		exp_max(t_stack **head)
{
	t_stack *tmp;
	int		nodes;
	int		val;
	int		exp;

	tmp = *head;
	nodes = count_nodes(head) - 1;
	val = 0;
	exp = 0;
	while (tmp)
	{
		if (tmp->pstn == nodes)
			val = tmp->pstn;
		tmp = tmp->next;
	}
	while (val > 0)
	{
		val /= 10;
		exp++;
	}
	return (exp);
}

int		in_order(t_stack **head)
{
	t_stack *tmp;
	int		track;

	tmp = *head;
	track = 0;
	while (tmp)
	{
		track = tmp->pstn;
		tmp = tmp->next;
		if (tmp && track > tmp->pstn)
			return (0);
	}
	return (1);
}
