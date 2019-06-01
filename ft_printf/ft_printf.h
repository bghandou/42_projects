/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bghandou <bghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:29:46 by bghandou          #+#    #+#             */
/*   Updated: 2019/01/25 09:46:25 by bghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

typedef struct	s_args
{
	char			*s;
	char			c;
	intmax_t		i;
	size_t			u;
	long double		f;
	char			plus;
	char			hash;
	char			space;
	char			dot;
	char			star;
	char			zero;
	char			minus;
	int				pad_l;
	int				prec;
	char			*data_mod;
	char			*data_type;
	char			*modif;
	char			*modif_clean;
	char			*x;
	size_t			char_cnt;
}				t_args;

void			initialize_structure(t_args *list, const char *restrict format);
void			print_string(t_args *list);
void			error_fctn(t_args list);
int				ft_printf(const char *restrict format, ...);
int				primary_flags(const char *restrict format,
		va_list ap, t_args *list);
int				primary_flags_2(const char *restrict format, va_list ap,
	t_args *list, int len);
t_args			padding_length(t_args list, const char *format,
		int *add, va_list ap);
t_args			check_prec_flag(const char *format,
		t_args list, int *add, va_list ap);
t_args			check_type_1(t_args list,
		const char *restrict format, va_list ap);
t_args			check_type_2(t_args list,
		const char *restrict format, va_list ap);
t_args			check_type_3(t_args list,
		const char *restrict format, va_list ap);
t_args			perc_case(t_args list);
t_args			p_case(t_args list, va_list ap);
t_args			di_case(t_args list, va_list ap);
t_args			c_case(t_args list, va_list ap);
t_args			s_case(t_args list, va_list ap);
t_args			u_case(t_args list, va_list ap);
t_args			o_case(t_args list, va_list ap);
t_args			xcap_case(t_args list, va_list ap);
t_args			xcap_case_2(t_args list, va_list ap);
t_args			xsmall_case(t_args list, va_list ap);
t_args			f_case(t_args list, va_list ap);
void			f_case_2(t_args *list, va_list ap, intmax_t *conv, size_t *len);
size_t			f_case_3(t_args *list, size_t len, intmax_t conv, size_t exp);
int				f_case_4(t_args *list, int flag, intmax_t conv, size_t exp);
void			f_case_5(t_args *list, size_t exp, int flag, size_t len);
void			prepare_modif(t_args *list);
void			parse_flags(t_args *list);
t_args			handle_plus(t_args list);
t_args			handle_space(t_args list);
t_args			handle_prec_string(t_args list);
t_args			handle_0prec_x(t_args list, char *pad_wid);
t_args			handle_leftpad(t_args list);
t_args			handle_minus(t_args list);
t_args			handle_0_pad(t_args list);
t_args			handle_0_pad_2(t_args list, int i, char *pad_wid, int pad);
t_args			handle_prec(t_args list);
t_args			handle_prec_2(t_args list, int adjst, int len);
t_args			handle_prec_3(t_args list);
int				ft_count_itoa(size_t n, int base);
char			*ft_convert_itoa(size_t n, char *arr, int flag, int base);
char			*ft_itoa_basemax(size_t n, int base);

#endif
