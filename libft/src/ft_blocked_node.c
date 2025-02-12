/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocked_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:06:05 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/26 20:42:42 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_blocked_node.h"
#include "ft_stdlib.h"

t_blocked_node	*ft_bnnew(void)
{
	return ((t_blocked_node *)ft_calloc(sizeof(t_blocked_node), 1));
}

int	ft_bnadd(t_blocked_node *bn, void *ptr)
{
	while (bn->cnt == BN_STORE_MAX)
	{
		if (!bn->next)
		{
			bn->next = ft_bnnew();
			if (!bn->next)
				return (0);
		}
		bn = bn->next;
	}
	bn->p[bn->cnt] = ptr;
	bn->cnt += 1;
	return (1);
}

void	ft_bnfree_shallow(t_blocked_node *bn)
{
	t_blocked_node	*cur;
	t_blocked_node	*tmp;
	size_t			i;

	cur = bn;
	while (cur)
	{
		i = 0;
		while (i < cur->cnt)
		{
			free(cur->p[i]);
			i++;
		}
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}
