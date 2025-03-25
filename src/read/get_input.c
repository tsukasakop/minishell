/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:49:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/25 23:03:05 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  Get input via prompt, and returns input
 * //TODO: get_input関数で、malloc失敗したらどうする？終了ステータスセットする必要あるのか？
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
		return (perror_return_null(NULL));
	set_handlers_for_process();
	if (input)
		add_history(input);
	else
	{
		input = ft_g_mmadd(ft_strdup("exit"));
		if (!input)
			return (perror_return_null(NULL));
	}
	return (input);
}
