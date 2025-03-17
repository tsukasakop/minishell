# include <minishell.h>

/*
 * Function: token2ecmds
 * ----------------------------
 *  expand tokens to ecmds
 */
char	**token2ecmds(t_text_list *tokens)
{
	char		**expanded;
	char		**tmp;
	t_text_list	*cur_token;

	expanded = NULL;
	cur_token = tokens;
	while (cur_token)
	{
		tmp = expand_single_token(cur_token->text);
		if (tmp == NULL)
			return (NULL);
		if (expanded == NULL)
			expanded = tmp;
		else
			expanded = (char **)null_terminated_array_join(
					(void **)expanded, (void **)tmp);
		cur_token = cur_token->next;
	}
	if (expanded == NULL)
		expanded = ft_calloc(sizeof(char **), 1);
	return (expanded);
}
