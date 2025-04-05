/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_shell_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 03:41:19 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 01:56:56 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_errmsg_with_arg(char *msg, char *arg)
{
	char	*before;
	char	*after;

	ft_putstr_fd(SHELL_NAME, 2);
	if (msg)
	{
		after = strstr(msg, "{ARG}");
		if (arg && after)
		{
			before = msg;
			write(2, before, after - before);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(after + ft_strlen("{ARG}"), 2);
		}
		else
			ft_putstr_fd(msg, 2);
	}
	ft_putstr_fd("\n", 2);
}

void	print_errmsg_with_errno(char *prefix)
{
	ft_putstr_fd(SHELL_NAME, 2);
	if (prefix)
	{
		ft_putstr_fd(prefix, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

int	command_not_found_handle_new(char *cmd)
{
	print_errmsg_with_arg(EM_CMDNFND, cmd);
	return (127);
}


void	perror_with_shellname_new(char *prefix)
{
	print_errmsg_with_errno(prefix);
}

int	main(void)
{
	char	*msg = "msg";
	open(msg, O_WRONLY);
	perror_with_shellname_new(msg);

	char	*path = "../";
	print_errmsg_with_arg(EM_ISDIR, path);
	open("mm", O_WRONLY);
	print_errmsg_with_errno(path);
	path = "cmd";
	print_errmsg_with_arg(EM_CMDNFND, path);


	char	*syntax = "|";
	print_errmsg_with_arg(EM_SYNTAX, "|");

	char	*target = "$aa";
	print_errmsg_with_arg(EM_AMBRDIR, target);

	char	*identifier = "42=";
	print_errmsg_with_arg(EM_EXPO_BADID, identifier);

	print_errmsg_with_arg(EM_MANYARG, NULL);
	print_errmsg_with_arg(EM_CD_OPWDNSET, NULL);
	char		*next_dir = "/dir/in";
	print_errmsg_with_arg(EM_CD, next_dir);

	char	*delimiter = "EOF";
	print_errmsg_with_arg(ERR_HEREDOC, delimiter);

	return (0);
}
