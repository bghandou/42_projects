#include "push_swap.h"

t_stack	*take_string(char **av)
{
	int		i;
	char	**str;
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*new;

	i = 0;
	head = NULL;
	str = ft_strsplit(av[1], ' ');
	check_digit_string(str);
	if (!ft_strlen(str[0]))
		exit(EXIT_FAILURE);
	tmp = create_list(ft_atoi_swp(str[0], &head));
	head = tmp;
	while (str[++i] != '\0')
	{
		new = add_list(ft_atoi_swp(str[i], &head));
		tmp->next = new;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	free_string_args(str);
	return (head);
}

t_stack	*take_list(int ac, char **av)
{
	t_stack	*tmp;
	t_stack	*head;
	t_stack	*new;
	int		i;

	head = NULL;
	check_digit_args(ac, av);
	tmp = create_list(ft_atoi_swp(av[1], &head));
	head = tmp;
	i = 2;
	while (i < ac)
	{
		new = add_list(ft_atoi_swp(av[i], &head));
		tmp->next = new;
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	return (head);
}

void	launch_process(t_stack **head_a, t_stack **head_b)
{
	int		nodes;

	define_pstn(head_a);
	nodes = count_nodes(head_a);
	if (in_order(head_a) && !*head_b)
		return ;
	if (nodes == 3)
		tiny_arg(head_a);
	else if (nodes <= 10)
	{
		define_pstn(head_a);
		small_arg(head_a, head_b);
	}
	else
		choose_path(head_a, head_b);
}

int		main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		head_a = take_string(av);
	else
		head_a = take_list(ac, av);
	check_if_doubloons(&head_a, 0);
	launch_process(&head_a, &head_b);
	free_nodes(&head_a, &head_b);
}
