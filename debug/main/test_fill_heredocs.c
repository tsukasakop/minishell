/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fill_heredocs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:39:47 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/04 14:37:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_hd_list(t_heredoc *hd_list)
{
	while (hd_list)
	{
		printf("hd_eof: \"%s\", path: \"%s\"\n", hd_list->eof, hd_list->path);
		if (unlink(hd_list->path) != 0)
			perror("unlink error");
		hd_list = hd_list->next;
	}
}

void	print_redirects(t_redirect *redir)
{
	while (redir)
	{
		printf("Redirect: type=%d, from_fd=%d, path=%s\n",
			redir->type, redir->from_fd, redir->path);
		redir = redir->next;
	}
}

// **📝 テスト実行**
int	main(void)
{
	t_redirect	*redir = NULL;
	t_heredoc	*hd = NULL;
	size_t		i;
	i = 0;
	char		*word[4][2] = {
		{"<<", "EOF"},
		{"<<", "2"},
		{">", "1"},
		{NULL}
	};
	while (word[i][0])
	{
		printf("word[0] = %s, word[1] = %s\n", word[i][0], word[i][1]);
		parse_redirects(&redir, &hd, word[i][0], word[i][1]);
		i++;
	}
	// **結果確認**
	printf("\n--- Redirects ---\n");
	print_redirects(redir);
	printf("\n--- Heredocs ---\n");
	print_hd_list(hd);

	return (0);
}
