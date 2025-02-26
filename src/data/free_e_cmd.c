/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_e_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:26:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/26 11:40:03 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * free memory of e_cmd
 */
void	free_e_cmd(char **e_cmd)
{
	int	i;

	i = 0;
	if (e_cmd == NULL)
		return ;
	while (e_cmd[i])
	{
		free(e_cmd[i]);
		i++;
	}
	free(e_cmd);
}
