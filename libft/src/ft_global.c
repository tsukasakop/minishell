/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:44:16 by tkondo            #+#    #+#             */
/*   Updated: 2025/01/04 12:30:03 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"

t_htbl	ft_get_globals(void)
{
	static t_htnode	*dict[HTSIZE];

	return (dict);
}

int	ft_set_global(const char *key, void *val)
{
	t_htbl	dict;

	dict = ft_get_globals();
	if (!dict)
		return (0);
	return (!!htadd(dict, key, val));
}

void	*ft_get_global(const char *key)
{
	t_htbl	dict;

	dict = ft_get_globals();
	if (!dict)
		return (0);
	return (htget(dict, key));
}

void	ft_delone_global(const char *key, void (*del)(t_htnode *))
{
	t_htbl	dict;

	dict = ft_get_globals();
	if (!dict)
		return ;
	return (htdelone(dict, key, del));
}
