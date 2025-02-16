/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/31 10:17:37 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

t_memory_manager	*vfpmm(void)
{
	return ((t_memory_manager *)ft_get_global("ft-vfp-mm"));
}

void	print_by_unit(t_file *s, const char **f, va_list ap)
{
	t_print		*p;
	t_format	*fmt;

	ft_set_global("ft-vfp-mm", (void *)ft_mmnew());
	fmt = read_fmt(f, ap);
	p = norm_fmt(fmt);
	if (p)
		print_unit(s, p);
	ft_mmfree(vfpmm());
	ft_delone_global("ft-vfp-mm", NULL);
}

int	ft_vfprintf(t_file *s, const char *format, va_list ap)
{
	int	cnt;

	set_cnt(0);
	while (*format != '\0' && get_cnt() < INT_MAX)
	{
		print_by_unit(s, &format, ap);
		if (get_cnt() > INT_MAX)
		{
			del_cnt();
			return (EOF);
		}
	}
	cnt = get_cnt();
	del_cnt();
	return (cnt);
}
