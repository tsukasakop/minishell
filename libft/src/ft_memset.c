/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:57:52 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/09 05:14:21 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*c_b;

	ch = (unsigned char)c;
	c_b = (unsigned char *)b;
	while (len)
	{
		c_b[len - 1] = ch;
		len--;
	}
	return (b);
}
