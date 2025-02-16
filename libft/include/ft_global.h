/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:58:57 by tkondo            #+#    #+#             */
/*   Updated: 2025/01/04 12:30:41 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# include "ft_htbl.h"
# include "ft_memory.h"

t_htbl	ft_get_globals(void);
int		ft_set_global(const char *key, void *val);
void	*ft_get_global(const char *key);
void	ft_delone_global(const char *key, void (*del)(t_htnode *));

#endif
