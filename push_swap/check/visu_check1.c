#include <SDL2/SDL.h>
#include "push_swap.h"

void	adjustments_draw(t_stack **head_a, t_draw **info)
{
	double	nodes;
	t_stack	*tmp;
	int		max;

	tmp = *head_a;
	max = 0;
	nodes = count_nodes(head_a);
	ismax(head_a);
	if (nodes <= 15)
		(*info)->count = 500;
	else if (nodes <= 100)
		(*info)->count = 7;
	else
		(*info)->count = 0;
	if (nodes)
		(*info)->hgt = 768 / nodes;
	while (tmp)
	{
		if (tmp->ismax == 1)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	if (max)
		(*info)->wid = 512 / (double)max;
}

int		visu_init(t_stack **head_a, t_stack **head_b)
{
	t_draw			*info;
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("push_swap", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
	if (!window || !renderer)
		return (0);
	if (!(info = (t_draw*)malloc(sizeof(t_draw))))
		return (0);
	adjustments_draw(head_a, &info);
	define_pstn(head_a);
	visu_init2(head_a, head_b, renderer, &info);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	free(info);
	SDL_Quit();
	return (0);
}

void	visu_init2(t_stack **head_a, t_stack **head_b, SDL_Renderer *renderer,
		t_draw **info)
{
	char		*line;
	static int	q;

	line = NULL;
	while (!q)
	{
		while (get_next_line(0, &line) > 0 && !q)
		{
			q = read_act_vis(head_a, head_b, line);
			visu_background(head_a, head_b, renderer, info);
			if (q)
				free_nodes_er(head_a, head_b, 1);
			free(line);
		}
		SDL_Delay(3000);
		q = 1;
		check_check(head_a, head_b);
	}
}

void	visu_background(t_stack **head_a, t_stack **head_b,
		SDL_Renderer *renderer, t_draw **info)
{
	SDL_Rect	half;

	half.x = 512;
	half.y = 0;
	half.w = 512;
	half.h = 768;
	SDL_SetRenderDrawColor(renderer, 100, 10, 200, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &half);
	visu_draw_rec(head_a, head_b, renderer, info);
}

void	visu_draw_rec(t_stack **head_a, t_stack **head_b,
		SDL_Renderer *renderer, t_draw **info)
{
	visu_first_stack(head_a, info, renderer);
	visu_scnd_stack(head_b, info, renderer);
	SDL_RenderPresent(renderer);
}
