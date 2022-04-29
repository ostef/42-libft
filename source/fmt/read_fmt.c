/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:04:22 by soumanso          #+#    #+#             */
/*   Updated: 2022/04/29 17:49:04 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char			g_fmt_specifiers[] = "cspdiuxXbnam";
static const t_fmt_func		g_fmt_funcs[] = {
	&ft_sprint_c,
	&ft_sprint_s,
	&ft_sprint_p,
	&ft_sprint_i,
	&ft_sprint_i,
	&ft_sprint_u,
	&ft_sprint_x,
	&ft_sprint_x,
	&ft_sprint_b,
	&ft_sprint_n,
	&ft_sprint_a,
	&ft_sprint_m
};
static const char			g_flag_str[] = "-+ #0\\";
static const t_fmt_flags	g_flag_values[] = {
	FLAG_LJUSTIFY,
	FLAG_SIGN,
	FLAG_SPACE,
	FLAG_HASH,
	FLAG_ZPAD,
	FLAG_ESCAPED
};

static t_s64	ft_read_flag(char c, t_fmt_arg *arg)
{
	t_s64	i;

	i = 0;
	while (i < (t_s64)(sizeof (g_flag_str) - 1))
	{
		if (c == g_flag_str[i])
		{
			arg->flags |= g_flag_values[i];
			return (1);
		}
		i += 1;
	}
	return (0);
}

static t_s64	ft_read_width(const char *fmt, t_fmt_arg *arg)
{
	t_s64	i;

	i = 0;
	arg->width = WIDTH_DEFAULT;
	if (fmt[i] == '*')
	{
		arg->width = WIDTH_ARG;
		i += 1;
	}
	else if (fmt[i] >= '0' && fmt[i] <= '9')
		i += ft_str_to_int (fmt + i, &arg->width);
	return (i);
}

static t_s64	ft_read_precision(const char *fmt, t_fmt_arg *arg)
{
	t_s64	i;

	i = 0;
	arg->precision = PREC_DEFAULT;
	if (fmt[i] == '.')
	{
		i += 1;
		if (fmt[i] == '*')
		{
			arg->precision = PREC_ARG;
			i += 1;
		}
		else if (fmt[i] >= '0' && fmt[i] <= '9')
			i += ft_str_to_int (fmt + i, &arg->precision);
		else
			arg->precision = 0;
	}
	return (i);
}

static t_s64	ft_read_specifier(char c, t_fmt_arg *arg)
{
	t_s64	i;

	arg->specifier = 0;
	arg->func = NULL;
	i = 0;
	while (i < (t_s64)(sizeof (g_fmt_specifiers) - 1))
	{
		if (g_fmt_specifiers[i] == c)
		{
			arg->specifier = c;
			arg->func = g_fmt_funcs[i];
			return (1);
		}
		i += 1;
	}
	return (0);
}

t_s64	ft_read_arg(t_cstr fmt, t_fmt_arg *arg, va_list va)
{
	t_s64	i;

	i = 0;
	arg->flags = FLAG_NONE;
	while (fmt[i] && ft_read_flag (fmt[i], arg))
		i += 1;
	i += ft_read_width (fmt + i, arg);
	if (arg->width == WIDTH_ARG)
		arg->width = va_arg (va, t_int);
	i += ft_read_precision (fmt + i, arg);
	if (arg->precision == PREC_ARG)
		arg->precision = va_arg (va, t_int);
	i += ft_read_specifier (fmt[i], arg);
	return (i);
}
