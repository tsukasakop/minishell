/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htbl2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:18:31 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 12:18:33 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_htbl.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void	htiter(t_htbl ht, void (*f)(t_htnode *, void *), void *p)
{
	int			h;
	t_htnode	*node;
	t_htnode	*_node;

	h = 0;
	while (h < HTSIZE)
	{
		node = ht[h];
		while (node)
		{
			_node = node->next;
			f(node, p);
			node = _node;
		}
		h++;
	}
}
