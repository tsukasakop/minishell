/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:19:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/01/04 12:22:18 by tkondo           ###   ########.fr       */
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

	if (!overwrite && ft_getenv(name) != NULL)
		return (-1);
	p = _getenvp();
	if (p == NULL)
		return (-1);
	htadd(*p, name, (void *)value);
	return (0);
}

int	ft_putenv(char *string)
{
	char	*sp;
	char	*key;
	char	*val;

	sp = ft_strchr(string, '=');
	if (sp == NULL)
		return (-1);
	key = malloc(sp - string + 1);
	if (key == NULL)
		return (-1);
	ft_memcpy(key, string, sp - string);
	key[sp - string] = '\0';
	val = ft_strdup(sp + 1);
	if (val == NULL)
	{
		free(key);
		return (-1);
	}
	if (ft_setenv(key, val, 1) == -1)
	{
		free(key);
		free(val);
		return (-1);
	}
	return (0);
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
