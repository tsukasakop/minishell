/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:01:31 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 20:08:01 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

int	ft_fputs(const char *s, t_file *stream)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		if (cnt == INT_MAX)
			return (EOF);
		if (ft_fputc(s[cnt], stream) == EOF)
			return (EOF);
		cnt++;
	}
	return (cnt);
}
