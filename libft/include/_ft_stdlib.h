/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_stdlib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:52:48 by tkondo            #+#    #+#             */
/*   Updated: 2025/01/04 12:38:46 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STDLIB_H
# define _FT_STDLIB_H

# include <ft_htbl.h>
# include <ft_stdlib.h>
# include <ft_string.h>
# include <stddef.h>
# include <stdlib.h>

t_htbl	*_getenvp(void);
void	_delenv(t_htnode *n);

#endif
