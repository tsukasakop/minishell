/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:19:13 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 20:02:39 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifndef USE_STD_FILE_TYPE

int	ft_fputc(int c, t_file *stream)
{
	if (write(ft_fileno(stream), &c, 1) == -1)
		return (EOF);
	return (c);
}

#else

int	ft_fputc(int c, t_file *stream)
{
	return (fputc(c, stream));
}

#endif
