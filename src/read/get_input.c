/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:49:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 23:13:10 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  Get input via prompt, and returns input
 */
char	*get_input(void)
{
	char	*input;

	if (g_signal == SIGINT)
		ft_fprintf(ft_stderr(), "\n");
	set_signal(0);
	set_handlers_for_prompt();
	input = readline(PROMPT);
	set_handlers_for_process();
	if (input)
		add_history(input);
	else
		input = ft_strdup("exit");
	return (input);
}
