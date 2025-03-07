/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_null_terminated_arrar.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:09:20 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/05 14:09:24 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  free null-terminated-array.
 */
void	free_null_terminated_array(void **arr)
{
	void	**bak;

	if (arr == NULL)
		return ;
	bak = arr;
	while (*arr != NULL)
	{
		free(*arr);
		arr++;
	}
	free(bak);
}
