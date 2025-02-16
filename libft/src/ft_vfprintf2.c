/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/23 19:15:04 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

char	get_sign(t_format *f)
{
	if (f->u_val.nbr < 0)
		return ('-');
	if (f->s_flag.plus)
		return ('+');
	if (f->s_flag.space)
		return (' ');
	return ('\0');
}

size_t	minus(size_t *lhs, size_t rhs)
{
	if (*lhs < rhs)
		return (0);
	(*lhs) = (*lhs) - rhs;
	return (1);
}

void	set_f_width(t_print *p, t_format *f)
{
	size_t	f_width;

	f_width = f->field;
	if (!minus(&f_width, p->inner_len))
		return ;
	if (!minus(&f_width, p->zero_len))
		return ;
	if (p->sign && !minus(&f_width, 1))
		return ;
	if (p->prefix && !minus(&f_width, 2))
		return ;
	if (f->s_flag.minus)
		p->r_ws_len = f_width;
	else if (f->s_flag.zero && !f->s_flag.period)
		p->zero_len += f_width;
	else
		p->l_ws_len = f_width;
}

void	set_prec(t_print *p, t_format *f)
{
	size_t	prec;

	if (!f->s_flag.period)
		return ;
	prec = f->prec;
	if (!minus(&prec, p->inner_len))
		return ;
	p->zero_len = prec;
}

char	*ft_ui64toa_base(uint64_t i, const char *base, unsigned char base_len)
{
	char	buf[65];
	int		cur;

	buf[64] = '\0';
	cur = 64;
	if (!i)
	{
		cur--;
		buf[cur] = base[0];
	}
	while (i)
	{
		cur--;
		buf[cur] = base[i % base_len];
		i /= base_len;
	}
	return (ft_strdup(buf + cur));
}
