/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:32:12 by soumanso          #+#    #+#             */
/*   Updated: 2022/03/16 18:06:23 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_token	*ft_lexer_skip_spaces(t_lexer *lexer)
{
	t_token	*result;

	if (lexer->curr >= lexer->end)
		return (NULL);
	if (!ft_is_space (*(lexer->curr)))
		return (NULL);
	result = ft_lexer_push_token (lexer);
	if (!result)
		return (NULL);
	result->kind = TK_SPACES;
	result->str = lexer->curr;
	while (lexer->curr < lexer->end && ft_is_space (*(lexer->curr)))
		lexer->curr += 1;
	result->len = lexer->curr - result->str;
	return (result);
}

t_token	*ft_lexer_skip_delim(t_lexer *lexer, t_cstr delim)
{
	t_token	*result;

	if (lexer->curr >= lexer->end)
		return (NULL);
	result = ft_lexer_push_token (lexer);
	if (!result)
		return (NULL);
	result->kind = TK_DELIMITED;
	result->str = lexer->curr;
	while (lexer->curr < lexer->end && !ft_strchr (delim, *(lexer->curr)))
		lexer->curr += 1;
	result->len = lexer->curr - result->str;
	result->delim = *(lexer->curr);
	return (result);
}

t_token	*ft_lexer_skip_space_delim(t_lexer *lexer)
{
	t_token	*result;

	result = ft_lexer_skip_delim (lexer, "\v\t\r\n ");
	if (result)
		result->kind = TK_SPACE_DELIM;
	return (result);
}
