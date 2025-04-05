/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perrmsg_with_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:14:31 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 03:31:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	perrmsg_with_str(t_errmsg_type err_type, char *str)
{
	ft_putstr_fd(SHELL_NAME, 2);
	if (err_type == EM_SYSCALL)
	{
		perror(str);
		return ;
	}
	else if (err_type == EM_CD_SYSCALL)
	{
		ft_putstr_fd("cd: ", 2);
		perror(str);
		return ;
	}
	else if (err_type == EM_AMBRDIR)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ambiguous redirect", 2);
	}
	else if (err_type == EM_SYNTAX)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\'", 2);
	}
	else if (err_type == EM_ISDIR)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Is a directory", 2);
	}
	else if (err_type == EM_CMDNFND)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": command not found", 2);
	}
	else if (err_type == EM_HEREDOC)
	{
		ft_putstr_fd("warning: here-document delimited by end-of-file (wanted `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\')", 2);
	}
	else if (err_type == EM_MANYARG)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": too many arguments", 2);
	}
	else if (err_type == EM_EXPO_BADID)
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\': not a valid identifier", 2);
	}
	else if (err_type == EM_EXIT_NONUM)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required", 2);
	}
	else if (err_type == EM_CD_OPWDNSET)
	{
		ft_putstr_fd("cd: OLDPWD not set", 2);
	}
	ft_putstr_fd("\n", 2);
}

// void	perrmsg_with_str(t_errmsg_type err_type, char *str)
// {
// 	ft_putstr_fd(SHELL_NAME, 2);
// 	if (err_type == EM_SYSCALL)
// 		print_syscall_error(str);
// 	else if (err_type == EM_CD_SYSCALL)
// 		print_cd_syscall_error(str);
// 	else if (err_type == EM_AMBRDIR)
// 		print_amb_redir_error(str);
// 	else if (err_type == EM_SYNTAX)
// 		print_syntax_error(str);
// 	else if (err_type == EM_ISDIR)
// 		print_is_directory_error(str);
// 	else if (err_type == EM_CMDNFND)
// 		print_command_not_found_error(str);
// 	else if (err_type == EM_HEREDOC)
// 		print_heredoc_warning_error(str);
// 	else if (err_type == EM_MANYARG)
// 		print_too_many_arg_error(str);
// 	else if (err_type == EM_EXPO_BADID)
// 		print_bad_identifier_error(str);
// 	else if (err_type == EM_EXIT_NONUM)
// 		print_no_numeric_error(str);
// 	else if (err_type == EM_CD_OPWDNSET)
// 		print_oldpwd_not_set_error();
// 	ft_putstr_fd("\n", 2);
// }
