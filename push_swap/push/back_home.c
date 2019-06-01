#include "push_swap.h"

void	rotate_orhome(t_stack **head_a, t_stack **head_b, int value, int div)
{
	int		flag;

	flag = 0;
	if (!*head_b)
		return ;
	while (check_ifin_buck(head_b, value) > 0)
	{
		if (!*head_b)
			break ;
		if (*head_a)
		{
			if ((((*head_b)->pstn / div) % 10) == 0 && ((*head_a)->buck - 1)
					== (*head_b)->buck)
				flag = 1;
		}
		if ((*head_b)->buck == value && flag == 0)
			push_a(head_a, head_b);
		else if (check_ifin_buck(head_b, value) > 0)
		{
			rotate_b(head_b);
			flag = 0;
		}
	}
}

void	reverse_orhome(t_stack **head_a, t_stack **head_b, int value, int div)
{
	int		flag;

	flag = 0;
	if (!*head_a)
		return ;
	while (check_ifin_buck(head_a, value) > 0)
	{
		if (!*head_a || in_order(head_a))
			break ;
		if ((((*head_a)->pstn / div) % 10) == 9
				&& ((*head_b)->buck + 1) == (*head_a)->buck)
			flag = 1;
		if ((*head_a)->buck == value && flag == 0)
			push_b(head_a, head_b);
		else if (check_ifin_buck(head_a, value) > 0)
		{
			rotate_a(head_a);
			flag = 0;
		}
	}
}
