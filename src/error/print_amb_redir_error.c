/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_amb_redir_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 03:20:14 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:aaaaaaaaaaaaaa
 * ----------------------------
 */
void	print_amb_redir_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ambiguous redirect", 2);
	ft_putstr_fd("\n", 2);
}
