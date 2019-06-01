#include "push_swap.h"

void	vis_reverse_a(t_stack **head_a)
{
	t_stack	*tmp1;
	t_stack	*tmp_lst;

	tmp1 = *head_a;
	if (!*head_a)
		return ;
	if (tmp1 && tmp1->next)
	{
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp_lst = tmp1->next;
		tmp_lst->next = *head_a;
		tmp1->next = NULL;
		*head_a = tmp_lst;
	}
}

void	vis_reverse_b(t_stack **head_b)
{
	t_stack	*tmp1;
	t_stack	*tmp_lst;

	if (!*head_b)
		return ;
	tmp1 = *head_b;
	if (tmp1 && tmp1->next)
	{
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp_lst = tmp1->next;
		tmp_lst->next = *head_b;
		tmp1->next = NULL;
		*head_b = tmp_lst;
	}
}

void	vis_reverse_both(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp1;
	t_stack	*tmp_lst;

	if (*head_a && (*head_a)->next)
	{
		tmp1 = *head_a;
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp_lst = tmp1->next;
		tmp_lst->next = *head_a;
		tmp1->next = NULL;
		*head_a = tmp_lst;
	}
	tmp1 = NULL;
	tmp_lst = NULL;
	if (*head_b && (*head_b)->next)
	{
		tmp1 = *head_b;
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp_lst = tmp1->next;
		tmp_lst->next = *head_b;
		tmp1->next = NULL;
		*head_b = tmp_lst;
	}
}
