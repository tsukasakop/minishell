/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:20:31 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/31 01:56:08 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

int	ft_fprintf(t_file *s, const char *format, ...)
{
	va_list	args;
	int		n;

	va_start(args, format);
	n = ft_vfprintf(s, format, args);
	va_end(args);
	return (n);
}
