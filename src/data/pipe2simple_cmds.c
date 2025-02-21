/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2simple_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:23:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/21 17:36:43 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Expand pipeline string and returns array of simple commands
 *
 * const char *pipe: string on pipeline
 */
// t_simple_cmd	*pipe2simple_cmds(const char *pipe)
// {
// 	return (ft_split(pipe, '|'));
// }

char	**pipe2simple_cmds(const char *pipe)
{
	return (ft_split(pipe, '|'));
}
