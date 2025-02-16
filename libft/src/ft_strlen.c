/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:37:00 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/11 18:10:35 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	const char	*t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < maxlen && s[cnt])
		cnt++;
	return (cnt);
}
