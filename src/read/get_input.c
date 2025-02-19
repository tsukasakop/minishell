/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:49:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/19 15:40:46 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_input(void)
{
	char	*input;

	if (g_signal == SIGINT)
		printf("\n");
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
		exit(0);
		input = ft_strdup("exit");
	}
	return (input);
}
