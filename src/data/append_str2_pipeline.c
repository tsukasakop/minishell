/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str2_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:17 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/19 19:55:56 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:append_str2_pipeline
 * ----------------------------
 * Extracts len size of text from start.
 * And appends it to the pipeline.
 */
void	append_str2_pipeline(char ***pipeline, const char *text, \
								size_t start, size_t len)
{
	char	*sub;

	sub = ft_substr(text, start, len);
	if (sub)
		append_str(pipeline, sub);
	free(sub);
}
