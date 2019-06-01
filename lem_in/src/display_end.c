#include "lem_in.h"
#include "visu.h"

t_node	*next_path(t_node *current)
{
	int i;

	i = 0;
	if (current->role == END)
		return (NULL);
	while (current->links[i])
	{
		if (current->links[i]->role == END)
			return (current->links[i]);
		if (current->flux[i] == 1 && current->links[i]->access == 1)
			return (current->links[i]);
		i++;
	}
	return (NULL);
}

void	print_path(t_ant *ants, t_node *next, int options, t_node *head)
{
	if (options & COLOR)
	{
		if (next->role == END)
			ft_printf("%sL%d%s-%s%s%s", YELLOW, ants->nb, DEF, RED,
				next->name, DEF);
		else if (!is_linked(next, get_start(head)))
			ft_printf("%sL%d%s-%s%s%s", YELLOW, ants->nb, DEF, GREEN,
				next->name, DEF);
		else
			ft_printf("%sL%d%s-%s%s%s", YELLOW, ants->nb, DEF, BLUE,
				next->name, DEF);
	}
	else
		ft_printf("L%d-%s", ants->nb, next->name);
}

int		access_room(t_ant *ants, int *table, int options, t_node *head)
{
	t_node		*start;
	t_node		*end;
	t_node		*next;

	end = get_end(head);
	start = get_start(head);
	if (ants->room == start && start->access == 1)
		next = ants->room->links[remaining_space(table, start, 1)];
	else
		next = next_path(ants->room);
	print_path(ants, next, options, head);
	ants->room->access = 1;
	ants->room = next;
	if (next != end)
		ants->room->access = 0;
	return (1);
}

int		update_ants(t_ant *ants, t_node *head, int *table, int options)
{
	static long	next_ant_index = 0;
	int			finished;
	t_node		*start;
	t_node		*end;

	finished = 1;
	end = get_end(head);
	start = get_start(head);
	while (ants)
	{
		if (ants->room == end && remaining_space(table, start, 0) != -1)
		{
			finished = 0;
			ants->room = start;
			ants->nb = ++next_ant_index;
		}
		if (ants->room != end && (ants->room != start || remaining_space(table,
			start, 0) != -1) && next_path(ants->room))
		{
			finished = update_finished(finished, next_ant_index);
			access_room(ants, table, options, head);
		}
		ants = ants->next;
	}
	return (finished);
}

int		display_end(t_node *head, long ant_nb, int *table, int options)
{
	t_ant	*ants;
	int		ant;
	int		count;

	ant = 0;
	count = 0;
	reset_nodes(head);
	if (table == NULL)
		return (0);
	if (!(ants = allocate_ants(ant_nb, get_end(head))))
		return (0);
	while (update_ants(ants, head, table, options) == 0)
	{
		write(1, "\n", 1);
		count++;
	}
	if (options & COUNT)
		ft_printf("\n%sFINAL%s : %d\n", RED, DEF, count);
	free_ants(ants);
	return (1);
}
