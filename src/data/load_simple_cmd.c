/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/21 18:44:27 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
//open関数のために追加
#include <fcntl.h>
// typedef struct			s_simple_cmd
// {
// 	t_redirect		*reds;
// 	char			**words;
// 	t_simple_cmd	*next;
// }				t_simple_cmd;

// struct					s_redirect
// {
// 	enum	{ REDIR_IN, REDIR_OUT, REDIR_APPEND } redirect_type;
// 	int							fd_redirect_from;//←リダイレクトの左 n>	int型？
// 	const char					*path;//←リダイレクトの右 >word
// 	t_redirect					*next;
// }			t_redirect;


// struct					s_heredoc
// {
// 	char			*eof;
// 	char			*path;
// 	t_heredoc		*next;
// }				t_heredoc;

// void	stderror_msg(char *msg)
// {
// 	write(2, msg, ft_strlen(msg));
// 	exit(1);
// }

void	free_new_redirects(t_redirect *reds)
{
	t_redirect	*tmp;

	while (reds != NULL)
	{
		free((char *)reds->path);
		tmp = reds;
		reds = reds->next;
		free(tmp);
	}
}


// /*
//  * Function:add_struct_heredoc
//  * ----------------------------
//  * ヒアドクの構造体にデータを格納する関数
//  */
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
	t_redirect	*new_red;
	t_redirect	*tmp;

	new_red = malloc(sizeof(t_redirect));
	if (!new_red)
		return ;
	new_red->path = ft_strdup(path);
	new_red->redirect_type = type;
	new_red->next = NULL;
	if (*reds == NULL)
		*reds = new_red;
	else
	{
		tmp = *reds;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_red;
	}
}

// /*
//  * Function:fill_struct_redirect
//  * ----------------------------
//  * リダイレクトの記号ごとに、構造体redirect&構造体heredocにデータを格納する関数
//  */
void	fill_struct_redirect(t_redirect **reds, t_heredoc **here, char *word, char *path)
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


// /*
//  * Function:has_redirect
//  * ----------------------------
//  * リダイレクトの記号がある場合はture
//  * ない場合はfalseになる
//  * ToDO:これ間違ってるかも
//  */
bool	has_redirect(char *word)
{
	size_t	len;

	len = ft_strlen(word);
	if (ft_strnstr(word, "<<", len) || ft_strnstr(word, "<", len) || \
		ft_strnstr(word, ">", len) || ft_strnstr(word, ">>", len))
		return (true);
	return (false);
}


// /*
//  * Function:fill_words
//  * ----------------------------
//  * wordsを埋める関数を作る
//  * wc分mallocして、has_redirectでfalseの文字列を格納する
//  */
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
void	load_simple_cmd(t_simple_cmd *cmd, t_redirect **reds, \
		t_heredoc **here, char **cmds_text)
{
	size_t				i;
	size_t				wc;
	// TODO: extract redirects into reds
	// TODO: split correctly
	// *words = ft_split(cmds_text, ' ');
	i = 0;
	wc = 0;
	while (cmds_text[i])
	{
		if (has_redirect(cmds_text[i]) == true && cmds_text[i + 1])
		{
			fill_struct_redirect(reds, here, cmds_text[i], cmds_text[i + 1]);
			i++;
		}
		else
			wc++;
		i++;
	}
	cmd->words = fill_words(cmds_text, wc);
}


int	main(int argc, char **argv, char **envp)
{
	t_redirect			*reds;
	// // char				**words;
	t_simple_cmd	cmds[3];
	t_heredoc	*here;
	char			*text;
	char		**cmds_text;
	int					i;
	(void)argc;
	(void)argv;
	(void)envp;

	// text = "echo 45 >out>outfile | ls >out";
	int	m = 0;
	while(m < 3)
	{
		if (m == 0)
		text = "< infile cat | grep 42 > outfile | < IN cat > OUT ";
		if (m == 1)
		text = "echo 42";
		if (m == 2)
		text = "ls | wc -c >> outfile ";
		printf("text = %s\n", text);
		cmds_text = pipe2simple_cmds(text);
		i = 0;
		while (cmds_text[i])
		{
			printf("---- cmds_text[%d] = %s ----\n", i, cmds_text[i]);
			reds = NULL;
			load_simple_cmd(&cmds[i], &reds, &here, ft_split(cmds_text[i], ' '));
			int	c = 0;
			while (reds)
			{
				printf("%d...redirect_type:%u, path: %s\n", c++, reds->redirect_type, reds->path);
				reds = reds->next;
			}
			int	j = 0;
			while (cmds[i].words[j] != NULL)
			{
				printf("words[%d]:%s\n", j, cmds[i].words[j]);
				free(cmds[i].words[j]);
				j++;
			}
			free(cmds[i].words);
			free_new_redirects(reds);
			i++;
		}
		free(cmds_text);
		printf("\n");
		m++;
	}
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
