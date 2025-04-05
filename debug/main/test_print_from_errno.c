/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_from_errno.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:31:28 by mfunakos          #+#    #+#             */
/*   Updated: 2025/04/05 21:49:01 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	test_print_from_errno(t_error_type err_type, char *arg)
{
	char	*before;
	char	*after;

	ft_putstr_fd(SHELL_NAME, 2);
	if (err_type == ERR_SYSCALL)
	{
		perror(arg);
		return ;
	}
	else if (err_type == ERR_AMBRDIR)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ambiguous redirect", 2);
	}
	else if (err_type == ERR_SYNTAX)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\'", 2);
	}
	else if (err_type == ERR_ISDIR)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": Is a directory", 2);
	}
	else if (err_type == ERR_CMDNFND)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found", 2);
	}
	else if (err_type == ERR_EXPO_BADID)
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\': not a valid identifier", 2);
	}
	else if (err_type == ER_HEREDOC)
	{
		ft_putstr_fd("warning: here-document delimited by end-of-file \
(wanted `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\')", 2);
	}
	else if (err_type == ERR_CD_2MARG)
	{
		ft_putstr_fd("cd: too many arguments", 2);
	}
	else if (err_type == ERR_CD_OPWDNSET)
	{
		ft_putstr_fd("cd: OLDPWD not set", 2);
	}
	else if (err_type == ERR_CD)
	{
		ft_putstr_fd("cd: ", arg);
		ft_putstr_fd(arg, 2);
	}
	ft_putstr_fd("\n", 2);
}

int	main(void)
{
	char	*msg = "msg";
	open(msg, O_WRONLY);
	// 各エラータイプをテスト
	test_print_from_errno(ERR_SYSCALL, "msg");          // perrorを使った出力
	test_print_from_errno(ERR_AMBRDIR, "$aa");      // あいまいなリダイレクト
	test_print_from_errno(ERR_SYNTAX, "|");             // シンタックスエラー
	test_print_from_errno(ERR_ISDIR, "../");       // ディレクトリエラー
	test_print_from_errno(ERR_CMDNFND, "cmd");    // コマンド見つからない
	test_print_from_errno(ER_HEREDOC, "EOF");     // exportに使えない識別
	test_print_from_errno(ERR_EXPO_BADID, "42=");     // exportに使えない識別子
	test_print_from_errno(ERR_CD_2MARG, NULL);           // cdの引数多すぎ
	test_print_from_errno(ERR_CD_OPWDNSET, NULL);        // OLDPWD未設定
	test_print_from_errno(ERR_CD, "nonexistent_dir");    // cdの通常エラー

	return (0);
}
