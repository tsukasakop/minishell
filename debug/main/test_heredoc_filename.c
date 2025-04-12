/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heredoc_filename.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:39:47 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/12 17:33:16 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*bytes_to_hex(unsigned char *bytes, int len)
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

char	*new_create_random_filename(int fd_random)
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
		printf("bytes_to_hex : %s\n", hex_str);
		filename = ft_strjoin("/tmp/heredoc_", hex_str);
		if (!filename)
			close(fd_random);

		new_fd = open(filename, O_CREAT | O_EXCL, 0600);
	}
	close(new_fd);
	return (filename);
}

char	*new_create_tmp_file(void)
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
	filename = new_create_random_filename(fd_random);
	close(fd_random);
	return (filename);
}

// **📝 テスト実行**
int	main(void)
{
	char	*filename;

	filename = new_create_tmp_file();
	printf("%s\n", filename);
	free(filename);

	return (0);
}
