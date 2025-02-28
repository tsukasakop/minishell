/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:04:20 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 18:47:16 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

volatile unsigned char	g_signal = 0;

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	unsigned char	last_status;

	(void)argc;
	(void)argv;
	init();
	while (true)
	{
		input = get_input();
		last_status = eval_cmd_line(input, envp);
		if (g_signal)
			last_status = 128 + g_signal;
		set_exit_status(last_status);
		free(input);
	}
	return (0);
}
