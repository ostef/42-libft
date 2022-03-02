/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:52:28 by soumanso          #+#    #+#             */
/*   Updated: 2022/03/02 16:02:06 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_lexer_is_integer(t_lexer *lexer)
{
	t_s64	i;

	i = 0;
	if (lexer->curr[i] == '-' || lexer->curr[i] == '+')
		i += 1;
	return (lexer->curr + i < lexer->end && ft_is_digit (lexer->curr[i]));
}

t_token	*ft_lexer_skip_integer(t_lexer *lexer)
{
	t_token	*result;

	if (lexer->curr >= lexer->end)
		return (NULL);
	if (ft_lexer_is_integer (lexer))
		return (NULL);
	result = ft_lexer_push_token (lexer);
	if (!result)
		return (NULL);
	result->kind = TK_INTEGER;
	result->str = lexer->curr;
	if (*(lexer->curr) == '-' || *(lexer->curr) == '+')
		lexer->curr += 1;
	while (lexer->curr < lexer->end && ft_is_digit (*(lexer->curr)))
		lexer->curr += 1;
	result->len = lexer->curr - result->str;
	return (result);
}
