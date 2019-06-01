#include "lem_in.h"

void	free_nodes(t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp->links != NULL)
		{
			free(tmp->links);
			tmp->links = NULL;
		}
		remove_path(tmp->hist);
		if (tmp->flux)
			free(tmp->flux);
		free(tmp->name);
		tmp->name = NULL;
		free(tmp);
		tmp = NULL;
	}
}
