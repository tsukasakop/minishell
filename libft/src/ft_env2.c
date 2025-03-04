/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:16:20 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 12:16:22 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ft_stdlib.h>

static void	cnt_htnode(t_htnode *n, void *cntp)
{
	(void)n;
	(*(size_t *)cntp)++;
}

static void	store_htnode(t_htnode *n, void *p)
{
	char	***envp_cur;
	char	*keyval;

	keyval = ft_strjoin((char *)n->key, "=");
	keyval = ft_strjoin(keyval, (char *)n->val);
	envp_cur = (char ***)p;
	**envp_cur = keyval;
	++*envp_cur;
}

char	**ft_getenvp(void)
{
	t_htbl	*p;
	size_t	cnt;
	char	**envp;
	char	**envp_cur;

	p = _getenvp();
	if (p == NULL)
		return (NULL);
	cnt = 0;
	htiter(*p, cnt_htnode, (void *)&cnt);
	envp = malloc(sizeof(char *) * (cnt + 1));
	if (!envp)
		return (NULL);
	envp[cnt] = NULL;
	envp_cur = envp;
	htiter(*p, store_htnode, (void *)&envp_cur);
	return (envp);
}
