/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 01:20:58 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/11 01:10:24 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	s_needle;
	size_t	i;
	size_t	j;
	size_t	s_haystack;

	if (len == 0)
	{
		if (haystack && *needle == '\0')
			return ((char *)haystack);
		else
			return (NULL);
	}
	i = 0;
	s_haystack = ft_strlen(haystack);
	s_needle = ft_strlen(needle);
	while (i + s_needle <= s_haystack && i + s_needle <= len)
	{
		j = 0;
		while (j < s_needle && haystack[i + j] == needle[j])
			j++;
		if (j == s_needle)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
