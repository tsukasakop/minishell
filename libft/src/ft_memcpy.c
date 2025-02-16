/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:19:42 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/29 20:01:47 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*c_dst;
	const unsigned char	*c_src;

	c_src = (const unsigned char *)src;
	c_dst = (unsigned char *)dst;
	while (n && (dst || src))
	{
		c_dst[n - 1] = c_src[n - 1];
		n--;
	}
	return (dst);
}
