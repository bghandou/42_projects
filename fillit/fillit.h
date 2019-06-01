/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:14:09 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/15 17:12:34 by bghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define AVAILABLE 1
# define PLACED 0
# define LAST 2
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_tetrimino
{
	int	x[4];
	int	y[4];
	int	status;
}				t_tetrimino;

int				ft_check(char **square, int i, t_tetrimino current, int pos);
char			**ft_fill_square(char **square, t_tetrimino *cur, int pos,
		char letter);
char			**ft_erase_square(char **square, int i, char letter);
int				ft_algo(char ***square, t_tetrimino *file, int i, int position);
char			**ft_fillit(t_tetrimino *file);
char			**ft_init_square(int i);
void			ft_error_exit(void);
int				ft_abs(int a);
void			ft_normalize_coord(int stock_x[], int stock_y[],
		t_tetrimino **tet);
void			ft_map_coordinates(char *stock, t_tetrimino **tet);
int				ft_check_valid_board_2(char *stock);
void			ft_check_valid_board_1(char *stock, t_tetrimino **tet);
void			ft_stock_feed(char *feed, int ret, t_tetrimino **tet);
void			ft_store_valid_tetri(int stock_x[], int stock_y[],
		t_tetrimino **tet);
int				ft_return(t_tetrimino *file);
int				ft_sqrt(int nb);
void			ft_print_2dtable(char **tab);
void			ft_usage(void);
void			ft_count_neighbor(int stock_x[], int stock_y[],
		t_tetrimino **tet);
void			ft_square_del(char **square);

#endif
