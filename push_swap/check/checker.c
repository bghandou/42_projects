#include "push_swap.h"

t_stack	*take_string(char **av)
{
	int		i;
	char	**str;
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*new;

	str = NULL;
	head = NULL;
	i = 0;
	str = (ft_strcmp(av[1], "-v") == 0) ? ft_strsplit(av[2], ' ')
		: ft_strsplit(av[1], ' ');
	check_digit_string2(str);
	if (!str || !ft_strlen(str[0]))
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
	free_string_args2(str);
	return (head);
}

t_stack	*take_list_check(int ac, char **av, int flag)
{
	t_stack	*tmp;
	t_stack	*head;
	t_stack	*new;
	int		i;

	head = NULL;
	check_digit_args2(ac, av, flag);
	tmp = create_list(ft_atoi_swp(av[1 + flag], &head));
	head = tmp;
	i = 2 + flag;
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

void	check_check(t_stack **head_a, t_stack **head_b)
{
	define_pstn(head_a);
	if (*head_a)
	{
		if (in_order(head_a) && !*head_b)
		{
			ft_putendl("OK");
			free_nodes_er(head_a, head_b, 0);
		}
		else
		{
			ft_putendl("KO");
			free_nodes_er(head_a, head_b, 0);
		}
	}
}

void	read_it(t_stack **head_a, t_stack **head_b)
{
	char	*line;
	int		exit;

	line = NULL;
	exit = 0;
	while (get_next_line(0, &line) > 0 && !exit)
	{
		exit = read_act(head_a, head_b, line);
		free(line);
		if (exit)
			break ;
	}
	if (exit)
		free_nodes_er(head_a, head_b, 1);
}

int		main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	char	*line;
	int		flag;

	head_a = NULL;
	head_b = NULL;
	line = NULL;
	flag = 0;
	if (ac < 2)
		return (0);
	if (ac >= 3 && ft_strcmp(av[1], "-v") == 0)
		flag = 1;
	if ((ac == 2 && flag == 0) || (ac == 3 && flag == 1))
		head_a = take_string(av);
	else
		head_a = take_list_check(ac, av, flag);
	check_if_doubloons(&head_a, 0);
	if (flag == 1)
		visu_init(&head_a, &head_b);
	else if (flag == 0)
		read_it(&head_a, &head_b);
	check_check(&head_a, &head_b);
	free_nodes_er(&head_a, &head_b, 0);
}
