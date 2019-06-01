#ifndef LEM_IN_H
# define LEM_IN_H

# include "haflib.h"
# include "fcntl.h"
# include <limits.h>

# define VISU 2
# define COUNT 4
# define COLOR 8
# define SILENT 16

# define START		1
# define END		2
# define OPEN		1
# define CLSD		0
# define VISITED	1
# define FREE		0

/*
**	Role : (0 = node; 1 = start; 2 = end)
*/
typedef struct		s_node
{
	struct s_node	**links;
	struct s_node	*next;
	struct s_path	*hist;
	char			*name;
	int				role;
	int				access;
	int				vzt;
	int				*flux;
	int				weight;
	int				skip;
	int				x;
	int				y;
	int				tag;
}					t_node;

typedef struct		s_path
{
	struct s_path	*prev;
	t_node			*room;
	struct s_path	*next;
}					t_path;

typedef struct		s_ant
{
	struct s_ant	*next;
	t_node			*room;
	int				nb;
	int				color;
}					t_ant;

/*
**	PARSING FUNCTIONS
*/
t_node				*load_map(int argc, char **argv, long *ant_nb, int options);
t_node				*load_structure(char *data, long *ant_nb);
t_node				*add_node(t_node *head, char *line, int pos);
void				free_nodes(t_node *head);
t_node				*get_node(char *name, size_t len, t_node *head);
int					alloc_links_list(t_node *node, t_node *link);
int					verify_data(char *data);
int					basic_solver(t_node *head);
int					load_links(t_node *head, char *data);
int					is_linked(t_node *node, t_node *node2);
int					create_link(t_node *node1, t_node *node2);
/*
** NODE MANIPULATION UTILS
*/
t_node				*get_start(t_node *head);
t_node				*get_end(t_node *head);
t_node				*get_node(char *name, size_t len, t_node *head);
t_node				*get_next_open_link(t_node *node);
void				reset_nodes(t_node *head);

void				reinit_all(t_node *head);

/*
** PATH MANIPULATION UTILS
*/

void				closed_access_case(t_node **room, t_path **vzt_nxt, int idx,
	t_path **reinit);
void				closed_access_case2(t_node *nxt_room, t_path **vzt_nxt,
	t_path **reinit, int i);

/*
** PATH MANIPULATION UTILS
*/
t_path				*new_path(t_node *node);
int					add_path(t_node *node, t_path *path);
void				remove_path(t_path *path);
int					solver(t_node *head);

t_path				*copy_path(t_path *path);

t_path				*new_path(t_node *node);
int					add_path(t_node *node, t_path *path);
t_path				*deprecate_first(t_path **path, t_path *deprecated);
void				reinit_visited(t_path **history);
int					compare_weights(t_node **room, int idx);
int					skip_from_close(t_node **room, int idx);
int					check_outwardflux(t_node **room);
int					check_path_skip(t_node *node, t_path *path,
	t_path **reinit);

/*
** FLUX MANIPULATION UTILS
*/

int					find_index(t_node *prev, t_node *next);
int					reverse_flux_case(t_node *room, int idx);
void				adjust_reverse_flux(t_node **room, int idx);
void				create_flux(t_node **room);

/*
** BFS
*/

void				closed_access_case(t_node **room, t_path **vzt_nxt,
	int idx, t_path **reinit);
void				fill_vzt_path(t_node **room, t_node *nxt_room,
	t_path **vzt_nxt, int i);
t_node				*build_path(t_node *room, int i);
t_path				*visit_paths(t_node **room, t_path **vzt_nxt,
	t_path *reinit);
int					flux_to_end(t_node **room, t_path **vzt_nxt, int i,
	t_node *head);
t_node				*build_path(t_node *room, int i);

/*
** PATH PHASE
*/
int					*test_function(t_node *head, long ant_nb, int *loops);
void				shortest_path(t_node **room, t_node *head);

void				print_nodes(t_node *head);
void				print_path_test(t_path *head);
void				print_path_final(t_path *head);
void				print_flux(t_node *room);

int					test_flux(t_node *room);

/*
**	LAST DISPLAY
*/

int					display_end(t_node *head, long ant_nb, int *table,
	int params);
int					display_end_visu(t_node *head, long ant_nb, int *table,
	int params);
/*
** TESTNG PHASE
*/

int					count_edges(t_node *room);
int					count_paths(t_node *start);
int					count_iterations(t_node *head);

/*
** EQUATION
*/

int					path_length(t_node *start);
int					*solve_equation(int n_paths, int *table, long ant_nb,
	int total_len);
int					*calc_paths(t_node *start, int ant_nb);
int					check_viability(int *table, int ant_nb, t_node *head);
int					reset_or_not(int *table, int ant_nb, t_node **head);
void				flux_or_tag(t_node *start, int actv);
void				fill_remaining(int *table, long ant_nb);
void				check_startend(int *table, long ant_nb, t_node *start);
int					*save_table(int *table);
int					compare_tables(int *table, int *prv_tbl);

#endif
