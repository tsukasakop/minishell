/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_syntax_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:28:12 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/22 14:33:54 by miyuu            ###   ########.fr       */
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
		// クォートが適切に閉じているケース
		"echo \"Hello, World!\"",
		"echo 'Hello, World!'",
		"echo \"Hello 'inside' double quotes\"",
		"echo 'Hello \"inside\" single quotes'",
		"echo \"Nested 'quotes' inside\" | cat",
		"echo 'Nested \"quotes\" inside' | cat",
		"echo \"\" | cat",      // 空のダブルクォート
		"echo '' | cat",        // 空のシングルクォート
		"echo \"Hello\"\"World\"",
		"echo 'Hello''World'",
		"\'\'",
		"\"\"",
		"\'   ""\'",
		"\"  "   "   \"",
		"\'\'\'\'\'\'\'\'\'\'",
		"\'\'\"    \'\'\"	\'\"\'\'    \'\"\"	",
		"\'\'\"          \'\"",
		"\"\'\'\'\"",

		// クォートが閉じられていないエラーケース
		"echo \"Unclosed double quote",
		"echo 'Unclosed single quote",
		"echo \"Mismatched quotes'",
		"echo 'Another mismatched\"",
		"echo \"Multiple unclosed ' quotes",
		"echo 'Multiple unclosed \" quotes",
		"echo 'This is an example | with unclosed quote",
		"echo \"Unclosed quote before pipe | ls",
		"ls | echo \"Unclosed quote at end",

		// その他のクォートが混在するケース
		"echo \" | cat",        // 途中で閉じない
		"echo ' | cat",         // 途中で閉じない

		"\'",
		"\"",
		"\'       ",
		"\"            ",
		" 								\'",
		" 								\"",
		"\'\'\"\'\'\"\'\"\'\'\'\"",
		"\"    \''\"\'",
		"\"  \"  \''\"\'",
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
