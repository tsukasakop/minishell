/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:39 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/14 00:21:46 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *dup_name(char *cur)
{
	size_t len;
	char *str;

	len = namelen(cur);
	str = ft_strndup(cur, len);
	return str;
}

char *read_bare_string(char **cur_p, char *ends, size_t ends_len)
{
	char *next_cur;
	char *buffer;

	next_cur = ft_strchr_mul(*cur_p, ends, ends_len);
	buffer = ft_strndup(*cur_p, next_cur - *cur_p);
	*cur_p = next_cur;
	return buffer;
}

void	read_bare_string_m(char **cur_p, char** buf_p, char *ends, size_t ends_len)
{
	char *read;
	char *tmp;

	read = read_bare_string(cur_p, ends, ends_len);
	tmp = ft_strnjoin(*buf_p, read, ft_strlen(read));
	free(read);
	free(*buf_p);
	*buf_p = tmp;
}

void	expand_bare_string(char **cur_p, char** buf_p)
{
	read_bare_string_m(cur_p, buf_p, (char [4]){'\"', '\'', '$', '\0'}, 4);
}

void	expand_single_quote(char **cur_p, char** buf_p)
{
	*cur_p += 1;
	read_bare_string_m(cur_p, buf_p, "\'", 1);
	*cur_p += 1;
}

void	expand_double_quote(char **cur_p, char** buf_p)
{
	char *cur;
	char *buffer;
	char *name;
	char *var;

	buffer = *buf_p;
	cur++;
	while (*cur != '\"')
	{
		if (*cur == '$')
		{
			cur++;
			name = dup_name(cur);
			if (ft_strlen(name) == 0)
			{
				buffer = ft_strnjoin(buffer, "$", 1);
				free(name);
				continue ;
			}
			var = ft_getenv(name);
			if (var)
				buffer = ft_strnjoin(buffer, var, ft_strlen(var));
			cur += ft_strlen(name);
			free(name);
		}
		else
			read_bare_string_m(&cur, &buffer, "\"$", 2);
	}
	*buf_p = ft_strnjoin(buffer, "", 0);
	*cur_p = cur + 1;
}

void	expand_bare_variable(char **cur_p, char **buf_p, char ***fixed_p)
{
	char *cur;
	char *buffer;
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
		}
		else
			read_bare_string_m(&var_cur, &buffer, (char [4]){' ', '\t', '\n', '\0'}, 4);
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
