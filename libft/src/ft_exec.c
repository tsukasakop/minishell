/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:19:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/21 16:49:59 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ft_unistd.h>
#include <ft_stdlib.h>

static char	*create_path(char *dir, const char *name)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(dir, "/");
	path = ft_strjoin(tmp, name);
	free(tmp);
	return (path);
}

static char	*get_cwd_exec_path(const char *name)
{
	char	*cur_dir;
	char	*path;

	cur_dir = getcwd(NULL, 0);
	if (!cur_dir)
		return (NULL);
	path = create_path(cur_dir, name);
	free(cur_dir);
	return (path);
}

static void	free_dirs(char **dirs)
{
	size_t	i;

	i = 0;
	while(dirs && dirs[i])
	{
		free(dirs[i]);
		i++;
	}
	free(dirs);
}

static const char	*find_path(const char *name)
{
	char	*path;
	char	**dirs;
	size_t	i;

	if (ft_getenv("PATH") == NULL)
		return ((const char *)get_cwd_exec_path(name));
	dirs = ft_split(ft_getenv("PATH"), ':');
	i = 0;
	while (dirs && dirs[i])
	{
		path = create_path(dirs[i], name);
		if (access(path, F_OK) == 0)
		{
			free_dirs(dirs);
			return ((const char *)path);
		}
		free(path);
		i++;
	}
	free_dirs(dirs);
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
