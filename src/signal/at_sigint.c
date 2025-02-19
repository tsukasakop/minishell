/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_sigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:45:42 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/19 15:51:34 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  do when catch sigint on prompt
 */
void	at_sigint(int signal)
{
	(void)signal;
	flush_prompt();
}
