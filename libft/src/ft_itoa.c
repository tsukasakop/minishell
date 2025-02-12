/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:49:42 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/11 16:48:26 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	digit(int n)
{
	if (n / 10 == 0)
		return (1);
	return (digit(n / 10) + 1);
}

static void	set_digit(int n, char *p, size_t cur)
{
	p[cur] = n % 10 * ((n > 0) * 2 - 1) + '0';
	if (n / 10)
		set_digit(n / 10, p, cur - 1);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*p;

	len = digit(n) + (n < 0);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	if (n < 0)
		p[0] = '-';
	set_digit(n, p, len - 1);
	return (p);
}
