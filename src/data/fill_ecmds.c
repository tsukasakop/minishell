/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ecmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:36:06 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/26 12:05:35 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_ecmds
 * ----------------------------
 * Returns an array only strings without redirects.
 * ToDO:norminetteエラー
 */
char	**fill_ecmds(char **src, int wc)
{
	char	**ecmds;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	ecmds = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!ecmds)
		return (NULL);
	while (src[i])
	{
		if (has_redirect(src[i]) != NULL)
		{
			//ToDo:リダイレクトを含む文字列の最後もの字が記号かいなか関数分けする？
			len = ft_strlen(src[i]);
			if (src[i + 1] != NULL && \
				(src[i][len - 1] == '>' || src[i][len - 1] == '<'))
				i++;
		}
		else
		{
			ecmds[j] = ft_strdup(src[i]);
			if (!ecmds[j])
			{
				free_ecmds(ecmds);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	ecmds[j] = NULL;
	return (ecmds);
}
