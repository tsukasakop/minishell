/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_stdio.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:11:49 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/31 03:27:20 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STDIO_H
# define _FT_STDIO_H
# include "ft_ctype.h"
# include "ft_global.h"
# include "ft_memory.h"
# include "ft_stdio.h"
# include "ft_stdlib.h"
# include "ft_string.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_format	t_format;
typedef struct s_print	t_print;

struct					s_format
{
	unsigned char		mod;
	union
	{
		int				nbr;
		void			*ptr;
	} u_val;
	struct
	{
		unsigned int	zero : 1;
		unsigned int	minus : 1;
		unsigned int	space : 1;
		unsigned int	plus : 1;
		unsigned int	num : 1;
		unsigned int	period : 1;
	} s_flag;
	size_t				prec;
	size_t				field;
};

struct					s_print
{
	char				sign;
	const char			*prefix;
	size_t				l_ws_len;
	size_t				zero_len;
	size_t				inner_len;
	size_t				r_ws_len;
	const unsigned char	*p;
};

size_t					get_cnt(void);
void					set_cnt(size_t cnt);
void					del_cnt(void);
size_t					can_add_to_cnt(size_t c);
size_t					add_cnt(size_t rhs);
void					read_flag(const char **f, t_format *fmt);
int						read_nbr(const char **f);
int						read_arg(const char **f, t_format *p, va_list ap);
void					read_raw(t_format *fmt, const char **f);
t_format				*read_fmt(const char **f, va_list ap);
char					get_sign(t_format *f);
size_t					minus(size_t *lhs, size_t rhs);
void					set_f_width(t_print *p, t_format *f);
void					set_prec(t_print *p, t_format *f);
char					*ft_ui64toa_base(uint64_t i, const char *base,
							unsigned char base_len);
void					init_print_percent(t_format *f, t_print *p);
void					init_print_s(t_format *f, t_print *p);
void					init_print_c(t_format *f, t_print *p);
void					init_print_d(t_format *f, t_print *p);
void					init_print_u(t_format *f, t_print *p);
void					init_print_x(t_format *f, t_print *p);
void					init_print_xx(t_format *f, t_print *p);
void					init_print_p(t_format *f, t_print *p);
t_print					*norm_fmt(t_format *f);
int						is_overflow(t_print *p);
void					ft_fputc_wrapper(int c, t_file *stream);
void					print_data(t_file *s, t_print *p);
void					print_unit(t_file *s, t_print *p);
void					print_by_unit(t_file *s, const char **f, va_list ap);
t_memory_manager		*vfpmm(void);

#endif
