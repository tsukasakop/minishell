/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:04:20 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/26 02:23:18 by miyuu            ###   ########.fr       */
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
	init(envp);
	while (true)
	{
		input = get_input();
		if (!input)
		{
			ft_g_mmfree();
			ft_exit(1);
		}
		last_status = eval_cmd_line(input, envp);
		set_exit_status(last_status);
		ft_g_mmfree();
	}
	return (0);
}
