/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:16:16 by soumanso          #+#    #+#             */
/*   Updated: 2022/03/14 13:51:58 by soumanso         ###   ########lyon.fr   */
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

void	ft_lexer_init_n(t_lexer *lexer, t_cstr str, t_s64 len,
	t_alloc allocator)
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
