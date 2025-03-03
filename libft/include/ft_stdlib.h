/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:52:48 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 11:31:05 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H
# ifndef FT_MAX_F_ATEXIT
#  define FT_MAX_F_ATEXIT 32
# endif

# include <stddef.h>

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
void	ft_exit(int status);
int		ft_atexit(void *function);
char	*ft_getenv(const char *name);
int		ft_setenv(const char *name, const char *value, int overwrite);
int		ft_putenv(char *string);
int		ft_unsetenv(const char *name);
int		ft_initenv(char **envp);
void	ft_clearenv(void);
char	**ft_getenvp(void);

#endif
