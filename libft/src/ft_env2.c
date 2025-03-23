/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:16:20 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/21 16:33:20 by tkondo           ###   ########.fr       */
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
	char	*token;
	char	*tmp;

	tmp = ft_strjoin((char *)n->key, "=");
	if (tmp == NULL)
		return ;
	token = ft_strjoin(tmp, (char *)n->val);
	free(tmp);
	if (token == NULL)
		return ;
	envp_cur = (char ***)p;
	**envp_cur = token;
	++*envp_cur;
}

static void	free_envp(char **envp, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

static int	is_envp_filled(char **envp, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (envp[i] == NULL)
			return (0);
		i++;
	}
	return (1);
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
	if (!is_envp_filled(envp, cnt))
	{
		free_envp(envp, cnt);
		return (NULL);
	}
	return (envp);
}
