/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 11:27:43 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/11 11:32:34 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_conv *c, t_flags *f)
{
	get_zero(c, f);
	c->s = ft_strjoin(c->ze, c->s);
	get_sign(c, f);
	get_space(c, f);
	if (f->left == 1)
	{
		(f->flags == 'C' || f->l == 1) ? ft_putwchar(c->wc) : ft_putchar(c->c);
		c->s = ft_strjoin(c->s, c->sp);
		ft_putstr(c->s);
	}
	else
	{
		c->s = ft_strjoin(c->sp, c->s);
		ft_putstr(c->s);
		(f->flags == 'C' || f->l == 1) ? ft_putwchar(c->wc) : ft_putchar(c->c);
	}
	if (f->flags == 'C' || f->l == 1)
		c->final_len += ft_wcharlen(c->wc);
	else
		c->final_len += ft_strlen(c->s) + 1;
}

void	handles_c(t_conv *c, t_flags *f)
{
	f->space = 0;
	f->signe = 0;
	if (f->left == 1 && f->zero == 1)
		f->zero = 0;
	if (c->c == '0' && f->champ == 0)
		f->champ = 0;
	if (f->champ > 0 && f->preci < 0)
		f->champ -= 1;
	f->point = 0;
	print_c(c, f);
}

void	conv_c(t_conv *c, t_flags *f)
{
	if (f->l == 1 || f->flags == 'C')
		c->wc = (wchar_t)va_arg(c->ag, int);
	else
		c->c = (char)va_arg(c->ag, int);
	c->slen = 1;
	handles_c(c, f);
}
