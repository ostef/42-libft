/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:16 by soumanso          #+#    #+#             */
/*   Updated: 2022/03/11 14:33:20 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lexer_init(t_lexer *lexer, t_cstr str, t_alloc allocator)
{
	lexer->start = str;
	lexer->curr = str;
	lexer->end = str + ft_strlen (str);
	lexer->first_token = NULL;
	lexer->last_token = NULL;
	lexer->allocator = allocator;
}

void	ft_lexer_init_n(t_lexer *lexer, t_cstr str, t_int len, t_alloc allocator)
{
	lexer->start = str;
	lexer->curr = str;
	lexer->end = str + len;
	lexer->first_token = NULL;
	lexer->last_token = NULL;
	lexer->allocator = allocator;
}

t_bool	ft_lexer_is_valid(t_lexer *lexer)
{
	return (lexer->curr < lexer->end);
}

t_token	*ft_lexer_push_token(t_lexer *lexer)
{
	t_token	*new;
	t_token	*tmp_next;

	new = (t_token *)ft_zalloc (sizeof (t_token), lexer->allocator);
	if (!new)
		return (NULL);
	if (lexer->last_token)
	{
		tmp_next = lexer->last_token->next;
		lexer->last_token->next = new;
		new->prev = lexer->last_token;
		new->next = tmp_next;
		if (tmp_next)
			tmp_next->prev = new;
	}
	else
		lexer->first_token = new;
	lexer->last_token = new;
	return (new);
}

t_token	*ft_lexer_next(t_lexer *lexer)
{
	return (ft_lexer_skip (lexer, 0xffffffff));
}

t_token	*ft_lexer_skip(t_lexer *lexer, t_token_kind kinds)
{
	if (lexer->curr >= lexer->end)
		return (NULL);
	if ((kinds | TK_SPACES) == TK_SPACES && ft_is_space (*(lexer->curr)))
		return (ft_lexer_skip_spaces (lexer));
	if ((kinds | TK_QUOTED_STR) == TK_QUOTED_STR
		&& (*(lexer->curr) == '\'' || *(lexer->curr) == '"'))
		return (ft_lexer_skip_quoted_str (lexer));
	if ((kinds | TK_SPACE_DELIM) == TK_SPACE_DELIM)
		return (ft_lexer_skip_space_delim (lexer));
	if ((kinds | TK_IDENTIFIER) == TK_IDENTIFIER
		&& (*(lexer->curr) == '_' || ft_is_alpha (*(lexer->curr))))
		return (ft_lexer_skip_identifier (lexer));
	if ((kinds | TK_INTEGER) == TK_INTEGER && !ft_lexer_is_integer (lexer))
		return (ft_lexer_skip_integer (lexer));
	return (NULL);
}
