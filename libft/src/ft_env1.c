/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:19:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/08 01:32:28 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ft_stdlib.h>

char	*ft_getenv(const char *key)
{
	const t_htbl	*p;

	p = _getenvp();
	if (p == NULL || *p == NULL)
		return (NULL);
	return ((char *)htget(*p, key));
}

int	ft_setenv(const char *name, const char *value, int overwrite)
{
	t_htbl	*p;
	char	*dup_value;
	char	*past_value;

	past_value = ft_getenv(name);
	if (!overwrite && past_value != NULL)
		return (-1);
	p = _getenvp();
	if (p == NULL)
		return (-1);
	dup_value = ft_strdup(value);
	if (name == NULL || dup_value == NULL)
	{
		free(dup_value);
		return (-1);
	}
	htadd(*p, name, (void *)dup_value);
	free(past_value);
	return (0);
}

int	ft_putenv(char *string)
{
	char	*sp;
	char	*key;
	char	*val;
	int		ret;

	sp = ft_strchr(string, '=');
	if (sp == NULL)
		return (-1);
	key = malloc(sp - string + 1);
	if (key == NULL)
		return (-1);
	ft_memcpy(key, string, sp - string);
	key[sp - string] = '\0';
	val = ft_strdup(sp + 1);
	if (val == NULL || ft_setenv(key, val, 1) == -1)
		ret = -1;
	else
		ret = 0;
	free(key);
	free(val);
	return (ret);
}

int	ft_unsetenv(const char *name)
{
	t_htbl	*p;

	p = _getenvp();
	if (p == NULL)
		return (-1);
	htdelone(*p, name, _delenv);
	return (0);
}
