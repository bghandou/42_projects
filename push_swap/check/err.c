#include "push_swap.h"

void	free_nodes_er(t_stack **head_a, t_stack **head_b, int err)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
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
	if (err == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

int		free_nodes_er2(t_stack **head_a, t_stack **head_b, int err)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
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
	if (err == 1)
		return (1);
	return (0);
}
