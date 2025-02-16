/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:26:32 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 20:16:39 by tkondo           ###   ########.fr       */
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
}
