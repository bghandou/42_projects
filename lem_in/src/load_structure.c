#include "lem_in.h"

static t_node	*load_nodes(char *data, size_t *i)
{
	t_node	*head;
	size_t	j;
	int		pos;

	head = NULL;
	pos = 0;
	while (data[*i])
	{
		j = 0;
		while (data[*i + j] != '\n' && data[*i + j])
			j++;
		if (ft_memchr(&data[*i], ' ', j) == NULL && data[*i] != '#')
			break ;
		(ft_memcmp(&data[*i], "##start\n", 8) == 0) ? pos = 1 : 0;
		(ft_memcmp(&data[*i], "##end\n", 6) == 0) ? pos = 2 : 0;
		if (data[*i] != '#')
		{
			if (!(head = add_node(head, &data[*i], pos)))
				return (NULL);
			pos = 0;
		}
		*i = *i + j + 1;
	}
	return (head);
}

t_node			*load_structure(char *data, long *ant_nb)
{
	size_t	i;
	t_node	*head;

	i = 0;
	while (data[i] == '#')
	{
		while (data[i] != '\n' && data[i])
			i++;
		i++;
	}
	*ant_nb = ft_strtoll(&data[i], &i);
	i++;
	if (!(head = load_nodes(data, &i)))
		return ((t_node *)return_("Failed to load nodes"));
	if (!(load_links(head, &data[i])))
	{
		return (0);
	}
	return (head);
}
