/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:40:13 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/21 18:33:42 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Set exit status use as $?
 *
 * unsigned char st: exit status
 */
void	set_exit_status(unsigned char st)
{
	unsigned char	*st_ptr;

	st_ptr = get_exit_status_p();
	*st_ptr = st;
}
