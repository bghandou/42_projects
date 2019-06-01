#include "push_swap.h"

int		check_ifin_buck(t_stack **head, int val)
{
	t_stack	*tmp;
	int		count;
	int		postn;

	tmp = *head;
	count = 0;
	postn = 0;
	while (tmp)
	{
		postn++;
		if (val == tmp->buck)
			return (postn);
		tmp = tmp->next;
	}
	return (0);
}

int		relative_position(t_stack **head, int val)
{
	t_stack	*tmp;
	int		postn;
	int		flag;
	int		nodes;

	tmp = *head;
	postn = 0;
	flag = 0;
	nodes = count_nodes(head);
	while (tmp)
	{
		postn++;
		if (tmp->pstn == val)
		{
			flag = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (!flag)
		return (0);
	return ((nodes / 2) - postn);
}
