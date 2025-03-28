/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:49:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/28 18:39:53 by mfunakos         ###   ########.fr       */
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
	errno = 0;
	input = ft_g_mmadd(readline(PROMPT));
	if (input == NULL && errno == ENOMEM)
	{
		set_error_type(ERR_SYSCOLL);
		perror_with_shellname(NULL);
		return (NULL);
	}
	set_handlers_for_process();
	if (input)
		add_history(input);
	else
	{
		input = ft_g_mmadd(ft_strdup("exit"));
		if (!input)
		{
			set_error_type(ERR_SYSCOLL);
			perror_with_shellname(NULL);
			return (NULL);
		}
	}
	return (input);
}
