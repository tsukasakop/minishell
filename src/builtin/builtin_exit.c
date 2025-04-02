/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:01 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/03 02:59:30 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  reproduce exit function on bash.
 *  exit by argv[0] if it is provided, otherwise return last command status
 *
 *  TODO: handle errors
 */
bool	is_numeric(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

int	builtin_exit(char **argv)
{
	int	status;

	ft_fprintf(ft_stderr(), "exit\n");
	if (argv[0] != NULL && argv[1] != NULL)
	{
		ft_fprintf(ft_stderr(), "bash: exit: too many arguments\n");
		return (1);
	}
	if (argv == NULL || argv[0] == NULL)
		status = (int)get_exit_status();
	else if (argv[0][0]== '\0' || !is_numeric(argv[0]))
	{
		status = 2;
		ft_fprintf(ft_stderr(), "bash: exit: %s: numeric argument required\n", argv[0]);
	}
	else
		status = ft_atoi(argv[0]);
	ft_exit(status);
	return (1);
}
