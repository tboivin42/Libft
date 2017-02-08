/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:58:49 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/11 13:58:50 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ws(t_conv *c, t_flags *f)
{
	get_zero_w(c, f);
	if (f->zero == 1)
		ft_putstr(c->ze);
	else
		get_space_w(c, f);
	if (f->left == 1)
	{
		ft_putnwstr(c, f);
		ft_putstr(c->sp);
	}
	else if (f->point == 1 && f->preci >= 0)
	{
		ft_putstr(c->sp);
		ft_putnwstr(c, f);
	}
	else
	{
		ft_putstr(c->sp);
		ft_putnwstr(c, f);
	}
	if (f->zero == 1)
		c->final_len += ft_strnwlen(c, f) + ft_strlen(c->ze);
	else
		c->final_len += ft_strnwlen(c, f) + ft_strlen(c->sp);
}

void	handles_s(t_conv *c, t_flags *f)
{
	f->space = 0;
	f->signe = 0;
	if (f->left == 1 && f->zero == 1)
		f->zero = 0;
	if (f->flags == 'S' || f->l == 1)
		print_ws(c, f);
	else
		print_s(c, f);
}

void	print_s(t_conv *c, t_flags *f)
{
	int	i;

	i = ft_strlen(c->s);
	if (f->point == 1 && (f->preci < i))
		c->s = ft_strsub(c->s, 0, f->preci);
	get_zero(c, f);
	if (f->zero == 1)
		c->s = ft_strjoin(c->ze, c->s);
	get_sign(c, f);
	get_space(c, f);
	if (f->left == 1)
		c->s = ft_strjoin(c->s, c->sp);
	else
		c->s = ft_strjoin(c->sp, c->s);
	ft_putstr(c->s);
	c->final_len += ft_strlen(c->s);
}

void	conv_s(t_conv *c, t_flags *f)
{
	if (f->flags == 'S' || f->l == 1)
	{
		c->ws = va_arg(c->ag, wchar_t *);
		if (!c->ws)
			c->ws = L"(null)";
		c->slen = ft_wstrlen(c->ws);
	}
	else
	{
		c->s = va_arg(c->ag, char *);
		if (!c->s)
			c->s = "(null)";
		c->slen = ft_strlen(c->s);
	}
	handles_s(c, f);
}
