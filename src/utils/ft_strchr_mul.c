/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_mul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:07:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/05 14:07:34 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  returns place where character in $targets appears first on s.
 */
char	*ft_strchr_mul(const char *s, char *targets, size_t target_len)
{
	size_t	i;

	while (true)
	{
		i = 0;
		while (i < target_len)
		{
			if (*s == targets[i])
				return ((char *)s);
			i++;
		}
		if (*s == '\0')
			return (NULL);
		s++;
	}
}
