/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_my_errno.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:52:53 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/25 19:09:15 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// typedef enum e_error_type		t_error_type;
// enum e_error_type
// {
// 	NOERR,
// 	ERR_PERROR, //bad fdの時→1 No such→1
// 	ERR_AMBRDIR, //1
// 	ERR_SYNTAX, //2
// };

const char	*get_error_name(t_error_type err)
{
	static const	char *error_names[] = {
		"NOERR",
		"ERR_PERROR",
		"ERR_AMBRDIR",
		"ERR_SYNTAX",
	};
	return (error_names[err]);
}

unsigned char	t_error_check(t_error_type	st_error)
{
	if (st_error == NOERR)
		return (0);
	else if (st_error == ERR_PERROR)
		return (1);
	else if (st_error == ERR_AMBRDIR)
		return (1);
	else if (st_error == ERR_SYNTAX)
		return (2);
	return (0);
}

void	error_set_exitstatus(t_error_type err)
{
	unsigned char	exit_status;

	exit_status = t_error_check(err);
	set_exit_status(exit_status);
}

t_error_type	*get_error_type_p(void)
{
	static t_error_type	p;

	return (&p);
}

t_error_type	get_error_type(void)
{
	t_error_type	*st_ptr;

	st_ptr = get_error_type_p();
	return (*st_ptr);
}

void	set_error_type(t_error_type st)
{
	t_error_type	*st_ptr;

	st_ptr = get_error_type_p();
	*st_ptr = st;
}


int	main(void)
{
	char cmd_line[] = "$?";
	char *cur_p;
	char *exit_status;
	t_error_type	get_enum;

	for (t_error_type err = NOERR; err <= ERR_SYNTAX; err++)
	{
		set_error_type(err);
		get_enum = get_error_type();

		cur_p = cmd_line;
		if (get_enum != NOERR)
		{
			error_set_exitstatus(get_enum);
			exit_status = read_variable_m(&cur_p, NULL);
			printf("Error: %-10s → err_enum: %3d exit_status: %s\n", get_error_name(get_enum), get_enum, exit_status);
		}
		else
		{
			exit_status = read_variable_m(&cur_p, NULL);
			printf("NOError: %-10s → err_enum: %3d exit_status: %s\n", get_error_name(get_enum), get_enum, exit_status);
		}
	}
	return (0);
}
