/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:37:01 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/11 16:48:52 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putabsnbr_fd(int n, int fd)
{
	char	c;

	if (n / 10)
		ft_putabsnbr_fd(n / 10, fd);
	c = '0' + (n % 10) * ((n > 0) * 2 - 1);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	write(fd, "-", n < 0);
	ft_putabsnbr_fd(n, fd);
}
