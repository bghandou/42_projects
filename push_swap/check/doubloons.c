#include "push_swap.h"

void	check_if_doubloons(t_stack **head, int count)
{
	t_stack *tmp1;
	t_stack	*tmp2;
	t_stack	*nul_pt;
	int		to;

	to = 0;
	nul_pt = NULL;
	tmp1 = *head;
	while (to++ < count)
		tmp1 = tmp1->next;
	to = 0;
	tmp2 = tmp1->next;
	while (tmp2)
	{
		if (tmp1->nbr == tmp2->nbr)
			free_nodes_er(head, &nul_pt, 1);
		tmp2 = tmp2->next;
	}
	if (tmp1->next)
		check_if_doubloons(head, count + 1);
	else
		return ;
}
