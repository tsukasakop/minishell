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

int	main(void)
{
	char	*msg = "msg";
	open(msg, O_WRONLY);
	// 各エラータイプをテスト
	perrmsg_with_str(EM_SYSCALL, NULL);
	perrmsg_with_str(EM_SYSCALL, "msg");          // perrorを使った出力
	perrmsg_with_str(EM_ISDIR, "../");       // ディレクトリエラー
	perrmsg_with_str(EM_SYSCALL, "../");       // ディレクトリエラー
	perrmsg_with_str(EM_CMDNFND, "cmd");    // コマンド見つからない
	perrmsg_with_str(EM_SYNTAX, "|");             // シンタックスエラー
	perrmsg_with_str(EM_AMBRDIR, "$aa");      // あいまいなリダイレクト
	perrmsg_with_str(EM_EXPO_BADID, "42=");     // exportに使えない識別子
	perrmsg_with_str(EM_MANYARG, "cd");           // cdの引数多すぎ
	perrmsg_with_str(EM_CD_OPWDNSET, NULL);        // OLDPWD未設定
	perrmsg_with_str(EM_CD_SYSCALL, "/dir/in");    // cdの通常エラー
	perrmsg_with_str(EM_HEREDOC, "EOF");     // exportに使えない識別

	return (0);
}
