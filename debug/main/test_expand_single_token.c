/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_single_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:52:53 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/05 14:43:25 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_str_array(char **p)
{
	if (p == NULL)
	{
		fprintf(stderr, "Null Pointer\n");
		return;
	}
	while(*p)
	{
		fprintf(stderr, "%s\n", *p);
		p++;
	}
}

int main()
{
	ft_setenv("VAR", "   test  '  ", 1);
	char **pp;
	pp = expand_single_token("'$VAR");
	print_str_array(pp);
	pp = expand_single_token("aaa$VAR\"==$VAR===\"$VAR---\'$VAR\'+++");
	print_str_array(pp);
}
