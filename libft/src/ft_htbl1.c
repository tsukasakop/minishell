/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htbl1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:25:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/01/04 14:16:10 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_htbl.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static void	htnodedel(t_htnode *htnode, void (*del)(t_htnode *))
{
	if (del)
		del(htnode);
	free(htnode);
}

void	htdelone(t_htnode **ht, const char *key, void (*del)(t_htnode *))
{
	uint8_t		h;
	t_htnode	*i;
	t_htnode	**p;

	h = hash(key);
	p = &ht[h];
	i = ht[h];
	while (i)
	{
		if (!ft_strcmp(i->key, key))
		{
			*p = i->next;
			htnodedel(i, del);
			return ;
		}
		p = &((*p)->next);
		i = i->next;
	}
}

void	htclear(t_htnode **ht, void (*del)(t_htnode *))
{
	uint8_t		h;
	t_htnode	*i;
	t_htnode	*tmp;

	h = 0;
	while (h < HTSIZE)
	{
		i = ht[h];
		while (i)
		{
			tmp = i->next;
			htnodedel(i, del);
			i = tmp;
		}
		h++;
	}
	free(ht);
}
