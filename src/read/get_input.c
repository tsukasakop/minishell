/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:49:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/23 16:38:11 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  Get input via prompt, and returns input
 *
 *  TODO:
 *   - check syntax, heredoc, lastpipe
 *   - get more input on heredoc, empty pipe
 *   - do exit command on ctrl + D
 */
char	*get_input(void)
{
	char	*input;

	if (g_signal == SIGINT)
		ft_fprintf(ft_stderr(), "\n");
	set_signal(0);
	set_handlers_for_prompt();
	input = readline(PROMPT);
	//TODO: check input syntax, heredoc, last pipe
	set_handlers_for_process();
	if (input)
		add_history(input);
	else
	{
		//TODO: replace exit function to builtin command
		builtin_exit((char *[2]){"exit", NULL});
		input = ft_strdup("exit");
	}
	return (input);
}
