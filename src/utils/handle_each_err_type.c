/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_each_err_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:47:11 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/27 17:34:14 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:handle_each_err_type
 * ----------------------------
 * Set t_error_type and output errors for each err_type.
 */
void	handle_each_err_type(t_error_type err_type, char *str)
{
	set_error_type(err_type);
	if (err_type == NOERR)
		return ;
	else if (err_type == ERR_SYSCOLL)
		perror_with_shellname(str);
	else if (err_type == ERR_AMBRDIR)
		ft_fprintf(ft_stderr(), "bash: %s: ambiguous redirect\n", str);
	else if (err_type == ERR_SYNTAX)
		syntax_error_handle(str);
}
