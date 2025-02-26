/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write_heredocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:39:47 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/26 12:39:50 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(void)
{
	t_heredoc	*hd;

	hd = (t_heredoc *)malloc(sizeof(t_heredoc));
	*hd = (t_heredoc){"EOF", "/tmp/eof", NULL};
	hd->next = (t_heredoc *)malloc(sizeof(t_heredoc));
	*(hd->next) = (t_heredoc){"AIUEO", "/tmp/aiueo", NULL};
	hd->next->next = (t_heredoc *)malloc(sizeof(t_heredoc));
	*(hd->next->next) = (t_heredoc){"EOF", "/tmp/eof2", NULL};
	return (write_heredocs(hd));
}
