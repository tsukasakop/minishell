/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:21:31 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/21 18:39:36 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ft_stdlib.h>

t_htbl	*_getenvp(void)
{
	static t_htbl	p;

	if (!p)
		p = htnew();
	return (&p);
}

void	_delenv(t_htnode *n)
{
	free((void *)n->key);
	free((void *)n->val);
	free((void *)n);
}

int	ft_initenv(char **envp)
{
	if (envp == NULL)
		return (-1);
	while (*envp)
	{
		if (ft_putenv(*envp) == -1)
			return (-1);
		envp++;
	}
	ft_atexit(ft_clearenv);
	return (0);
}

void	ft_clearenv(void)
{
	t_htbl	*p;

	p = _getenvp();
	if (p == NULL)
		return ;
	htclear(*p, _delenv);
	*p = NULL;
}
