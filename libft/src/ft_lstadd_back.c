/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:58:29 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/11 01:02:24 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*leaf;

	if (lst == NULL)
		return ;
	leaf = ft_lstlast(*lst);
	if (leaf == NULL)
		*lst = new;
	else
		leaf->next = new;
}
