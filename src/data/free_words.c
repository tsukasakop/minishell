/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:26:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/24 13:53:07 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * free memory of words
 */
void	free_words(char **words)
{
	if (words == NULL)
		return ;
	while (*words)
	{
		free(*words);
		words++;
	}
	//ToDO:wordsの先頭をfreeする
}
