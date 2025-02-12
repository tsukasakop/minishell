/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/23 18:51:05 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

size_t	get_cnt(void)
{
	return ((size_t)ft_get_global("_vfp_cnt"));
}

void	set_cnt(size_t cnt)
{
	ft_set_global("_vfp_cnt", (void *)cnt);
}

void	del_cnt(void)
{
	ft_delone_global("_vfp_cnt", NULL);
}

size_t	can_add_to_cnt(size_t c)
{
	size_t	cnt;

	cnt = get_cnt();
	return (cnt < INT_MAX && cnt >= 0 && cnt < INT_MAX - c);
}

size_t	add_cnt(size_t rhs)
{
	size_t	lhs;

	lhs = get_cnt();
	if (lhs > SIZE_MAX - rhs)
		set_cnt(SIZE_MAX);
	else
		set_cnt(lhs + rhs);
	return (get_cnt());
}
