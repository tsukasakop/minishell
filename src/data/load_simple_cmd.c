/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/22 01:30:36 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
//open関数のために追加
#include <fcntl.h>

// void	stderror_msg(char *msg)
// {
// 	write(2, msg, ft_strlen(msg));
// 	exit(1);
// }

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

void	free_new_redirects(t_redirect *reds)
{
	t_redirect	*tmp;

	while (reds)
	{
		tmp = reds;
		free((char *)reds->path);
		reds = reds->next;
		free(tmp);
	}
}

void	free_simple_cmd(t_simple_cmd *cmds)
{
	t_simple_cmd	*tmp;

	while (cmds)
	{
		tmp = cmds;
		free_words(cmds->words);
		free(cmds->words);
		free_new_redirects(cmds->reds);
		cmds = cmds->next;
		free(tmp);
	}
}


/*
 * Function:add_struct_heredoc
 * ----------------------------
 * ヒアドクの構造体にデータを格納する関数
 */
// void	add_struct_heredoc(t_heredoc **here, char *eof, char *path)
// {
// 	//ToDo:作る

// 	t_heredoc	*new;
// 	t_heredoc	*tmp;

// 	new = malloc(sizeof(t_heredoc));
// 	if (!new)
// 		return ;
// 	new->eof = ft_strdup(eof);
// 	new->path = ft_strdup(path);
// 	new->next = NULL;
// 	if (*here == NULL)
// 		*here = new;
// 	else
// 	{
// 		tmp = *here;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 	}
// }

void	add_struct_redirect(t_redirect **reds, int type, char *path)
{
	t_redirect	*new;
	t_redirect	*tmp;

	new = malloc(sizeof(t_redirect));
	if (!new)
		return ;
	new->path = ft_strdup(path);
	new->redirect_type = type;
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
 * リダイレクトの記号ごとに、構造体redirect&構造体heredocにデータを格納する関数
 */
void	parse_redirects(t_redirect **reds, t_heredoc **here, char *word, char *path)
{
	size_t	len;
	(void)here;

	len = ft_strlen(word);
	if ((ft_strnstr(word, "<<", len)))
	{
		if (open("/tmp/test", O_WRONLY | O_TRUNC | O_CREAT, 0644) == -1)
			perror(NULL);
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
 * リダイレクトの記号がある場合はture
 * ない場合はfalseになる
 * ToDO:これ間違ってるかも
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
 * wordsを埋める関数を作る
 * wc分mallocして、has_redirectでfalseの文字列を格納する
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
 * Read simple command and divide tokens to redirect and the others
 *
 * const t_simple_cmd cmd: object to split
 * t_redirect **reds: pointer to store redirects info
 * char ***wirds: pointer to store command and its arguments
 *
 */
t_simple_cmd	*load_simple_cmd(char **cmds_text)
{
	size_t				i;
	size_t				wc;
	// TODO: extract redirects into reds
	// TODO: split correctly
	t_simple_cmd *cmd;
	t_heredoc	**here;

	here = NULL;
	cmd = malloc(sizeof(t_simple_cmd));
	if (!cmd)
		return (NULL);
	cmd->reds = NULL;
	cmd->next = NULL;

	i = 0;
	wc = 0;
	while (cmds_text[i])
	{
		if (has_redirect(cmds_text[i]) && cmds_text[i + 1])
		{
			parse_redirects(&cmd->reds, here, cmds_text[i], cmds_text[i + 1]);
			i++;
		}
		else
			wc++;
		i++;
	}
	cmd->words = fill_words(cmds_text, wc);
	free(cmds_text);
	return (cmd);
}


t_simple_cmd	*fill_struct_simple_cmd(char *text)
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
			free_simple_cmd(head);
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

void	print_commands(t_simple_cmd *cmds)
{
	int i = 0;

	while (cmds)
	{
		printf("Command[%d]:\n", i++);
		printf("  words:");
		for (int j = 0; cmds->words[j]; j++)
			printf(" %s,", cmds->words[j]);
		printf("\n");
		t_redirect *red = cmds->reds;
		while (red)
		{
			printf("  Redirect: type=%d, path=%s\n", red->redirect_type, red->path);
			red = red->next;
		}
		cmds = cmds->next;
	}
}

#include <stdlib.h>
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char *text[] = {
		"< infile cat | grep 42 > outfile | < IN cat > OUT",
		"echo 42",
		"ls | wc -c >> outfile"
	};
	// text = "echo 45 >out>outfile | ls >out";
	int	i = 0;
	while (i < 3)
	{
		printf("text = %s\n", text[i]);
		t_simple_cmd *cmd_list = fill_struct_simple_cmd(text[i]);
		print_commands(cmd_list);
		free_simple_cmd(cmd_list);
		printf("\n");
		i++;
	}
	// system("leaks minishell");
	return (0);
}

/*
 * ```bash
 * $ < infile cat | grep 42 > outfile　←入力
 * text = "< infile cat | grep 42 > outfile"
 *
 * cmds = pipe2simple_cmds(text);の後
 * cmds = < infile cat
 * cmds =  grep 42 > outfile
 * ```
 *
 * ToDo
 * reds
 * 	→ red:<
 * 	→path:infile
 * *words[0]:cat
 *
 * 2回目のwhile
 * reds
 * 	→ red:>
 * 	→path:outfile
 * *words[0]:grep
 * *words[1]:42
 */
