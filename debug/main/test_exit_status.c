/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:52:53 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/22 13:42:39 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

typedef enum e_error_type		t_error_type;
enum e_error_type
{
	NOERR,
	ERR_PERROR, //bad fdの時→1 No such→1
	ERR_NOFILE, //親プロでのredirの時→1
	ERR_AMBRDIR, //1
	ERR_SYNTAX, //2
	ERR_NOCMD//127
};

const char	*get_error_name(t_error_type err)
{
	static const	char *error_names[] = {
		"NOERR",
		"ERR_PERROR",
		"ERR_NOFILE",
		"ERR_AMBRDIR",
		"ERR_SYNTAX",
		"ERR_NOCMD",
	};
	return (error_names[err]);
}

unsigned char	t_error_check(t_error_type	st_error)
{
	if (st_error == NOERR)
		return (0);
	else if (st_error == ERR_PERROR)
		return (1);
	else if (st_error == ERR_NOFILE)
		return (1);
	else if (st_error == ERR_AMBRDIR)
		return (1);
	else if (st_error == ERR_SYNTAX)
		return (2);
	else if (st_error == ERR_NOCMD)
		return (127);
	return (0);
}

void	error_set_exitstatus(t_error_type err)
{
	unsigned char	exit_status;

	exit_status = t_error_check(err);
	set_exit_status(exit_status);
}

t_error_type	*get_error_enum_p(void)
{
	static t_error_type	p;

	return (&p);
}

t_error_type	get_error_enum(void)
{
	t_error_type	*st_ptr;

	st_ptr = get_error_enum_p();
	return (*st_ptr);
}

void	set_error_enum(t_error_type st)
{
	t_error_type	*st_ptr;

	st_ptr = get_error_enum_p();
	*st_ptr = st;
}


int	main(void)
{
	char cmd_line[] = "$?";
	char *cur_p;
	char *exit_status;
	t_error_type	get_enum;

	for (t_error_type err = NOERR; err <= ERR_NOCMD; err++)
	{
		set_error_enum(err);
		get_enum = get_error_enum();

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
