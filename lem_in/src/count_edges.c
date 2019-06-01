#include "../include/lem_in.h"

int		count_edges(t_node *room)
{
	int		i;

	i = -1;
	if (room->links)
	{
		while (room->links[++i])
			;
	}
	return (i);
}

int		count_iterations(t_node *head)
{
	t_node	*room;
	int		strt;
	int		end;

	room = get_start(head);
	strt = count_edges(room);
	room = get_end(head);
	end = count_edges(room);
	if (end < strt)
		return (end);
	else if (strt <= end)
		return (strt);
	return (0);
}

int		count_paths(t_node *start)
{
	int		i;
	int		n_paths;

	i = -1;
	n_paths = 0;
	while (start->links[++i])
	{
		if (start->flux[i] == 1)
			n_paths++;
	}
	return (n_paths);
}
