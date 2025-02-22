/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/22 18:58:22 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:add_struct_heredoc
 * ----------------------------
 * free memory of t_heredoc
 */

void	free_heredocs(t_heredoc *here)
{
	t_heredoc	*tmp;

	while (here)
	{
		tmp = here;
		free(here->eof);
		free(here->path);
		here = here->next;
		free(tmp);
	}
}

/*
 * Function:add_struct_heredoc
 * ----------------------------
 * Fill t_heredoc with data
 */
void	add_struct_heredoc(t_heredoc **here, char *eof, char *path)
{
	t_heredoc	*new;
	t_heredoc	*tmp;

	new = malloc(sizeof(t_heredoc));
	if (!new)
		return ;
	new->eof = ft_strdup(eof);
	new->path = ft_strdup(path);
	new->next = NULL;
	if (*here == NULL)
		*here = new;
	else
	{
		tmp = *here;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*
 * Function:add_struct_redirect
 * ----------------------------
 * Fill t_redirect with data.
 *
 * char *path = File path.
 * int type = The type of redirect (input, output, append).
 */
void	add_struct_redirect(t_redirect **reds, int type, char *path)
{
	t_redirect	*new;
	t_redirect	*tmp;

	new = malloc(sizeof(t_redirect));
	if (!new)
		return ;
	new->path = ft_strdup(path);
	new->red_type = type;
	new->next = NULL;
	if (*reds == NULL)
		*reds = new;
	else
	{
		tmp = *reds;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*
 * Function:parse_redirects
 * ----------------------------
 * parse the data to be filled in the structure for each redirection symbol.
 */

void	parse_redirects(t_redirect **reds, t_heredoc **here, \
						char *word, char *path)
{
	size_t	len;
	(void)here;

	len = ft_strlen(word);
	if ((ft_strnstr(word, "<<", len)))
	{
		// ToDo:ヒアドクがあった場合、ファイルを作成し、add_struct_heredoc関数を処理する機能が必要
		// open関数のために#include <fcntl.h>が必要
		// if (open("/tmp/test", O_WRONLY | O_TRUNC | O_CREAT, 0644) == -1)
		// 	perror(NULL);
		// add_struct_heredoc(here, path, "/tmp/test");
		add_struct_redirect(reds, REDIR_IN, path);
	}
	else if ((ft_strnstr(word, ">>", len)))
		add_struct_redirect(reds, REDIR_APPEND, path);
	else if ((ft_strnstr(word, "<", len)))
		add_struct_redirect(reds, REDIR_IN, path);
	else if ((ft_strnstr(word, ">", len)))
		add_struct_redirect(reds, REDIR_OUT, path);
}

/*
 * Function:has_redirect
 * ----------------------------
 * Returns true if there is a redirect, false if there is not.
 */
bool	has_redirect(char *word)
{
	size_t	len;

	len = ft_strlen(word);
	if (ft_strnstr(word, "<<", len) || ft_strnstr(word, "<", len) || \
		ft_strnstr(word, ">", len) || ft_strnstr(word, ">>", len))
		return (true);
	return (false);
}

/*
 * Function:fill_words
 * ----------------------------
 * Returns an array only strings without redirects.
 * ToDO:norminetteエラー
 */
char	**fill_words(char **src, int wc)
{
	char	**dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!dst)
		return (NULL);
	while (src[i])
	{
		if (has_redirect(src[i]) == true && src[i + 1])
			i++;
		else
		{
			dst[j] = ft_strdup(src[i]);
			if (!dst[j])
			{
				free_words(dst);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	dst[j] = NULL;
	return (dst);
}

/*
 * Function:
 * ----------------------------
 *
 *  Parses a simple command and returns a t_simple_cmd containing redirections and words.
 *
 */
t_simple_cmd	*load_simple_cmd(char **cmds_text)
{
	size_t				i;
	size_t				wc;
	t_simple_cmd		*scmd;
	t_heredoc			**here;

	here = NULL;
	scmd = malloc(sizeof(t_simple_cmd));
	if (!scmd)
		return (NULL);
	scmd->reds = NULL;
	scmd->next = NULL;
	i = 0;
	wc = 0;
	while (cmds_text[i])
	{
		if (has_redirect(cmds_text[i]) && cmds_text[i + 1])
		{
			parse_redirects(&scmd->reds, here, cmds_text[i], cmds_text[i + 1]);
			i++;
		}
		else
			wc++;
		i++;
	}
	scmd->words = fill_words(cmds_text, wc);
	free(cmds_text);
	return (scmd);
}

/*
 * Function:fill_struct_simple_cmd
 * ----------------------------
 * Parses const char *text and returns the head of the simple_cmd list.
 *
 * ToDO:norminetteエラー
 */
t_simple_cmd	*fill_struct_simple_cmd(const char *text)
{
	char			**cmds_text;
	t_simple_cmd	*head;
	t_simple_cmd	*current;
	t_simple_cmd	*new_cmd;
	int				i;

	cmds_text = pipe2simple_cmds(text);
	if (!cmds_text)
		return (NULL);
	i = 0;
	head = NULL;
	current = NULL;
	while (cmds_text[i])
	{
		new_cmd = load_simple_cmd(ft_split(cmds_text[i], ' '));
		if (!new_cmd)
		{
			free_simple_cmds(head);
			free(cmds_text);
			return (NULL);
		}
		if (!head)
			head = new_cmd;
		else
			current->next = new_cmd;
		current = new_cmd;
		i++;
	}
	free(cmds_text);
	return (head);
}
