/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate_null_terminated_array.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:59:46 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/10 16:58:34 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: concatenate_null_terminated_array
 * ----------------------------
 * Concatenates two NULL-terminated arrays into a newly allocated array.
 */
void	**concatenate_null_terminated_array(void **dst, size_t	dstlen, \
									void **src, size_t	srclen)
{
	void	**ptr;
	size_t	i;
	size_t	j;

	ptr = ft_g_mmmalloc(sizeof(void *) * (dstlen + srclen + 1));
	if (ptr == NULL)
	{
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
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
