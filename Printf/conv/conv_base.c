/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 07:56:33 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/10 07:56:38 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_base(t_conv *c, t_flags *f)
{
	if (f->hast == 1 && ((ft_strcmp(c->s, "0")) == 0))
		f->hast = 0;
	if (f->zero == 1 && (f->hast == 1 || f->flags == 'p') && f->point == 0)
		f->champ -= 2;
	get_zero(c, f);
	c->s = ft_strjoin(c->ze, c->s);
	if ((f->flags == 'x' && f->hast == 1 && f->pos == 0) || f->flags == 'p')
		c->s = ft_strjoin("0x", c->s);
	else if ((f->flags == 'O' || f->flags == 'o') && f->hast == 1)
		c->s = ft_strjoin("0", c->s);
	else if (f->flags == 'X' && f->hast == 1 && f->pos == 0)
		c->s = ft_strjoin("0X", c->s);
	get_sign(c, f);
	get_space(c, f);
	if (f->left == 1)
		c->s = ft_strjoin(c->s, c->sp);
	else
		c->s = ft_strjoin(c->sp, c->s);
	ft_putstr(c->s);
	c->final_len += ft_strlen(c->s);
}

void	handles_x(t_conv *c, t_flags *f)
{
	if ((f->point == 1 && f->preci <= 0) && ft_strcmp(c->s, "0") == 0)
	{
		f->pos = 1;
		c->s = "";
	}
	if (f->preci == 0)
		f->preci = 1;
	if (f->left == 1 && f->zero == 1)
		f->zero = 0;
	if (f->preci < 0)
	{
		f->left = 1;
		f->point = 0;
		f->champ = f->preci;
	}
	f->space = 0;
	f->signe = 0;
	print_base(c, f);
}

void	conv_x(t_conv *c, t_flags *f, int i)
{
	if (f->j == 1 || f->z == 1)
		f->l = 1;
	f->base = f->flags == 'X' || f->flags == 'O' ? 1 : 0;
	if (f->hh == 1 && f->flags != 'O' && f->flags != 'p')
		c->i = (unsigned char)(va_arg(c->ag, int));
	else if (f->h == 1 && f->flags != 'O' && f->flags != 'p')
		c->i = (unsigned short)(va_arg(c->ag, int));
	else if ((f->l == 1 && f->ll == 0) || f->flags == 'O' || f->flags == 'p')
		c->i = va_arg(c->ag, long int);
	else if (f->ll == 1)
		c->i = va_arg(c->ag, long long int);
	else
		c->i = va_arg(c->ag, unsigned int);
	if (c->i >= 0)
		c->s = ft_itoa_base(c->i, i, f->base);
	else
	{
		c->s = ft_itoa_base_neg(c->i, i, f->base);
		f->neg = 1;
	}
	c->slen = ft_strlen(c->s);
	handles_x(c, f);
}
