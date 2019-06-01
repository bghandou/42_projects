#include "push_swap.h"

void	c_swap_a(t_stack **head_a)
{
	t_stack	*tmp1_a;
	t_stack	*tmp2_a;

	if (*head_a && (*head_a)->next)
	{
		tmp1_a = *head_a;
		*head_a = tmp1_a->next;
		tmp2_a = tmp1_a->next->next;
		(*head_a)->next = tmp1_a;
		tmp1_a->next = tmp2_a;
		tmp1_a = NULL;
		tmp2_a = NULL;
	}
}

void	c_swap_b(t_stack **head_b)
{
	t_stack	*tmp1_b;
	t_stack	*tmp2_b;

	if (*head_b && (*head_b)->next)
	{
		tmp1_b = *head_b;
		*head_b = tmp1_b->next;
		tmp2_b = tmp1_b->next->next;
		(*head_b)->next = tmp1_b;
		tmp1_b->next = tmp2_b;
	}
}

void	c_swap_both(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*head_a && (*head_a)->next)
	{
		tmp1 = *head_a;
		*head_a = tmp1->next;
		tmp2 = tmp1->next->next;
		(*head_a)->next = tmp1;
		tmp1->next = tmp2;
	}
	tmp1 = NULL;
	tmp2 = NULL;
	if (*head_b && (*head_b)->next)
	{
		tmp1 = *head_b;
		*head_b = tmp1->next;
		tmp2 = tmp1->next->next;
		(*head_b)->next = tmp1;
		tmp1->next = tmp2;
	}
}

void	c_push_a(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp_a;

	if (*head_b)
	{
		tmp_a = *head_a;
		*head_a = *head_b;
		*head_b = (*head_b)->next;
		(*head_a)->next = tmp_a;
	}
}

void	c_push_b(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp_b;

	if (*head_a)
	{
		tmp_b = *head_b;
		*head_b = *head_a;
		*head_a = (*head_a)->next;
		(*head_b)->next = tmp_b;
	}
}
