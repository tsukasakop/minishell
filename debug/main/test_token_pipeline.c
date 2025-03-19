/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_token_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:28:12 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/19 23:58:27 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**cmdline2_scmd_texts(const char *cmd_line);

void	print_pipeline(char **pipeline)
{
	if (!pipeline)
	{
		printf("Pipeline is NULL\n");
		return ;
	}
	int i = 0;
	while (pipeline[i])
	{
		printf("pipeline[%d]: \"\x1b[32m%s\x1b[39m\"\n", i, pipeline[i]);
		i++;
	}
}

int	main(void)
{
	char *test_cases[] = {
		"ls -l | grep txt | wc -l",
		"echo 'hello $VAR' | cat",
		"ls | grep '^a' | wc -l",
		"ps aux | grep chrome | awk '{print $2}'",
		"echo \"Hello | World\"",
		"echo 'Hello | World' | cat",
		"echo \"Hello | | World\"",
		"echo \"      Hello | |\"|    ls",
		"\"|||||\"|ls",
		"l    s   | \"\"",
		"l    s   |\"       \"   ",
		"ls |",
		"| ls",
		"ls    | ",
		"ls || cat",
		"ls |  | cat",
		"l|l|l|",
		"|",
		"     |    ",
		"||||||",
		"       ",
		"",
		NULL
	};

	int i = 0;
	while (test_cases[i])
	{
		printf("\nTest case: \"%s\"\n", test_cases[i]);
		char **pipeline = cmdline2_scmd_texts(test_cases[i]);
		print_pipeline(pipeline);

		if (pipeline)
		{
			int j = 0;
			while (pipeline[j])
				free(pipeline[j++]);
			free(pipeline);
		}

		i++;
	}
	return (0);
}
