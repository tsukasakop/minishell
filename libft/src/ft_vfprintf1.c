/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/31 03:18:32 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

void	read_flag(const char **f, t_format *fmt)
{
	while (1)
	{
		if (**f == '#')
			fmt->s_flag.num = 1;
		else if (**f == '0')
			fmt->s_flag.zero = 1;
		else if (**f == '-')
			fmt->s_flag.minus = 1;
		else if (**f == ' ')
			fmt->s_flag.space = 1;
		else if (**f == '+')
			fmt->s_flag.plus = 1;
		else
			return ;
		++*f;
	}
}

int	read_nbr(const char **f)
{
	int	n;

	n = 0;
	while (ft_isdigit(**f))
	{
		if (n > (INT_MAX - **f + '0') / 10)
			set_cnt(EOF);
		n = **f - '0' + n * 10;
		++*f;
	}
	return (n);
}

int	read_arg(const char **f, t_format *p, va_list ap)
{
	p->mod = **f;
	++*f;
	if (ft_strchr("cdiuxX", p->mod))
		p->u_val.nbr = va_arg(ap, int);
	else if (ft_strchr("sp", p->mod))
		p->u_val.ptr = va_arg(ap, void *);
	else if (p->mod == '%')
		;
	else
		return (0);
	return (1);
}

void	read_raw(t_format *fmt, const char **f)
{
	size_t	i;

	fmt->mod = 'R';
	i = 0;
	while ((*f)[i] && (*f)[i] != '%')
		++i;
	fmt->u_val.ptr = (void *)ft_strndup(*f, i);
	ft_mmadd(vfpmm(), fmt->u_val.ptr);
	*f += i;
}

t_format	*read_fmt(const char **f, va_list ap)
{
	t_format	*fmt;

	fmt = ft_mmcalloc(vfpmm(), 1, sizeof(t_format));
	if (fmt == NULL)
		return (NULL);
	if (**f != '%')
		read_raw(fmt, f);
	else
	{
		++*f;
		read_flag(f, fmt);
		fmt->field = read_nbr(f);
		if (**f == '.')
		{
			++*f;
			fmt->s_flag.period = 1;
			fmt->prec = read_nbr(f);
		}
		read_arg(f, fmt, ap);
	}
	return (fmt);
}
