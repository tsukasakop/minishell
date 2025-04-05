/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perrmsg_with_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:14:31 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 01:25:20 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	perrmsg_with_str(t_errmsg_type err_type, char *arg)
{
	ft_putstr_fd(SHELL_NAME, 2);
	if (err_type == EM_SYSCALL)
	{
		perror(arg);
		return ;
	}
	else if (err_type == EM_AMBRDIR)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ambiguous redirect", 2);
	}
	else if (err_type == EM_SYNTAX)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\'", 2);
	}
	else if (err_type == EM_ISDIR)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": Is a directory", 2);
	}
	else if (err_type == EM_CMDNFND)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found", 2);
	}
	else if (err_type == EM_EXPO_BADID)
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\': not a valid identifier", 2);
	}
	else if (err_type == EM_HEREDOC)
	{
		ft_putstr_fd("warning: here-document delimited by end-of-file (wanted `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\')", 2);
	}
	else if (err_type == EM_CD_2MARG)
	{
		ft_putstr_fd("cd: too many arguments", 2);
	}
	else if (err_type == EM_CD_OPWDNSET)
	{
		ft_putstr_fd("cd: OLDPWD not set", 2);
	}
	else if (err_type == EM_CD)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(arg, 2);
	}
	ft_putstr_fd("\n", 2);
}
