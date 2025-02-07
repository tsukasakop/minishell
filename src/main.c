#include <signal.h>
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#define PROMPT "minishell$ "
#define EXIT_OFF_SIG 128

void	flush_prompt(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init(void)
{
	signal(SIGINT, flush_prompt);
}

int eval_input(const char* input)
{
	int status;

	status = system(input);
	//system関数の戻り値は正しくないことがあるので調整しているだけ
	if (status == SIGINT)
		status += EXIT_OFF_SIG;
	return status;
}

int	main(void)
{
	const char	*input;

	init();
	while (1)
	{
		input = (const char*)readline(PROMPT);
		if (!input)
			exit(EXIT_SUCCESS);
		if (*input)
			add_history(input);
		if(eval_input(input) == SIGINT + EXIT_OFF_SIG)
			printf("\n");
		free((void *)input);
	}
}
