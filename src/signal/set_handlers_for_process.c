/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_handlers_for_process.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:27:06 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/19 15:55:33 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  during system processing, catch signal and record it
 */
void	set_handlers_for_process(void)
{
	signal(SIGINT, set_signal);
	signal(SIGQUIT, set_signal);
}
