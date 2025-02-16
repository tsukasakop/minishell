/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:02:25 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 19:09:32 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

size_t	ft_fwrite(const void *ptr, size_t size, size_t nitems, t_file *stream)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < nitems)
	{
		while (j < size)
		{
			if (ft_fputc(((unsigned char *)ptr)[size * i + j], stream) == EOF)
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
