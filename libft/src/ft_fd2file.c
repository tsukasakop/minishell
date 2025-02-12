/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd2file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:59:44 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/23 19:10:30 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

t_file	*ft_fd2file(int fd)
{
	t_file	*f;

	if (fd == 0)
		return (ft_stdin());
	if (fd == 1)
		return (ft_stdout());
	if (fd == 2)
		return (ft_stderr());
	f = ft_filenew();
	if (!f)
		return (NULL);
	ft_fset_fd(f, fd);
	return (f);
}
