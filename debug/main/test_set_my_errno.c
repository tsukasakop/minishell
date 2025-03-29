/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_my_errno.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:52:53 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

volatile unsigned char	g_signal = 0;

const char	*get_error_name(t_error_type err)
{
	static const	char *error_names[] = {
		"NOERR",
		"ERR_SYSCALL",
		"ERR_AMBRDIR",
		"ERR_SYNTAX",
	};
	return (error_names[err]);
}

int	main(void)
{
	char cmd_line[] = "$?";
	char			*cur_p;
	char 			*echo_status;
	t_error_type	get_enum;
	unsigned char	last_status;
	const t_simple_cmd *scmd_list;
	size_t	i = 0;

	char *test_cases[] = {
		// エラーなし
		"echo \"Hello, World!\"",

		// エラーなし リダイレクトによるopenのエラーは子プロセス内で行うため、errnoによるエラーはなし
		"< no_exist cat",

		// ambiguous redirect
		"echo Hello >$aa",

		// リダイレクト  syntax error
		"echo Hello 1> ",

		// クォート  syntax error
		"echo \"Unclosed double quote",

		// パイプ  syntax error
		"echo Hello | cat | ",

		NULL
	};

	while (test_cases[i])
	{
		printf("\nTest case: \"%s\"\n", test_cases[i]);

		set_error_type(NOERR);
		scmd_list = init_scmd_list(test_cases[i]);

		get_enum = get_error_type();
		last_status = get_exit_status_from_err_type(get_enum);
		set_exit_status(last_status);

		cur_p = cmd_line;
		echo_status = read_variable_m(&cur_p, NULL);
		if (scmd_list == NULL)
			printf("Error: \x1b[32m%-10s\x1b[39m → err_enum: \x1b[32m%3d\x1b[39m last_status: \x1b[32m%c\x1b[39m echo $?: \x1b[32m%s\x1b[39m\n", get_error_name(get_enum), get_enum, last_status, echo_status);
		else
			printf("NOError: \x1b[32m%-10s\x1b[39m → err_enum: \x1b[32m%3d\x1b[39m last_status: \x1b[32m%c\x1b[39m echo $?: \x1b[32m%s\x1b[39m\n", get_error_name(get_enum), get_enum, last_status, echo_status);

		i++;
	}

	return (0);
}
