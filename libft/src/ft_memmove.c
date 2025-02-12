/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:19:42 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/09 05:14:13 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*c_dst;
	const unsigned char	*c_src;
	char				sign;
	size_t				cur;

	c_src = (const unsigned char *)src;
	c_dst = (unsigned char *)dst;
	sign = (dst < src) * 2 - 1;
	cur = (sign == -1) * len;
	while (cur != (sign == 1) * len && (dst || src))
	{
		c_dst[cur - (sign == -1)] = c_src[cur - (sign == -1)];
		cur += sign;
	}
	return (dst);
}
