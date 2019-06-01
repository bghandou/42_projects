#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <errno.h>
# define BUFF 2048

/*
**	Concernant le "intflags"
**	0 = nothing
**	1 = l
**	2 = ll
**	3 = h
**	4 = hh
**
**	Pour les autres flags
**	Si 1, alors present, sinon 0 = absent :D
**	Cas particulier : precision (-1 si absent)
*/

typedef struct	s_flag
{
	char	buffer[BUFF + 1];
	va_list	ap;
	size_t	buffer_index;
	size_t	str_index;
	int		total_size;
	char	type;
	char	intflags;
	int		precision;
	int		minsize;
	char	minus;
	char	plus;
	char	l;
	char	space;
	char	hash;
	char	zero;
}				t_flag;

void			*ft_memset2(void *s, int c, size_t n);
void			ft_bzero2(char *s, size_t n);
int				ft_strcmp2(const char *s1, const char *s2);
char			*ft_strdup2(const char *s);
size_t			ft_strlen2(const char *s);
char			*ft_itoa2(int n);
int				ft_atoi2(char *s, t_flag *all);
void			ft_strrev2(char *str);

/*
**itoabu stands for : integer to array base unsigned
**itoabs stands for : integer to array base signed
*/
void			ft_ftoa(long double num, t_flag *all);
void			ft_itoabu(unsigned long long nb, t_flag *all);
void			ft_itoabs(long long nb, t_flag *all);
void			ft_ptoa(size_t nb, t_flag *flags);
void			char_flags(char ret, t_flag *all);
void			str_flags(char *ret, t_flag *all);
void			print(char *ret, t_flag *all);
void			ft_strcat2(char *arg, t_flag *all);
void			ft_charcat2(char arg, t_flag *all);
void			ft_strlcat2(char *arg, t_flag *all, size_t size);

void			get_int(t_flag *flags);
void			get_int_base(t_flag *flags);
void			get_pourcent(t_flag *flags);
void			get_float(t_flag *all);
void			get_nothing(t_flag *all);
void			print_errno(t_flag *all);
void			get_charwriten(t_flag *all);

int				ft_printf(const char *str, ...);

#endif
