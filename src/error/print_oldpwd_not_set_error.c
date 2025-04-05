/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oldpwd_not_set_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 03:50:20 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:print_oldpwd_not_set_error
 * ----------------------------
 * When executing the cd command,
 * an error is output if OLDPWD is not set.
 */
void	print_oldpwd_not_set_error(void)
{
	ft_putstr_fd("cd: OLDPWD not set", 2);
	ft_putstr_fd("\n", 2);
}
