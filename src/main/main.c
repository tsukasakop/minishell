/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:04:20 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/19 15:46:41 by tkondo           ###   ########.fr       */
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
		last_status = eval_text(input, envp);
		set_exit_status(last_status);
		free(input);
	}
	return (0);
}
