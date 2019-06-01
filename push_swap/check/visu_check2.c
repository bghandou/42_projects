#include "push_swap.h"

void	visu_first_stack(t_stack **head_a, t_draw **info,
		SDL_Renderer *renderer)
{
	SDL_Rect	r0;
	double		nodes;
	t_stack		*tmp;
	int			clr;

	tmp = *head_a;
	nodes = count_nodes(head_a);
	clr = 0;
	while (tmp)
	{
		clr = tmp->nbr < 0 ? 100 : 0;
		r0.w = (*info)->wid * tmp->nbr;
		r0.x = (1024 / 4) - ((r0.w) / 2);
		r0.h = (*info)->hgt + 1;
		r0.y = 768 - (*info)->hgt * nodes;
		SDL_SetRenderDrawColor(renderer, 255 - clr / 2, 255 / (clr + 1)
				, 255 - clr / 4, 255);
		SDL_RenderDrawRect(renderer, &r0);
		SDL_RenderFillRect(renderer, &r0);
		tmp = tmp->next;
		nodes--;
	}
}

void	visu_scnd_stack(t_stack **head_b, t_draw **info,
		SDL_Renderer *renderer)
{
	SDL_Rect	r1;
	int			nodes;
	t_stack		*tmp;
	int			clr;

	tmp = *head_b;
	nodes = count_nodes(head_b);
	clr = 0;
	SDL_Delay((*info)->count);
	while (tmp)
	{
		clr = tmp->nbr < 0 ? 100 : 0;
		r1.w = (*info)->wid * tmp->nbr;
		r1.x = (768) - ((r1.w) / 2);
		r1.h = (*info)->hgt + 1;
		r1.y = 768 - (*info)->hgt * nodes;
		tmp = tmp->next;
		SDL_SetRenderDrawColor(renderer, 215 - clr, 0 + clr, 215 - clr, 255);
		SDL_RenderDrawRect(renderer, &r1);
		SDL_RenderFillRect(renderer, &r1);
		nodes--;
	}
}
