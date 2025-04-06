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

int	main(void)
{
	open("noexsit", O_WRONLY);

	print_errmsg_with_str(EM_SYSCALL, NULL);
	print_errmsg_with_str(EM_SYSCALL, "msg");          // perrorを使った出力
	print_errmsg_with_str(EM_ISDIR, "../");       // ディレクトリエラー
	print_errmsg_with_str(EM_CMDNFND, "cmd");    // コマンド見つからない
	print_errmsg_with_str(EM_SYNTAX, "|");             // シンタックスエラー
	print_errmsg_with_str(EM_AMBRDIR, "$aa");      // あいまいなリダイレクト
	print_errmsg_with_str(EM_EXIT_NONUM, "hello");      // exitの引数が数値以外だった時
	print_errmsg_with_str(EM_EXPO_BADID, "42=");     // exportに使えない識別子
	print_errmsg_with_str(EM_MANYARG, "cd");           // cdの引数多すぎ
	print_errmsg_with_str(EM_CD_OPWDNSET, NULL);        // OLDPWD未設定
	print_errmsg_with_str(EM_CD_SYSCALL, "/dir/in");    // cdの通常エラー
	print_errmsg_with_str(EM_HEREDOC, "EOF");     // ヒアドク中のエラー

	return (0);
}
