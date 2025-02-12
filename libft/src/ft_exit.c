/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:42:12 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/31 01:40:45 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include <stdlib.h>

static void	*_get_func_atexit(void)
{
	static void	(*f[FT_MAX_F_ATEXIT + 1])(void);

	return ((void (**)(void))f);
}

int	ft_atexit(void *function)
{
	void			(*f)(void);
	void			(**fs)(void);
	static size_t	i;

	f = (void (*)(void))function;
	if (i == FT_MAX_F_ATEXIT)
		return (-1);
	fs = _get_func_atexit();
	fs[i] = f;
	i++;
	return (0);
}

void	ft_exit(int status)
{
	void	(**fs)(void);
	size_t	i;

	fs = _get_func_atexit();
	i = (0);
	while (fs[i])
		fs[i++]();
	exit(status);
}
