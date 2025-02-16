/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocked_node.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:53:48 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/19 17:22:58 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BLOCKED_NODE_H
# define FT_BLOCKED_NODE_H
# define BN_STORE_MAX 256

# include <stdlib.h>

typedef struct s_blocked_node	t_blocked_node;

struct							s_blocked_node
{
	void						*p[BN_STORE_MAX];
	size_t						cnt;
	t_blocked_node				*next;
};

t_blocked_node					*ft_bnnew(void);
int								ft_bnadd(t_blocked_node *bn, void *ptr);
void							ft_bnfree_shallow(t_blocked_node *bn);

#endif
