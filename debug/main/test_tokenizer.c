/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:39:47 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 19:50:18 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_list(t_text_list *head)
{
	printf("Parsed list: [");
	for (t_text_list *cur = head; cur; cur = cur->next)
	{
		printf("\"%s\"", cur->text);
		if (cur->next)
			printf(", ");
	}
	printf("]\n");
}

void	free_text_list(t_text_list *scmds)
{
	t_redirect	*tmp;

	while (scmds)
	{
		tmp = scmds->next;
		if (scmds->text)
			free(scmds->text);
		free(scmds);
		scmds = tmp;
	}
}

int	main(void)
{
	char *test_cases[] = {
		"ls -l > out",
		"ls -l> out",
		"ls -l >out>out2",
		"ls 2> out",
		"ls 123456789< out",
		"ls 2 > out",
		"ls '2'> out",
		"ls -l > ",	//シンタックスエラーのテストケース
		"ls -l >2>aiueo",	//シンタックスエラーのテストケース
		"ls -l <<<aiueo",	//シンタックスエラーのテストケース
		"echo \"aa aa",
		"echo 'aa aa'",
		NULL
	};

	int i = 0;
	while (test_cases[i])
	{
		printf("\nTest case: \"%s\"\n", test_cases[i]);
		t_text_list *head = tokenizer_scmd_text(test_cases[i]);
		print_list(head);
		free_text_list(head);
		i++;
	}
	return (0);
}
