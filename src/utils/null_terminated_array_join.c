/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_terminated_array_join.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:27:04 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 16:58:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: null_terminated_array_join
 * ----------------------------
 *  join dst and src and returns freeable pointer
 *  NOTE: this function will not mutate dst and src
 */
void	**null_terminated_array_join(void **dst, void **src)
{
	size_t	dstlen;
	size_t	srclen;
	void	**ptr;

	dstlen = null_terminated_array_len(dst);
	srclen = null_terminated_array_len(src);
	ptr = concatenate_null_terminated_array(dst, dstlen, src, srclen);
	return (ptr);
}
