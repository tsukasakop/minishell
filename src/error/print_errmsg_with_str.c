/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errmsg_with_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:32:54 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/12 22:32:55 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:print_errmsg_with_str
 * ----------------------------
 * Prints the error message specified by err_type.
 * If necessary, also prints str.
 */
void	print_errmsg_with_str(t_errmsg_type err_type, char *str)
{
	ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
	if (err_type == EM_SYSCALL)
		perror(str);
	else if (err_type == EM_CD_SYSCALL)
		print_cd_syscall_error(str);
	else if (err_type == EM_AMBRDIR)
		print_amb_redir_error(str);
	else if (err_type == EM_SYNTAX)
		print_syntax_error(str);
	else if (err_type == EM_ISDIR)
		print_is_directory_error(str);
	else if (err_type == EM_CMDNFND)
		print_command_not_found_error(str);
	else if (err_type == EM_HEREDOC)
		print_heredoc_warning_error(str);
	else if (err_type == EM_MANYARG)
		print_too_many_arg_error(str);
	else if (err_type == EM_EXPO_BADID)
		print_bad_identifier_error(str);
	else if (err_type == EM_EXIT_NONUM)
		print_no_numeric_error(str);
	else if (err_type == EM_CD_OPWDNSET)
		print_oldpwd_not_set_error();
}
