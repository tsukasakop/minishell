/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write_heredocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:39:47 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 14:34:20 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

volatile unsigned char g_signal = 0;

void	print_hd_list(t_heredoc *hd_list)
{
	while (hd_list)
	{
		printf("hd_eof: \"%s\", path: \"%s\"\n", hd_list->eof, hd_list->path);
		hd_list = hd_list->next;
	}
}

int	main(void)
{
	t_heredoc	*root_hd;
	t_heredoc	*cur_hd;
	char		*hd_texts[4][2] = {
		{"EOF", "/tmp/eof"},
		{"AIUEO", "/tmp/aiueo"},
		{"EOF", "/tmp/eof2"},
		{NULL}
	};
	size_t		i;

	i = 0;
	root_hd = NULL;
	while (hd_texts[i][0])
	{
		if (root_hd == NULL)
		{
			root_hd = (t_heredoc *)malloc(sizeof(t_heredoc));
			*root_hd = (t_heredoc){hd_texts[i][0], hd_texts[i][1], NULL};
			cur_hd = root_hd;
		}
		else
		{
			cur_hd->next = (t_heredoc *)malloc(sizeof(t_heredoc));
			*(cur_hd->next) = (t_heredoc){hd_texts[i][0], hd_texts[i][1], NULL};
			cur_hd = cur_hd->next;
		}
		i++;
	}
	print_hd_list(root_hd);
	printf("returned: %d\n", write_heredocs(root_hd));
}
