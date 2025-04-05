/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_shell_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 03:41:19 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/05 15:34:00 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


int	ft_putstr_fd_len(char *s, int fd)
{
	if (!s)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putnbr_fd_len(int n, int fd)
{
	char	c;
	int	 len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr_fd_len("-2147483648", fd));
	if (n < 0)
	{
		len += write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr_fd_len(n / 10, fd);
	c = (n % 10) + '0';
	len += write(fd, &c, 1);
	return (len);
}


int	print_shell_error(char *prefix, char *msg, char *arg)
{
	int		len;
	char	*before;
	char	*after;


	len = ft_putstr_fd_len("bash: ", 2);
	if (prefix)
	{
		len += ft_putstr_fd_len(prefix, 2);
		len += ft_putstr_fd_len(": ", 2);
	}
	if (msg)
	{
		if (arg && ft_strchr(msg, '%'))
		{
			before = msg;
			after = ft_strchr(msg, '%');
			write(2, before, after - before);
			len += (after - before);
			len += ft_putstr_fd_len(arg, 2);
			len += ft_putstr_fd_len(after + 2, 2); // +2 to skip "%s"
		}
		else
		{
			len += ft_putstr_fd_len(msg, 2);
		}
	}
	len += ft_putstr_fd_len("\n", 2);
	return (len);
}

int	print_shell_error_errno(char *prefix)
{
	int	len;

	len = ft_putstr_fd_len("bash: ", 2);
	if (prefix)
	{
		len += ft_putstr_fd_len(prefix, 2);
		len += ft_putstr_fd_len(": ", 2);
	}
	len += ft_putstr_fd_len(strerror(errno), 2);
	len += ft_putstr_fd_len("\n", 2);
	return (len);
}

int	command_not_found_handle_new(char *cmd)
{
	print_shell_error(cmd, "command not found", NULL);
	return (127);
}


int	perror_with_shellname_new(char *prefix)
{
	return (print_shell_error_errno(prefix));
}

int	main(void)
{
	char	*msg = "msg";
	open(msg, O_WRONLY);
	perror_with_shellname_new(msg);

	char	*path = "../";
	print_shell_error(path, "Is a directory", NULL);
	open("mm", O_WRONLY);
	print_shell_error_errno(path);
	path = "cmd";
	command_not_found_handle_new(path);

	char	*syntax = "|";
	print_shell_error(NULL, "syntax error near unexpected token `%s'", "|");

	char	*target = "$aa";
	print_shell_error(target, "ambiguous redirect", NULL);

	char	*identifier = "42=";
	print_shell_error("export", "`%s': not a valid identifier", identifier);

	print_shell_error("cd", "too many arguments", NULL);
	print_shell_error("cd", "OLDPWD not set", NULL);
	char		*next_dir = "/dir/in";
	print_shell_error("cd", "%s", next_dir);

	char	*delimiter = "EOF";
	print_shell_error("warning", "here-document delimited by end-of-file (wanted `%s')", delimiter);


}
