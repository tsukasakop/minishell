/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:08:39 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/08 01:57:21 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_stdlib.h"
#include <stdlib.h>

t_memory_manager	*ft_mmnew(void)
{
	t_memory_manager	*(*_mmnew)(void);

	_mmnew = ft_bnnew;
	return ((t_memory_manager *)_mmnew());
}

void	*ft_mmadd(t_memory_manager *mm, void *ptr)
{
	int	(*_mmadd)(t_memory_manager *, void *);

	_mmadd = ft_bnadd;
	if (!mm)
		return (NULL);
	if (!_mmadd(mm, ptr))
		return (NULL);
	return (ptr);
}

void	*ft_mmmalloc(t_memory_manager *mm, size_t size)
{
	void	*p;

	if (!mm)
		return (NULL);
	p = malloc(size);
	if (!p)
		return (NULL);
	if (!ft_mmadd(mm, p))
	{
		free(p);
		return (NULL);
	}
	return (p);
}

void	*ft_mmcalloc(t_memory_manager *mm, size_t cnt, size_t size)
{
	void	*p;

	if (!mm)
		return (0);
	p = ft_calloc(cnt, size);
	if (!p)
		return (NULL);
	if (!ft_mmadd(mm, p))
	{
		free(p);
		return (NULL);
	}
	return (p);
}

void	ft_mmfree(t_memory_manager *mm)
{
	void	(*_mmfree)(t_memory_manager *);

	_mmfree = ft_bnfree_shallow;
	if (!mm)
		return ;
	_mmfree(mm);
}
