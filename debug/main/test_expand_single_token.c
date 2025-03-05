/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_single_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:52:53 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/05 17:20:02 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_str_array(char **p)
{
	size_t	i;

	if (p == NULL)
	{
		fprintf(stderr, " [Error]: Caught Null Pointer\n");
		return ;
	}
	i = 0;
	while (p[i])
	{
		fprintf(stderr, " [%lu] = \"%s\"\n", i, p[i]);
		i++;
	}
}

static void	test_expand_single_token(char *name, char *value, char *token)
{
	char	**pp;

	fprintf(stderr, "---------- Test Condition ----------\n");
	fprintf(stderr, " name  = \"%s\"\n", name);
	fprintf(stderr, " value = \"%s\"\n", value);
	fprintf(stderr, " token = \"%s\"\n", token);
	fprintf(stderr, "---------- Errors on Processing ----------\n");
	fprintf(stderr, " [%d]: from `ft_setenv(name, value, 1)`\n", ft_setenv(name,
			value, 1));
	fprintf(stderr, " [%s]: from `ft_getenv(name)`\n", ft_getenv(name));
	pp = expand_single_token(token);
	fprintf(stderr, "---------- Retuned Texts ----------\n");
	print_str_array(pp);
	fprintf(stderr, "------------------------------------\n");
}

int	main(void)
{
	char	*name;
	char	*value;

	test_expand_single_token("a23", "a23$a23", "$a23");
	test_expand_single_token("VAR", "   test  '  ", "'$VAR");
	test_expand_single_token("VAR", "   test  '  ",
		"aaa$VAR\"==$VAR===\"$VAR---\'$VAR\'+++");
}
