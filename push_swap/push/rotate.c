#include "push_swap.h"

void	rotate_a(t_stack **head_a)
{
	t_stack	*tmp1;
	t_stack *tmp_lst;

	if (*head_a && (*head_a)->next)
	{
		tmp1 = *head_a;
		*head_a = (*head_a)->next;
		tmp_lst = *head_a;
		while (tmp_lst->next != NULL)
			tmp_lst = tmp_lst->next;
		tmp_lst->next = tmp1;
		tmp1->next = NULL;
	}
	ft_putendl("ra");
}

void	rotate_b(t_stack **head_b)
{
	t_stack	*tmp1;
	t_stack *tmp_lst;

	if (*head_b && (*head_b)->next)
	{
		tmp1 = *head_b;
		*head_b = (*head_b)->next;
		tmp_lst = *head_b;
		while (tmp_lst->next != NULL)
			tmp_lst = tmp_lst->next;
		tmp_lst->next = tmp1;
		tmp1->next = NULL;
	}
	ft_putendl("rb");
}

void	rotate_both(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp1;
	t_stack *tmp_lst;

	if (*head_a && (*head_a)->next)
	{
		tmp1 = *head_a;
		*head_a = (*head_a)->next;
		tmp_lst = *head_a;
		while (tmp_lst->next != NULL)
			tmp_lst = tmp_lst->next;
		tmp_lst->next = tmp1;
		tmp1->next = NULL;
	}
	if (*head_b && (*head_b)->next)
	{
		tmp1 = *head_b;
		*head_b = (*head_b)->next;
		tmp_lst = *head_b;
		while (tmp_lst->next != NULL)
			tmp_lst = tmp_lst->next;
		tmp_lst->next = tmp1;
		tmp1->next = NULL;
	}
	ft_putendl("rr");
}
