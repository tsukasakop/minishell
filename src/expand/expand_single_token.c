/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:39 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/14 01:44:38 by tkondo           ###   ########.fr       */
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

char *read_variable_m(char **cur_p, char **buf_p)
{
	char *name;
	char *value;
	char *tmp;

	(*cur_p)++;
	name = dup_name(*cur_p);
	if (name == NULL || ft_strlen(name) == 0)
	{
		free(name);
		tmp = ft_strnjoin(*buf_p, "$", 1);
		free(*buf_p);
		*buf_p = tmp;
		return NULL;
	}
	*cur_p += ft_strlen(name);
	value = ft_getenv(name);
	free(name);
	return value;
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
	char *var;
	char *tmp;

	(*cur_p)++;
	while (**cur_p != '\"')
	{
		if (**cur_p == '$')
		{
			var = read_variable_m(cur_p, buf_p);
			if (!var)
				continue;
			tmp = ft_strnjoin(*buf_p, var, ft_strlen(var));
			free(*buf_p);
			*buf_p = tmp;
		}
		else
			read_bare_string_m(cur_p, &*buf_p, "\"$", 2);
	}
	tmp = ft_strnjoin(*buf_p, "", 0);
	free(*buf_p);
	*buf_p = tmp;
	(*cur_p)++;
}

void	expand_bare_variable(char **cur_p, char **buf_p, char ***fixed_p)
{
	char *name;
	char *var;

	var = read_variable_m(cur_p, buf_p);
	while (var && *var)
	{
		if (ft_isifs(*var))
		{
			if (*buf_p != NULL)
				append_str(fixed_p, *buf_p);
			*buf_p = NULL;
			var++;
		}
		else
			read_bare_string_m(&var, buf_p, (char [4]){' ', '\t', '\n', '\0'}, 4);
	}
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
