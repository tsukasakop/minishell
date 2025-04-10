/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_append_variable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:48:27 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/10 16:33:41 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: expand_and_append_variable
 * ----------------------------
 * Expands variables and concatenates the string to dst_buf.
 */
int	expand_and_append_variable(char **src_p, char **dst_buf)
{
	char	*var;
	char	*tmp;

	var = read_variable_m(src_p, dst_buf);
	if (var == NULL && errno == ENOMEM)
		return (-1);
	if (!var)
		return (1);
	tmp = ft_strnjoin(*dst_buf, var, ft_strlen(var));
	if (!tmp)
	{
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
		return (-1);
	}
	*dst_buf = tmp;
	return (0);
}
