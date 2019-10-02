/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:50:04 by drestles          #+#    #+#             */
/*   Updated: 2019/02/13 11:13:22 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define BUFF_SIZE 131072
# define TYPE "sSpdDioOuUxXcCf"

typedef struct	s_flag {
	int			sharp;
	int			nul;
	int			minus;
	int			plus;
	int			space;
	int			point;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			width;
	int			num;
	int			dot;
	int			toch;
	int			nn;
}				t_flag;

typedef struct	s_prt {
	va_list		*ap;
	t_flag		*flag;
	char		buff[BUFF_SIZE];
	char		*format;
	int			i;
	int			j;
	size_t		len;
	int			count_zero;
}				t_prt;

int				flags(t_prt *prt);
int				parser(t_prt *prt);
int				ft_printf(const char *format, ...);
int				init_flags(t_prt *prt);
int				def_types(t_prt *prt);
int				types(t_prt *prt);
int				def_percentage(t_prt *prt);
int				third_flags_two(t_prt *prt);
int				third_flags_one(t_prt *prt);
int				third_flags(t_prt *prt);
int				second_flags(t_prt *prt);
int				first_flags(t_prt *prt);
int				handle_d(t_prt *prt);
int				handle_c(t_prt *prt);
int				handle_c_flags(t_prt *prt, char *c);
int				handle_zero(t_prt *prt);
int				handle_s(t_prt *prt);
int				handle_s_flags(t_prt *prt, char *s, size_t len);
char			*ft_itoal(long int n);
char			*ft_itoal_u(unsigned long int n);
int				handle_f(t_prt *prt);
int				handle_d(t_prt *prt);
int				handle_u(t_prt *prt);
char			*multibytes(char *uni, int c, int bytes);
char			*ft_unicode(int c);
int				handle_s_flags(t_prt *prt, char *s, size_t len);
int				handle_s(t_prt *prt);
int				handle_c(t_prt *prt);
int				handle_c_flags(t_prt *prt, char *c);
int				handle_ls_flags(t_prt *prt, char *s, size_t len);
int				handle_ls(t_prt *prt);
int				handle_lc_flags(t_prt *prt, char *s, size_t len);
int				handle_lc(t_prt *prt);
int				handle_x(t_prt *prt);
long int		assignment_u(t_prt *prt);
int				handle_o(t_prt *prt);
int				handle_b_x(t_prt *prt);
long int		abs_l(long int a);
int				handle_p(t_prt *prt);
long double		pow_10(int n);
char			*ft_strjoin_right(char const *s1, char const *s2);
char			*ft_strjoin_left(char const *s1, char const *s2);
char			*ft_strjoin_all(char const *s1, char const *s2);
char			*ft_strdup_free(const char *s1);

#endif
