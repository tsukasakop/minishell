/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fset_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:57:25 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 20:03:55 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifndef USE_STD_FILE_TYPE

void	ft_fset_fd(t_file *f, int fd)
{
	f->_fd = fd;
}

#else

void	ft_fset_fd(t_file *f, int fd)
{
	(void)f;
	(void)fd;
}

#endif
