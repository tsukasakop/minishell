/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:39 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/05 15:09:06 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  expand single token text into string array.
 */
char	**expand_single_token(char *orig)
{
	char	*buffer;
	char	**fixed;
	char	*name;
	char	*cur;
	char	*next_cur;
	char	*var;
	char	*var_cur;
	size_t	name_len;

	buffer = NULL;
	fixed = ft_calloc(sizeof(char *), 1);
	cur = orig;
	while (*cur)
	{
		// 2a. シングルクオーとの場合
		if (*cur == '\'')
		{
			cur++;
			// 対応するシングルクオーとがない場合
			if (ft_strchr(cur, '\'') == NULL)
			{
				printf("not closed quote\n");
				free(buffer);
				return (NULL);
			}
			// 2a1. curから次の'\''前までをbufferにjoinする
			next_cur = ft_strchr(cur, '\'');
			buffer = ft_strnjoin(buffer, cur, next_cur - cur);
			// 2a2.  curを次の'\''の次の位置にセット
			cur = next_cur + 1;
			continue ;
		}
		// 2b. ダブルクオーとの場合
		if (*cur == '\"')
		{
			cur++;
			// 対応するクオーとがない場合error
			if (ft_strchr(cur, '\"') == NULL)
			{
				printf("not closed quote\n");
				free(buffer);
				return (NULL);
			}
			while (*cur != '\"')
			{
				// 2b2a. $の場合
				while (*cur == '$')
				{
					//変数名を展開してbufferにjoinする
					name_len = namelen(++cur);
					name = ft_strndup(cur, name_len);
					buffer = ft_strjoin(buffer, ft_getenv(name));
					// curを変数名の次の位置にセット
					cur += name_len;
				}
				// curから次の'\"', '$',"前までをbufferにjoinする
				// curを次の'\"', '$', の位置にセット
				next_cur = ft_strchr_mul(cur, (char [2]){'\"', '$'}, 2);
				buffer = ft_strnjoin(buffer, cur, next_cur - cur);
				cur = next_cur;
			}
			cur++;
			continue ;
		}
		// 2c. ＄の場合
		if (*cur == '$')
		{
			// 2c1. 展開結果をvarに一時保存する
			name_len = namelen(++cur);
			name = ft_strndup(cur, name_len);
			cur += name_len;
			var = ft_getenv(name);
			var_cur = var;
			while (*var_cur)
			{
				// 2c3a. 分割文字の場合
				if (*var_cur == ' ' || *var_cur == '\t' || *var_cur == '\n')
				{
					// 2c3a1.  bufferをfixedの末尾に挿入
					if (buffer != NULL)
					{
						append_str(&fixed, buffer);
						// printf("%s\n", buffer);
						free(buffer);
						buffer = NULL;
					}
					var_cur++;
					continue ;
				}
				// var_curの次のIFS文字か'\0'までをbufferにjoinする
				// var_curを次のIFS文字か'\0'の位置にセット
				next_cur = ft_strchr_mul(var_cur, (char [4]){' ', '\t', '\n',
						'\0'}, 4);
				buffer = ft_strnjoin(buffer, var_cur, next_cur - var_cur);
				var_cur = next_cur;
			}
			// 2c3b
			continue ;
		}
		// curから次の'\"', '\'', '$', '\0'前までをbufferにjoinする
		next_cur = ft_strchr_mul(cur, (char [4]){'\"', '\'', '$', '\0'}, 4);
		buffer = ft_strnjoin(buffer, cur, next_cur - cur);
		// curを次の'\"', '\'', '$', '\0'の位置にセット
		cur = next_cur;
	}
	if (buffer != NULL)
		append_str(&fixed, buffer);
	return (fixed);
}
