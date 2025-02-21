/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/20 17:10:39 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// struct							s_redirect
// {
// 	//リダイレクトの種類(<,>,<<,>>)
// 	const char					*path;//リダイレクトの右 >word
// 	//リダイレクトの左 n>	int型？
// 	t_redirect					*next;
// };

//

// struct							s_redirect
// {
// 	int							type;
// 	const char					*in_path;
// 	int							out_fd;
// 	t_redirect					*next;
// };

struct							s_redirect
{
	int							fd_redirect_from;//←リダイレクトの左 n>	int型？
	char							*redirect_type;//←enumでやってみる。ヒアドクでも<でやる
	redirect_type				red_type;
	const char					*path;//←リダイレクトの右 >word
	t_redirect					*next;
};

typedef enum enm {
  Mon,
  Tue,
  Wed,
  Thu,
  Fri,
  Sat,
  Sun
} redirect_type;


//todo:ヒアドク用の構造体作る
void	stderror_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	free_new_redirects(t_redirect *reds)
{
	t_redirect	*tmp;

	while (reds != NULL)
	{
		free((char *)reds->path);
		free((char *)reds->redirect_type);
		tmp = reds;
		reds = reds->next;
		free(tmp);
	}
}

void	fill_struct_redirect(char *type, char *path, t_redirect **reds)
{
	t_redirect	*new_red;
	t_redirect	*tmp;

	new_red = malloc(sizeof(t_redirect));
	if (!new_red)
		return ;
	new_red->path = ft_strdup(path);
	new_red->redirect_type = ft_strdup(type);
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

bool	has_redirect(char *word)
{
	size_t	len;

	len = ft_strlen(word);
	if (ft_strnstr(word, "<<", len))
		return (true);
	if (ft_strnstr(word, ">>", len))
		return (true);
	if (ft_strnstr(word, "<", len))
		return (true);
	if (ft_strnstr(word, ">", len))
		return (true);
	return (false);
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
 * ex) cmd =
 */
void	load_simple_cmd(const t_simple_cmd cmd, t_redirect **reds,
		char ***words)
{
	size_t				i;
	(void)reds;
	// TODO: extract redirects into reds
	// TODO: split correctly
	*words = ft_split(cmd, ' ');
	i = 0;
	while ((*words)[i])
	{
		if (has_redirect((*words)[i]))
		{
			if ((*words)[i + 1] != NULL)
			{
				fill_struct_redirect((*words)[i], (*words)[i + 1], reds);
				i++;
			}
			else
				stderror_msg("syntax error");
		}
		else
			printf("words:words[%zu] = %s\n", i, (*words)[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_redirect			*reds;
	char				**words;
	const t_simple_cmd	*cmds;
	const char			*text;
	int					i;
	// int					j;
	(void)argc;
	(void)argv;
	(void)envp;

	text = "< infile cat | grep 42 > outfile | < IN cat > OUT ";
	// text = "echo 45 >out>outfile | ls >out";
	cmds = pipe2simple_cmds(text);
	i = 0;
	while (cmds[i])
	{
		printf("cmds[%d] = %s\n", i, cmds[i]);
		reds = NULL;
		load_simple_cmd(cmds[i], &reds, &words);
		while (reds)
		{
			printf("%d = redirect_type:%s, path: %s\n", i, reds->redirect_type, reds->path);
			reds = reds->next;
		}
		i++;
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
