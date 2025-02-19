/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/19 18:47:03 by miyuu            ###   ########.fr       */
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

bool	has_redirect(char *word)
{
	size_t	len;

	len = ft_strlen(word);
	if (ft_strnstr(word, "<<", len))
		return (true);
	if (ft_strnstr(word, "<", len))
		return (true);
	if (ft_strnstr(word, ">", len))
		return (true);
	if (ft_strnstr(word, ">>", len))
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
	// TODO: extract redirects into reds
	// TODO: split correctly
	*words = ft_split(cmd, ' ');
	i = 0;
	while ((*words)[i])
	{
		if (has_redirect((*words)[i]) == true)
			printf("red:words[%zu] = %s\n", i, (*words)[i]);
		else
			printf("words:words[%zu] = %s\n", i, (*words)[i]);
		i++;
	}
	(void)reds;
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

	text = "< infile cat | grep 42 > outfile";
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
