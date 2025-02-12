/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:50:13 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 20:01:11 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifdef USE_STD_FILE_TYPE

int	ft_fileno(t_file *stream)
{
	return (fileno(stream));
}

#else

int	ft_fileno(t_file *stream)
{
	return (stream->_fd);
}

#endif
