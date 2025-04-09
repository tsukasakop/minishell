/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:43:26 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/06 19:02:40 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  delete written input and reflesh prompt
 */
void	flush_prompt(void)
{
	ft_putstr_fd("\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
