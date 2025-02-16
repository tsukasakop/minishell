/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:05:24 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 20:05:46 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifndef USE_STD_FILE_TYPE

int	ft_fflush(t_file *stream)
{
	(void)stream;
	return (0);
}

#else

int	ft_fflush(t_file *stream)
{
	return (fflush(stream));
}

#endif
