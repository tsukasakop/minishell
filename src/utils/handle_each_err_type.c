/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_each_err_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:47:11 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/26 04:06:36 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  read input and write it on given fd until it is hd_eof or empty line
 *
 * fd: file descriptor to write
 * hd_eof: string represent end
 */
void	handle_each_err_type(t_error_type err_type, char *str)
{
	set_error_type(err_type);
	if (err_type == NOERR)
		return ;
	else if (err_type == ERR_PERROR)
		perror_with_shellname(str);
	else if (err_type == ERR_AMBRDIR)
		ft_fprintf(ft_stderr(), "bash: %s: ambiguous redirect\n", str);
	else if (err_type == ERR_SYNTAX)
		syntax_error_handle(str);
}
