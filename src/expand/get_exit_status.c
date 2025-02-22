/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:40:13 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/21 18:34:04 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Get exit status
 */
unsigned char	get_exit_status(void)
{
	unsigned char	*st_ptr;

	st_ptr = get_exit_status_p();
	return (*st_ptr);
}
