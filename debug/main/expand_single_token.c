/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:52:53 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/05 14:37:58 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  get length of name. name as regex is :
 *  	[A-Za-z_][A-Za-z0-9_]*
 */
size_t	namelen(char *str)
{
	size_t	cnt;

	cnt = 0;
	if (!(ft_isalpha(*str) || *str == '_'))
		return (cnt);
	str++;
	cnt++;
	while (ft_isalnum(*str) || *str == '_')
	{
		str++;
		cnt++;
	}
	return (cnt);
}

/*
 * Function:
 * ----------------------------
 *  (immutable) returns string s1 with s2_len chars head of s2.
 *  if s1 is null, this works as strndup(s2, s2_len).
 */
char	*ft_strnjoin(char *s1, char *s2, size_t s2_len)
{
	char	*joined;
	size_t	s1_len;

	s1_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	joined = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (joined == NULL)
		return (NULL);
	ft_memcpy(joined, s1, s1_len);
	ft_memcpy(joined + s1_len, s2, s2_len);
	joined[s1_len + s2_len] = '\0';
	return (joined);
}

/*
 * Function:
 * ----------------------------
 *  returns place where character in $targets appears first on s.
 */
char	*ft_strchr_mul(const char *s, char *targets, size_t target_len)
{
	size_t i;

	while (true)
	{
		i = 0;
		while (i < target_len)
		{
			if (*s == targets[i])
				return ((char *)s);
			i++;
		}
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

/*
 * Function:
 * ----------------------------
 *  returns length of null-terminated-array.
 */
size_t	null_terminated_array_len(void **arr)
{
	size_t i;

	i = 0;
	while(arr[i] != NULL)
		i++;
	return i;
}

/*
 * Function:
 * ----------------------------
 *  free null-terminated-array.
 */
void	free_null_terminated_array(void **arr)
{
	void **bak;

	if (arr == NULL)
		return;
	bak = arr;
	while (*arr != NULL)
	{
		free(*arr);
		arr++;
	}
	free(bak);
}

/*
 * Function:
 * ----------------------------
 *  (mutable) append string($orig) on end of $store.
 */
void	append_str(char ***store, char *orig)
{
	size_t len;
	char **tmp;
	char *dup;

	len = null_terminated_array_len((void **)*store);
	tmp = malloc(sizeof(char *) * (len + 2));
	if (tmp == NULL)
	{
		free_null_terminated_array((void **)*store);
		*store = NULL;
		return;
	}
	memcpy(tmp, *store, sizeof(char *) * len);
	dup = ft_strdup(orig);
	if (dup == NULL)
	{
		free(tmp);
		free_null_terminated_array((void **)*store);
		*store = NULL;
		return;
	}
	tmp[len] = dup;
	tmp[len + 1] = NULL;
	free(*store);
	*store = tmp;
}

/*
 * Function:
 * ----------------------------
 *  expand single token text into string array.
 */
char	**expand_single_token(char *orig)
{
	char	*buffer;
	char	**fixed;
	char *name;
	char *cur;
	char *next_cur;
	char *var;
	char *var_cur;
	size_t name_len;

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
				next_cur = ft_strchr_mul(cur, (char[2]){'\"', '$'}, 2);
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
						//printf("%s\n", buffer);
						free(buffer);
						buffer = NULL;
					}
					var_cur++;
					continue;
				}
				// var_curの次のIFS文字か'\0'までをbufferにjoinする
				// var_curを次のIFS文字か'\0'の位置にセット
				next_cur = ft_strchr_mul(var_cur, (char[4]){' ', '\t', '\n', '\0'},
							4);
				buffer = ft_strnjoin(buffer, var_cur, next_cur - var_cur);
				var_cur = next_cur;
			}
			// 2c3b
			continue ;
		}
		// curから次の'\"', '\'', '$', '\0'前までをbufferにjoinする
		next_cur = ft_strchr_mul(cur, (char[4]){'\"', '\'', '$', '\0'}, 4);
		buffer = ft_strnjoin(buffer, cur, next_cur - cur);
		// curを次の'\"', '\'', '$', '\0'の位置にセット
		cur = next_cur;
	}
	if(buffer != NULL)
		append_str(&fixed, buffer);
	return (fixed);
}

static void	print_str_array(char **p)
{
	if (p == NULL)
	{
		fprintf(stderr, "Null Pointer\n");
		return;
	}
	while(*p)
	{
		fprintf(stderr, "%s\n", *p);
		p++;
	}
}

int main()
{
	ft_setenv("VAR", "   test  '  ", 1);
	char **pp;
	pp = expand_single_token("'$VAR");
	print_str_array(pp);
	pp = expand_single_token("aaa$VAR\"==$VAR===\"$VAR---\'$VAR\'+++");
	print_str_array(pp);
}
