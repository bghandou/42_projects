#include "push_swap.h"

void	fill_bucket(t_stack **head, int div)
{
	t_stack		*tmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp)
	{
		tmp->buck = (tmp->pstn / div) % 10;
		tmp = (tmp)->next;
	}
}

void	choose_path(t_stack **head_a, t_stack **head_b)
{
	t_stack *tmp_a;
	int		div;
	int		value;
	int		exp;
	int		nodes;

	tmp_a = *head_a;
	div = 1;
	value = 0;
	exp = exp_max(head_a);
	nodes = count_nodes(head_a);
	if (exp >= 1)
	{
		fill_bucket(head_a, div);
		rotate_ornot(head_a, head_b);
		value = 9;
		fill_bucket(head_b, div * 10);
		while (value >= 0)
		{
			rotate_orhome(head_a, head_b, value, div);
			value--;
		}
	}
	choose_path2(head_a, head_b, value, div);
}

void	choose_path2(t_stack **head_a, t_stack **head_b, int value, int div)
{
	int	exp;
	int	nodes;

	exp = exp_max(head_a);
	nodes = count_nodes(head_a);
	while (exp >= 3)
	{
		div *= 10;
		fill_bucket(head_a, div * 10);
		while (value <= 9)
		{
			if (*head_a && (*head_a)->pstn == nodes - 1)
				rotate_a(head_a);
			in_order(head_a) ? value = 9 : 0;
			reverse_orhome(head_a, head_b, value, div);
			value++;
		}
		fill_bucket(head_a, div * 10);
		while (value >= 0)
		{
			rotate_orhome(head_a, head_b, value, div);
			value--;
		}
		exp--;
	}
}

void	rotate_ornot(t_stack **head_a, t_stack **head_b)
{
	int		a;
	int		b;

	a = 5;
	b = 4;
	if (!*head_a)
		return ;
	while ((check_ifin_buck(head_a, a) || check_ifin_buck(head_a, b)))
	{
		while ((*head_a) && (*head_a)->buck == a)
		{
			push_b(head_a, head_b);
			check_ifin_buck(head_a, a) ? 1 : a++;
		}
		while ((*head_a) && (*head_a)->buck == b)
		{
			push_b(head_a, head_b);
			check_ifin_buck(head_a, b) ? 1 : b--;
			rotate_b(head_b);
		}
		if (check_ifin_buck(head_a, a) || check_ifin_buck(head_a, b))
			rotate_a(head_a);
	}
}

void	free_nodes(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	while (*head_a)
	{
		tmp_a = *head_a;
		*head_a = (*head_a)->next;
		free(tmp_a);
	}
	while (*head_b)
	{
		tmp_b = *head_b;
		*head_b = (*head_b)->next;
		free(tmp_b);
	}
}
