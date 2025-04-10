/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:49:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 16:56:41 by miyuu            ###   ########.fr       */
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
		ft_putstr_fd("\n", STDERR_FILENO);
	set_signal(0);
	set_handlers_for_prompt();
	errno = 0;
	input = get_readline_safely(PROMPT);
	if (input == NULL && errno == ENOMEM)
		return (NULL);
	set_handlers_for_process();
	if (input)
		add_history(input);
	else
	{
		input = ft_g_mmadd(ft_strdup("exit"));
		if (!input)
		{
			set_error_type(ERR_SYSCALL);
			print_errmsg_with_str(EM_SYSCALL, NULL);
			return (NULL);
		}
	}
	return (input);
}
