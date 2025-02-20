/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/20 15:49:07 by mfunakos         ###   ########.fr       */
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


// struct							s_redirect
// {
// 	int							fd_redirect_from;//←リダイレクトの左 n>	int型？
// 	int							redirect_type;//←enumでやってみる。ヒアドクでも<でやる
// 	const char					*path;//←リダイレクトの右 >word
// 	t_redirect					*next;
// };

//todo:ヒアドク用の構造体作る


void	stderror_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

// void	redirect(char *word)
// {
// 	int	i;

// 	i = 0;
// 	while (word[i] != NULL && word[i] != '>' && word[i] != NULL && word[i] != NULL)
// 	{
// 		if ()

// 	}
// }


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
			printf("red:words[%zu] = %s\n", i, (*words)[i]);
			if ((*words)[i + 1] != NULL)
			{
				printf("red:path[%zu] = %s\n", i + 1, (*words)[i + 1]);
				// t_redirect *new_red = malloc(sizeof(t_redirect));
				// if (!new_red)
				// 	return;
				// new_red->path = strdup((*words)[i + 1]);
				// new_red->next = NULL;

				// // `reds` に追加
				// if (*reds == NULL)
				// 	*reds = new_red;
				// else
				// {
				// 	t_redirect *tmp = *reds;
				// 	while (tmp->next)
				// 		tmp = tmp->next;
				// 	tmp->next = new_red;
				// }
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

	text = "< infile cat | grep 42 > outfile | ls >out";
	// text = "echo 45 >out>outfile";
	cmds = pipe2simple_cmds(text);
	i = 0;
	printf("cmds[%d] = %s\n", i, cmds[i]);
	while (cmds[i])
	{
		reds = NULL;
		load_simple_cmd(cmds[i], &reds, &words);
		// j = 0;
		// while (words[j])
		// {
		// 	printf("words[%d] = %s\n", j, words[j]);
		// 	j++;
		// }
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
