/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:04:20 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 21:03:16 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
		if (last_status == SIGINT + EXIT_OFFSET_SIGNAL)
			printf("\n");
		set_exit_status(last_status);
		free(input);
	}
	return (0);
}
