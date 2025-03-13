/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:39 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/13 22:23:38 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  expand single token text into string array.
 *  Returns
 *  	NULL:
 *  		failed process (not closed quote, or malloc failed)
 *  	return_value[0] == NULL:
 *  		expanded but no token exits.
 *  		this occurs on expandng empty string without double quotes.
 *  	return_value[1] == NULL:
 *  		general case. expanded to 1 token.
 *  	return_value[>=2] == NULL:
 *  		expanded to more than 1 token, by expanding variable without quotes.
 *
 *
 */
char	**expand_single_token(char *orig)
{
	char	*buffer;
	char	**fixed;
	char	*name;
	char	*cur;
	char	*next_cur;
	char	*var;
	char	*var_cur;
	size_t	name_len;
	size_t	var_len;

	buffer = NULL;
	fixed = ft_calloc(sizeof(char *), 1);
	cur = orig;
	while (*cur)
	{
		if (*cur == '\'')
		{
			cur++;
			next_cur = ft_strchr(cur, '\'');
			buffer = ft_strnjoin(buffer, cur, next_cur - cur);
			cur = next_cur + 1;
			continue ;
		}
		else if (*cur == '\"')
		{
			cur++;
			while (*cur != '\"')
			{
				if (*cur == '$')
				{
					name_len = namelen(cur + 1);
					if (name_len == 0)
					{
						buffer = ft_strnjoin(buffer, "$", 1);
						cur++;
						continue ;
					}
					name = ft_strndup(cur + 1, name_len);
					var = ft_getenv(name);
					if (var)
					{
						var_len = ft_strlen(var);
						buffer = ft_strnjoin(buffer, var, var_len);
					}
					cur += 1 + name_len;
					continue ;
				}
				next_cur = ft_strchr_mul(cur, "\"$", 2);
				buffer = ft_strnjoin(buffer, cur, next_cur - cur);
				cur = next_cur;
			}
			buffer = ft_strnjoin(buffer, "", 0);
			cur++;
		}
		else if (*cur == '$')
		{
			name_len = namelen(cur + 1);
			name = ft_strndup(cur + 1, name_len);
			if (!(name && name[0]))
			{
				buffer = ft_strnjoin(buffer, "$", 1);
				cur++;
				continue ;
			}
			cur += 1 + name_len;
			var = ft_getenv(name);
			if (var == NULL)
				continue ;
			var_cur = var;
			while (*var_cur)
			{
				if (*var_cur == ' ' || *var_cur == '\t' || *var_cur == '\n')
				{
					if (buffer != NULL)
					{
						append_str(&fixed, buffer);
						free(buffer);
						buffer = NULL;
					}
					var_cur++;
					continue ;
				}
				next_cur = ft_strchr_mul(var_cur, (char [4]){' ', '\t', '\n',
						'\0'}, 4);
				buffer = ft_strnjoin(buffer, var_cur, next_cur - var_cur);
				var_cur = next_cur;
			}
		}
		else
		{
			next_cur = ft_strchr_mul(cur, (char [4]){'\"', '\'', '$', '\0'}, 4);
			buffer = ft_strnjoin(buffer, cur, next_cur - cur);
			cur = next_cur;
		}
	}
	if (buffer != NULL)
		append_str(&fixed, buffer);
	return (fixed);
}
