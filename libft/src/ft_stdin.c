/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:59:44 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/23 19:09:26 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

#ifndef USE_STD_FILE_TYPE

t_file	*ft_stdin(void)
{
	static unsigned int	has_build;
	static t_file		f;

	if (!has_build)
	{
		ft_fset_fd(&f, STDIN_FILENO);
		has_build = 1;
	}
	return (&f);
}

#else

t_file	*ft_stdin(void)
{
	return (stdin);
}

#endif
