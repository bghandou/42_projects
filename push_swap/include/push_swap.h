#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdint.h>
# include "libft.h"
# include <SDL2/SDL.h>

typedef struct	s_stack
{
	int				nbr;
	int				pstn;
	int				buck;
	int				ismax;
	int				mx_exp;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_draw
{
	double	wid;
	double	hgt;
	int		count;
}				t_draw;

void			launch_process(t_stack **head_a, t_stack **head_b);
t_stack			*take_list(int ac, char **av);
t_stack			*take_string(char **av);
t_stack			*create_list(int nbr);
t_stack			*add_list(int nbr);
int				read_act(t_stack **head_a, t_stack **head_b, char *act);
void			c_swap_a(t_stack **head_a);
void			c_swap_b(t_stack **head_b);
void			c_swap_both(t_stack **head_a, t_stack **head_b);
void			c_push_a(t_stack **head_a, t_stack **head_b);
void			c_push_b(t_stack **head_a, t_stack **head_b);
void			c_rotate_a(t_stack **head_a);
void			c_rotate_b(t_stack **head_b);
void			c_rotate_both(t_stack **head_a, t_stack **head_b);
void			c_reverse_a(t_stack **head_a);
void			c_reverse_b(t_stack **head_b);
void			c_reverse_both(t_stack **head_a, t_stack **head_b);
int				read_act_vis(t_stack **head_a, t_stack **head_b, char *act);
void			vis_swap_a(t_stack **head_a);
void			vis_swap_b(t_stack **head_b);
void			vis_swap_both(t_stack **head_a, t_stack **head_b);
void			vis_push_a(t_stack **head_a, t_stack **head_b);
void			vis_push_b(t_stack **head_a, t_stack **head_b);
void			vis_rotate_a(t_stack **head_a);
void			vis_rotate_b(t_stack **head_b);
void			vis_rotate_both(t_stack **head_a, t_stack **head_b);
void			vis_reverse_a(t_stack **head_a);
void			vis_reverse_b(t_stack **head_b);
void			vis_reverse_both(t_stack **head_a, t_stack **head_b);
void			check_digit_string(char **str);
void			check_digit_args(int ac, char **av);
void			check_digit_string2(char **str);
void			check_digit_args2(int ac, char **av, int flag);
void			swap_a(t_stack **head_a);
void			swap_b(t_stack **head_b);
void			swap_both(t_stack **head_a, t_stack **head_b);
void			push_a(t_stack **head_a, t_stack **head_b);
void			push_b(t_stack **head_a, t_stack **head_b);
void			rotate_a(t_stack **head_a);
void			rotate_b(t_stack **head_b);
void			rotate_both(t_stack **head_a, t_stack **head_b);
void			reverse_a(t_stack **head_a);
void			reverse_b(t_stack **head_b);
void			reverse_both(t_stack **head_a, t_stack **head_b);
void			fill_bucket(t_stack **head, int div);
void			ismax(t_stack **head_a);
int				count_nodes(t_stack **head);
int				check_ifin_buck(t_stack **head, int val);
void			rotate_ornot(t_stack **head_a, t_stack **head_b);
void			swap_a_ornot(t_stack **head_a, t_stack **head_b, int value);
void			choose_path(t_stack **head_a, t_stack **head_b);
void			choose_path2(t_stack **head_a, t_stack **head_b,
		int value, int div);
void			rotate_orhome(t_stack **head_a, t_stack **head_b,
		int value, int div);
void			define_pstn(t_stack **head_a);
int				exp_max(t_stack **head);
void			reverse_orhome(t_stack **head_a, t_stack **head_b,
		int value, int div);
int				relative_position(t_stack **head, int val);
void			insert_nodes(t_stack **head_a, t_stack **head_b,
		int value, int shft);
void			small_arg(t_stack **head_a, t_stack **head_b);
void			small_arg2(t_stack **head_a);
int				in_order(t_stack **head);
void			tiny_arg(t_stack **head_a);
void			free_nodes(t_stack **head_a, t_stack **head_b);
void			free_nodes_er(t_stack **head_a, t_stack **head_b, int err);
int				free_nodes_er2(t_stack **head_a, t_stack **head_b, int err);
void			free_string_args(char **str);
void			free_string_args2(char **str);
t_stack			*take_list_check(int ac, char **av, int flag);
void			check_check(t_stack **head_a, t_stack **head_b);
void			read_it(t_stack **head_a, t_stack **head_b);
int				visu_init(t_stack **head_a, t_stack **head_b);
void			visu_init2(t_stack **head_a, t_stack **head_b,
		SDL_Renderer *renderer, t_draw **info);
void			visu_background(t_stack **head_a, t_stack **head_b,
			SDL_Renderer *renderer, t_draw **info);
void			visu_draw_rec(t_stack **head_a, t_stack **head_b,
		SDL_Renderer *renderer, t_draw **info);
void			visu_first_stack(t_stack **head_a,
		t_draw **info, SDL_Renderer *renderer);
void			visu_scnd_stack(t_stack **head_b,
		t_draw **info, SDL_Renderer *renderer);
void			adjustments_draw(t_stack **head_a, t_draw **info);
int				ft_atoi_swp(const char *str, t_stack **head_a);
int				invalid_atoi(const char *str, t_stack **head, int *i, int neg);
void			check_if_doubloons(t_stack **head, int count);

#endif
