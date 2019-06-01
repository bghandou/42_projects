#ifndef VISU_H
# define VISU_H

# include "lem_in.h"
# include "haflib.h"
# include <SDL2/SDL.h>
# include <time.h>

# define SIZE 50
# define STEP 1
# define TIME_MOV 1000
# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440

typedef struct		s_visu
{
	t_ant			*ants;
	t_node			*start;
	t_node			*end;
	int				ant;
	int				size;
	SDL_Window		*win;
	SDL_Renderer	*ren;
}					t_visu;

int					sdl_start(t_visu *var, int width, int height);
void				sdl_end(SDL_Window *win, SDL_Renderer *ren);
int					height_map(t_node *head);
int					width_map(t_node *head);
void				draw(t_node *head, t_visu *var, int *table);
t_node				*next_path(t_node *current);
t_ant				*allocate_ants(long ant_nb, t_node *end);
int					remaining_space(int *table, t_node *start, int mode);
int					update_ants(t_ant *ants, t_node *head, int *table,
	int options);
void				free_ants(t_ant *head);
int					flux_value(t_node *node, char *name);
int					update_finished(int finished, long next_ant_index);

#endif
