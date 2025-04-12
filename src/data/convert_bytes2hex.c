/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bytes2hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:29:11 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/12 20:41:30 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:convert_bytes2hex
 * ----------------------------
 * Converts an array of bytes into a hexadecimal string.
 *
 * bytes: pointer to the byte array
 * len: length of the byte array
 */
char	*convert_bytes2hex(unsigned char *bytes, size_t len)
{
	char	*hex_base;
	char	*hex_out;
	size_t	i;

	hex_base = "0123456789abcdef";
	hex_out = ft_g_mmmalloc(len * 2 + 1);
	if (!hex_out)
	{
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
		return (NULL);
	}
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
