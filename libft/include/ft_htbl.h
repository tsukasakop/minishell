/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htbl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:17:24 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 11:12:39 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HTBL_H
# define FT_HTBL_H
# include <stdint.h>
# define HTSIZE UINT8_MAX

typedef struct s_htnode	t_htnode;
typedef t_htnode		**t_htbl;

struct					s_htnode
{
	const char			*key;
	void				*val;
	t_htnode			*next;
};

uint8_t					hash(const char *key);
t_htbl					htnew(void);
t_htbl					htadd(t_htbl ht, const char *key, void *val);
t_htbl					htget(t_htbl ht, const char *key);
void					htdelone(t_htbl ht, const char *key,
							void (*del)(t_htnode *));
void					htclear(t_htbl ht, void (*del)(t_htnode *));
void					htiter(t_htbl ht, void (*f)(t_htnode *, void *),
							void *p);

#endif
