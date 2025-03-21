/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:16:02 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/21 12:42:27 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include "ft_blocked_node.h"

typedef t_blocked_node	t_memory_manager;

t_memory_manager		*ft_mmnew(void);
void					*ft_mmadd(t_memory_manager *mm, void *ptr);
void					*ft_mmmalloc(t_memory_manager *mm, size_t size);
void					*ft_mmcalloc(t_memory_manager *mm, size_t s, size_t c);
void					ft_mmfree(t_memory_manager *mm);

t_memory_manager		**ft_g_mmget(void);
void					*ft_g_mmadd(void *ptr);
void					*ft_g_mmmalloc(size_t size);
void					*ft_g_mmcalloc(size_t size, size_t cnt);
void					ft_g_mmfree(void);

#endif
