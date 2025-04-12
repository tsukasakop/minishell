/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc_randfile.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:31:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/12 20:39:20 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:create_heredoc_randfile
 * ----------------------------
 * Create a unique /tmp/heredoc_<hex> filename using random bytes
 *
 * fd_random: file descriptor for /dev/urandom
 */
char	*create_heredoc_randfile(int fd_random)
{
	int				new_fd;
	char			*filename;
	unsigned char	rand_bytes[4];
	char			*hex_str;

	new_fd = -1;
	while (new_fd == -1)
	{
		if (read(fd_random, rand_bytes, sizeof(rand_bytes)) \
										!= sizeof(rand_bytes))
			close(fd_random);
		hex_str = convert_bytes2hex(rand_bytes, 4);
		if (hex_str == NULL)
			return (NULL);
		filename = ft_g_mmadd(ft_strjoin(HEREDOC_TMP_PREFIX, hex_str));
		if (!filename)
		{
			set_error_type(ERR_SYSCALL);
			print_errmsg_with_str(EM_SYSCALL, NULL);
			return (NULL);
		}
		new_fd = open(filename, O_CREAT | O_EXCL, 0600);
	}
	close(new_fd);
	return (filename);
}
