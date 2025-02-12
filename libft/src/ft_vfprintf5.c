/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/31 03:20:25 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

t_print	*norm_fmt(t_format *f)
{
	t_print	*p;

	p = (t_print *)ft_mmcalloc(vfpmm(), sizeof(t_print), 1);
	if (!p)
		return (NULL);
	if (f->mod == 'R' || f->mod == 's')
		init_print_s(f, p);
	if (f->mod == '%')
		init_print_percent(f, p);
	if (f->mod == 'c')
		init_print_c(f, p);
	if (f->mod == 'd' || f->mod == 'i')
		init_print_d(f, p);
	if (f->mod == 'u')
		init_print_u(f, p);
	if (f->mod == 'x')
		init_print_x(f, p);
	if (f->mod == 'X')
		init_print_xx(f, p);
	if (f->mod == 'p')
		init_print_p(f, p);
	return (p);
}

int	is_overflow(t_print *p)
{
	size_t	cnt;

	cnt = !!p->sign;
	if (!can_add_to_cnt(cnt))
		return (1);
	cnt += 2 * !!p->prefix;
	if (!can_add_to_cnt(cnt))
		return (1);
	cnt += p->l_ws_len * (p->l_ws_len > 0);
	if (!can_add_to_cnt(cnt))
		return (1);
	cnt += p->zero_len * (p->zero_len > 0);
	if (!can_add_to_cnt(cnt))
		return (1);
	cnt += p->inner_len * (p->inner_len > 0);
	if (!can_add_to_cnt(cnt))
		return (1);
	return (0);
}

void	ft_fputc_wrapper(int c, t_file *stream)
{
	if (ft_fputc(c, stream) != EOF)
		add_cnt(1);
}

void	print_data(t_file *s, t_print *p)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < p->inner_len)
	{
		ft_fputc_wrapper(p->p[cnt], s);
		cnt++;
	}
}

void	print_unit(t_file *s, t_print *p)
{
	size_t	cnt;

	cnt = 0;
	while (cnt++ < (size_t)p->l_ws_len)
		ft_fputc_wrapper(' ', s);
	if (p->sign)
		ft_fputc_wrapper(p->sign, s);
	cnt = 0;
	if (p->prefix)
	{
		while (p->prefix[cnt])
			ft_fputc_wrapper(p->prefix[cnt++], s);
	}
	cnt = 0;
	while (cnt++ < (size_t)p->zero_len)
		ft_fputc_wrapper('0', s);
	print_data(s, p);
	cnt = 0;
	while (cnt++ < (size_t)p->r_ws_len)
		ft_fputc_wrapper(' ', s);
}
