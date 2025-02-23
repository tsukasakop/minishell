/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:43:26 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/23 16:37:32 by tkondo           ###   ########.fr       */
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
	ft_fprintf(ft_stderr(), "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
