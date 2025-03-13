/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:39 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/13 23:11:44 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	expand_bare_string(char **cur_p, char** buf_p)
{
	char *next_cur;

	next_cur = ft_strchr_mul(*cur_p, (char [4]){'\"', '\'', '$', '\0'}, 4);
	*buf_p = ft_strnjoin(*buf_p, *cur_p, next_cur - *cur_p);
	*cur_p = next_cur;
}

void	expand_single_quote(char **cur_p, char** buf_p)
{
	char *next_cur;

	*cur_p += 1;
	next_cur = ft_strchr(*cur_p, '\'');
	*buf_p = ft_strnjoin(*buf_p, *cur_p, next_cur - *cur_p);
	*cur_p = next_cur + 1;
}

void	expand_double_quote(char **cur_p, char** buf_p)
{
	char *cur;
	char *buffer;
	char *next_cur;
	char *name;
	char *var;
	size_t name_len;
	size_t var_len;

	cur = *cur_p;
	buffer = *buf_p;
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
	*buf_p = ft_strnjoin(buffer, "", 0);
	*cur_p = cur + 1;
}

void	expand_bare_variable(char **cur_p, char **buf_p, char ***fixed_p)
{
	char *cur;
	char *buffer;
	char *next_cur;
	char *name;
	char *var;
	char *var_cur;
	size_t name_len;

	cur = *cur_p;
	buffer = *buf_p;
	name_len = namelen(cur + 1);
	name = ft_strndup(cur + 1, name_len);
	if (!(name && name[0]))
	{
		*buf_p = ft_strnjoin(buffer, "$", 1);
		*cur_p += 1;
		return;
	}
	cur += 1 + name_len;
	var = ft_getenv(name);
	if (var == NULL)
	{
		*cur_p = cur;
		return;
	}
	var_cur = var;
	while (*var_cur)
	{
		if (*var_cur == ' ' || *var_cur == '\t' || *var_cur == '\n')
		{
			if (buffer != NULL)
			{
				append_str(fixed_p, buffer);
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
	*buf_p = buffer;
	*cur_p = cur;
}

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
	char	*cur;

	buffer = NULL;
	fixed = ft_calloc(sizeof(char *), 1);
	cur = orig;
	while (*cur)
	{
		if (*cur == '\'')
			expand_single_quote(&cur, &buffer);
		else if (*cur == '\"')
			expand_double_quote(&cur, &buffer);
		else if (*cur == '$')
			expand_bare_variable(&cur, &buffer, &fixed);
		else
			expand_bare_string(&cur, &buffer);
	}
	if (buffer != NULL)
		append_str(&fixed, buffer);
	return (fixed);
}
