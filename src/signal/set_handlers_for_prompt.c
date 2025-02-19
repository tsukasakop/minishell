/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_handlers_for_prompt.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:27:06 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/19 15:56:15 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  during waiting user input, reflesh prompt on SIGINT
 */
void	set_handlers_for_prompt(void)
{
	signal(SIGINT, at_sigint);
	signal(SIGQUIT, SIG_IGN);
}
