/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ecmd.c                                       :+:      :+:    :+:   */
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
 * free memory of ecmd
 */
void	free_ecmd(char **ecmd)
{
	int	i;

	i = 0;
	if (ecmd == NULL)
		return ;
	while (ecmd[i])
	{
		free(ecmd[i]);
		i++;
	}
	free(ecmd);
}
