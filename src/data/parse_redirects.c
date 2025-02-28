/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:26 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/28 19:47:45 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	has_from_fd(char *cmds_text, int i)
{
	int	m;

	m = i;
	while (i > 0 && ft_isdigit(cmds_text[i - 1]))
		i--;
	if (i < m)
		return (ft_atoi(&cmds_text[i]));
	if (cmds_text[i] == '<')
		return (0);
	else if (cmds_text[i] == '>')
		return (1);
	return (-1);
}

char	*get_redirect_path(char *redir_symbol, char *next_word)
{
	char	*next;
	size_t	len;
	char	*path;

	while (*redir_symbol && (*redir_symbol == '>' || *redir_symbol == '<'))
		redir_symbol++;
	if (!*redir_symbol)
		return (next_word);

	next = has_redirect(redir_symbol);

	if (!next)
		return (redir_symbol);

	len = next - redir_symbol;
	path = strndup(redir_symbol, len);
	return (path);
}

/*
 * Function:parse_redirects
 * ----------------------------
 * parse the data to be filled in the structure for each redirection symbol.
 * ToDo:ヒアドクがあった場合、ファイルを作成し、add_struct_heredoc関数を処理する機能が必要
 * open関数のために#include <fcntl.h>が必要
 * if (open("/tmp/test", O_WRONLY | O_TRUNC | O_CREAT, 0644) == -1)
 *  perror(NULL);
 * add_struct_heredoc(here, path, "/tmp/test")
 */
void	parse_redirects(t_redirect **redir, t_heredoc **hd, \
						char *word, char *next_word)
{
	int		from_fd;
	char	*redir_symbol;
	char	*path;

	(void)hd;
	redir_symbol = has_redirect(word);
	while (redir_symbol)
	{
		from_fd = has_from_fd(word, redir_symbol - word);
		path = get_redirect_path(redir_symbol, next_word);
		printf("redir_symbol = %p, word = %p, i = %ld\n", redir_symbol, word, redir_symbol - word);
		printf("redir_symbol = %s, from_fd = %d, path = %s, \n", redir_symbol, from_fd, path);

		if ((ft_strncmp(redir_symbol, "<<", 2)) == 0)
		{
			add_struct_redirect(redir, REDIR_IN, path);
		}
		else if ((ft_strncmp(redir_symbol, ">>", 2)) == 0)
			add_struct_redirect(redir, REDIR_APPEND, path);
		else if ((ft_strncmp(redir_symbol, "<", 1)) == 0)
			add_struct_redirect(redir, REDIR_IN, path);
		else if ((ft_strncmp(redir_symbol, ">", 1)) == 0)
			add_struct_redirect(redir, REDIR_OUT, path);

		while (*redir_symbol && (*redir_symbol == '>' || *redir_symbol == '<'))
			redir_symbol++;
		redir_symbol = has_redirect(redir_symbol);
	}

}
