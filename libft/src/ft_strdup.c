/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 05:07:23 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/20 02:44:04 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	return (ft_strndup(s1, ft_strlen(s1)));
}

char	*ft_strndup(const char *s1, size_t size)
{
	char	*p;

	p = malloc(size + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, size);
	ft_memset(p + size, 0, 1);
	return (p);
}
