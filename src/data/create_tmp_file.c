/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmp_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:43:09 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/12 18:01:33 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*bytes_to_hex(unsigned char *bytes, size_t len)
{
	const char	*hex_base;
	char		*hex_out;
	size_t		i;

	hex_base = "0123456789abcdef";
	hex_out = ft_g_mmadd(malloc(len * 2 + 1));
	if (!hex_out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		hex_out[i * 2] = hex_base[(bytes[i] >> 4) & 0xF];
		hex_out[i * 2 + 1] = hex_base[bytes[i] & 0xF];
		i++;
	}
	hex_out[len * 2] = '\0';
	return (hex_out);
}

char	*create_random_filename(int fd_random)
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
		hex_str = bytes_to_hex(rand_bytes, 4);
		filename = ft_strjoin("/tmp/heredoc_", hex_str);
		if (!filename)
			close(fd_random);
		new_fd = open(filename, O_CREAT | O_EXCL, 0600);
	}
	close(new_fd);
	return (filename);
}

char	*create_tmp_file(void)
{
	int				fd_random;
	char			*filename;

	fd_random = open("/dev/urandom", O_RDONLY);
	if (fd_random == -1)
	{
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
		return (NULL);
	}
	filename = create_random_filename(fd_random);
	close(fd_random);
	return (filename);
}

/*
 * Function:create_tmp_file
 * ----------------------------
 * Creates a unique /tmp/heredoc_* file and returns its path.
 */
// char	*create_tmp_file(void)
// {
// 	int		count;
// 	char	*filename;
// 	int		fd;

// 	count = 0;
// 	filename = NULL;
// 	fd = -1;
// 	while (fd == -1)
// 	{
// 		filename = ft_g_mmadd(ft_strjoin("/tmp/heredoc_",
// 					ft_g_mmadd(ft_itoa(count++))));
// 		if (!filename)
// 		{
// 			set_error_type(ERR_SYSCALL);
// 			print_errmsg_with_str(EM_SYSCALL, NULL);
// 			return (NULL);
// 		}
// 		fd = open(filename, O_CREAT | O_EXCL, 0600);
// 	}
// 	close(fd);
// 	return (filename);
// }
