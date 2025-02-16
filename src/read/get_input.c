/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:49:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 21:08:13 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_input(void)
{
	char	*input;

	input = readline(PROMPT);
	if (input)
		add_history(input);
	else
		input = ft_strdup("exit");
	return (input);
}
