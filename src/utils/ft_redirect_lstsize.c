/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_lstsize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:11:14 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/06 02:12:08 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:ft_redirect_lstsize
 * ----------------------------
 * Return size of t_redirect lst.
 */
int	ft_redirect_lstsize(t_redirect *lst)
{
	if (lst == NULL)
		return (0);
	return (ft_redirect_lstsize(lst->next) + 1);
}
