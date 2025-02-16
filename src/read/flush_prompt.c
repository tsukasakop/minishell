/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:43:26 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 20:43:36 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	flush_prompt(void)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
