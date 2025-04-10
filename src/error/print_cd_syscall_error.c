/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cd_syscall_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:36:54 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 19:02:00 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:print_cd_syscall_error
 * ----------------------------
 * cd and errno error output.
 */
void	print_cd_syscall_error(char *str)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	perror(str);
}
