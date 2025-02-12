/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:26:27 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/11 01:09:57 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	c;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
		c = src_len + 1;
	else
		c = dstsize;
	if (c)
	{
		ft_memcpy(dst, src, c - 1);
		dst[c - 1] = '\0';
	}
	return (src_len);
}
