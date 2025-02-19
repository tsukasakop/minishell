/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_handlers_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:27:06 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/19 15:54:35 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  unset signal handlers, typically use for init childprocess
 */
void	set_handlers_default(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
