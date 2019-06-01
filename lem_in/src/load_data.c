#include "lem_in.h"

static int		valid_start_end(t_node *head)
{
	int		start;
	int		end;
	t_node	*mem;

	start = 0;
	end = 0;
	mem = head;
	while (head)
	{
		if (head->role == 1)
			start++;
		if (head->role == 2)
			end++;
		head = head->next;
	}
	if (end != 1 || start != 1)
	{
		free_nodes(mem);
		return (return_("Error in start and end (missing or duplicated)"));
	}
	return (1);
}

static char		*load_raw_data(char *file_name, int argc)
{
	int		fd;
	char	*raw_data;

	if ((argc == 2 && file_name[0] != '-') || argc == 3)
	{
		if ((fd = open(file_name, O_RDONLY)) == -1)
			return ((char *)return_("Failed to open the file"));
	}
	else
		fd = 0;
	if (!(raw_data = get_the_file(fd)))
		return ((char *)return_("Failed to read the file"));
	return (raw_data);
}

t_node			*load_map(int argc, char **argv, long *ant_nb, int options)
{
	char	*raw_data;
	t_node	*head;

	if (!(raw_data = load_raw_data(argv[argc - 1], argc)))
		return (NULL);
	if (!(verify_data(raw_data)))
	{
		free(raw_data);
		return (NULL);
	}
	if (!(head = load_structure(raw_data, ant_nb)))
	{
		free(raw_data);
		return (NULL);
	}
	if (!(options & SILENT))
		ft_printf("%s\n", raw_data);
	free(raw_data);
	if (!(valid_start_end(head)))
		return (NULL);
	return (head);
}
