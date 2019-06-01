#include "visu.h"

static void	draw_ants(t_node *head, t_visu *var, int *table)
{
	t_ant		*ants;
	SDL_Rect	ant;
	static int	i = 1;

	head = NULL;
	table = NULL;
	ant.w = var->size / 4;
	ant.h = var->size / 4;
	ants = var->ants;
	while (ants)
	{
		if (ants->room->role != END)
		{
			ant.x = (ants->room->x * var->size) - (var->size / 8);
			ant.y = (ants->room->y * var->size) - (var->size / 8);
			SDL_SetRenderDrawColor(var->ren, ants->color % 0xff00000, 0,
				ants->color % 0x0000ff, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawRect(var->ren, &ant);
			SDL_RenderFillRect(var->ren, &ant);
		}
		ants = ants->next;
	}
	i == STEP ? i = 1 : i++;
}

static void	draw_grid(SDL_Renderer *ren, int size)
{
	int	width;
	int	height;
	int	x;
	int	y;

	x = 0;
	y = 0;
	SDL_GetRendererOutputSize(ren, &width, &height);
	SDL_SetRenderDrawColor(ren, 50, 50, 50, 255);
	while (x <= width)
	{
		SDL_RenderDrawLine(ren, x, 0, x, height);
		x += size;
	}
	while (y <= height)
	{
		SDL_RenderDrawLine(ren, 0, y, width, y);
		y += size;
	}
}

static void	draw_links(t_node *head, SDL_Renderer *ren, int size)
{
	int		i;

	while (head)
	{
		i = 0;
		if (!head || !head->links || !head->flux)
		{
			head = head->next;
			continue ;
		}
		while (head->links[i] != NULL)
		{
			if (head->flux[i] == 1 || flux_value(head->links[i], head->name))
				SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
			else
				SDL_SetRenderDrawColor(ren, 50, 100, 90, 200);
			SDL_RenderDrawLine(ren, head->x * size, head->y * size,
				head->links[i]->x * size, head->links[i]->y * size);
			i++;
		}
		head = head->next;
	}
}

void		draw_map(t_node *head, SDL_Renderer *ren, int size)
{
	SDL_Rect	node;

	node.w = size / 2;
	node.h = size / 2;
	while (head)
	{
		if (head->role == START)
			SDL_SetRenderDrawColor(ren, 20, 20, 240, 255);
		else if (head->role == END)
			SDL_SetRenderDrawColor(ren, 210, 20, 20, 255);
		else
			SDL_SetRenderDrawColor(ren, 170, 170, 170, 255);
		node.x = (head->x * size) - (size / 4);
		node.y = (head->y * size) - (size / 4);
		SDL_RenderDrawRect(ren, &node);
		SDL_RenderFillRect(ren, &node);
		head = head->next;
	}
}

void		draw(t_node *head, t_visu *var, int *table)
{
	int		i;

	i = 0;
	while (i < STEP)
	{
		SDL_SetRenderDrawColor(var->ren, 0, 0, 0, 255);
		SDL_RenderClear(var->ren);
		draw_grid(var->ren, var->size);
		draw_links(head, var->ren, var->size);
		draw_map(head, var->ren, var->size);
		draw_ants(head, var, table);
		SDL_RenderPresent(var->ren);
		SDL_Delay(TIME_MOV / STEP);
		i++;
	}
}
