#include "push_swap.h"

int		read_act(t_stack **head_a, t_stack **head_b, char *act)
{
	if (!ft_strcmp(act, "sa"))
		c_swap_a(head_a);
	else if (!ft_strcmp(act, "sb"))
		c_swap_b(head_b);
	else if (!ft_strcmp(act, "ss"))
		c_swap_both(head_a, head_b);
	else if (!ft_strcmp(act, "pa"))
		c_push_a(head_a, head_b);
	else if (!ft_strcmp(act, "pb"))
		c_push_b(head_a, head_b);
	else if (!ft_strcmp(act, "ra"))
		c_rotate_a(head_a);
	else if (!ft_strcmp(act, "rb"))
		c_rotate_b(head_b);
	else if (!ft_strcmp(act, "rr"))
		c_rotate_both(head_a, head_b);
	else if (!ft_strcmp(act, "rra"))
		c_reverse_a(head_a);
	else if (!ft_strcmp(act, "rrb"))
		c_reverse_b(head_b);
	else if (!ft_strcmp(act, "rrr"))
		c_reverse_both(head_a, head_b);
	else
		return (free_nodes_er2(head_a, head_b, 1));
	return (0);
}

int		read_act_vis(t_stack **head_a, t_stack **head_b, char *act)
{
	if (!ft_strcmp(act, "sa"))
		vis_swap_a(head_a);
	else if (!ft_strcmp(act, "sb"))
		vis_swap_b(head_b);
	else if (!ft_strcmp(act, "ss"))
		vis_swap_both(head_a, head_b);
	else if (!ft_strcmp(act, "pa"))
		vis_push_a(head_a, head_b);
	else if (!ft_strcmp(act, "pb"))
		vis_push_b(head_a, head_b);
	else if (!ft_strcmp(act, "ra"))
		vis_rotate_a(head_a);
	else if (!ft_strcmp(act, "rb"))
		vis_rotate_b(head_b);
	else if (!ft_strcmp(act, "rr"))
		vis_rotate_both(head_a, head_b);
	else if (!ft_strcmp(act, "rra"))
		vis_reverse_a(head_a);
	else if (!ft_strcmp(act, "rrb"))
		vis_reverse_b(head_b);
	else if (!ft_strcmp(act, "rrr"))
		vis_reverse_both(head_a, head_b);
	else
		return (free_nodes_er2(head_a, head_b, 1));
	return (0);
}
