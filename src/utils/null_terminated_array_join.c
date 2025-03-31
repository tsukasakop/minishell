/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_terminated_array_join.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:27:04 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
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
	size_t	i;
	size_t	j;
	void	**ptr;

	dstlen = null_terminated_array_len(dst);
	srclen = null_terminated_array_len(src);
	ptr = ft_g_mmmalloc(sizeof(void *) * (dstlen + srclen + 1));
	if (ptr == NULL)
	{
		set_error_type(ERR_SYSCALL);
		perror_with_shellname(NULL);
		return (NULL);
	}
	i = 0;
	while (i < dstlen)
	{
		ptr[i] = dst[i];
		i++;
	}
	j = 0;
	while (j < srclen)
	{
		ptr[i + j] = src[j];
		j++;
	}
	ptr[i + j] = NULL;
	return (ptr);
}
