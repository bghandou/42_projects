#include "push_swap.h"

void	small_arg(t_stack **head_a, t_stack **head_b)
{
	int		a;

	a = 0;
	fill_bucket(head_a, 1);
	if (!*head_a)
		return ;
	while (!in_order(head_a) && check_ifin_buck(head_a, a))
	{
		while ((*head_a) && (*head_a)->buck == a)
		{
			push_b(head_a, head_b);
			check_ifin_buck(head_a, a) ? 1 : a++;
		}
		if (count_nodes(head_a) == 3)
			small_arg2(head_a);
		if (in_order(head_a))
			break ;
		if (check_ifin_buck(head_a, a) && (relative_position(head_a, a) >= 0))
			rotate_a(head_a);
		else if (check_ifin_buck(head_a, a)
				&& (relative_position(head_a, a) < 0))
			reverse_a(head_a);
	}
	while (*head_b)
		push_a(head_a, head_b);
}

void	small_arg2(t_stack **head_a)
{
	t_stack *tmp;

	tmp = (*head_a)->next;
	if ((*head_a)->pstn == 4)
	{
		if (tmp->pstn == 2)
			rotate_a(head_a);
		else if (tmp->pstn == 3)
		{
			swap_a(head_a);
			reverse_a(head_a);
		}
	}
	else if ((*head_a)->pstn == 3)
	{
		if (tmp->pstn == 2)
			swap_a(head_a);
		else if (tmp->pstn == 4)
			reverse_a(head_a);
	}
	else if ((*head_a)->pstn == 2)
	{
		swap_a(head_a);
		rotate_a(head_a);
	}
}

void	tiny_arg(t_stack **head_a)
{
	t_stack *tmp;

	tmp = (*head_a)->next;
	if ((*head_a)->pstn == 2)
	{
		if (tmp->pstn == 0)
			rotate_a(head_a);
		else if (tmp->pstn == 1)
		{
			swap_a(head_a);
			reverse_a(head_a);
		}
	}
	else if ((*head_a)->pstn == 1)
	{
		if (tmp->pstn == 0)
			swap_a(head_a);
		else if (tmp->pstn == 2)
			reverse_a(head_a);
	}
	else if ((*head_a)->pstn == 0)
	{
		swap_a(head_a);
		rotate_a(head_a);
	}
}
