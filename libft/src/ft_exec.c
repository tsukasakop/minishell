/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:19:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/17 19:58:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ft_unistd.h>
#include <ft_stdlib.h>

static const char	*find_path(const char *name)
{
	char	*tmp;
	char	*path;
	char	**dirs;
	char	*cur_dir;

	if (ft_getenv("PATH") == NULL)
	{
		cur_dir = getcwd(NULL, 0);
		if (!cur_dir)
			return (NULL);
		tmp = ft_strjoin(cur_dir, "/");
		path = ft_strjoin(tmp, name);
		free(cur_dir);
		return (path);
	}
	dirs = ft_split(ft_getenv("PATH"), ':');
	while (dirs && *dirs)
	{
		tmp = ft_strjoin(*dirs, "/");
		path = ft_strjoin(tmp, name);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			while (*dirs)
				free(*dirs++);
			return ((const char *)path);
		}
		free(path);
		free(*dirs);
		dirs++;
	}
	return (NULL);
}

int	ft_execvp(const char *path, char *const argv[])
{
	const char	*abs_path;
	int			ret;

	if (ft_strchr(path, '/') != NULL)
		return (execve(path, argv, NULL));
	abs_path = find_path(path);
	if (abs_path == NULL)
		return (127);
	ret = execve(abs_path, argv, NULL);
	free((void *)abs_path);
	return (ret);
}
