/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:29:49 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/10 07:56:23 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_d(t_conv *c, t_flags *f)
{
	if (f->j == 1 || f->z == 1)
		f->l = 1;
	if (f->hh == 1 && f->flags != 'D')
		c->i = (char)(va_arg(c->ag, int));
	else if (f->h == 1 && f->hh == 0 && f->flags != 'D')
		c->i = (short)(va_arg(c->ag, int));
	else if ((f->l == 1 && f->ll == 0) || f->flags == 'D')
		c->i = va_arg(c->ag, long);
	else if (f->ll == 1)
		c->i = va_arg(c->ag, long long);
	else
		c->i = va_arg(c->ag, int);
	c->s = ft_litoa(c->i);
	if (c->i < 0)
		c->s = ft_strsub(c->s, 1, ft_strlen(c->s));
	c->slen = ft_strlen(c->s);
	handles_d(c, f);
}

void		conv_u(t_conv *c, t_flags *f)
{
	if (f->j == 1 || f->z == 1)
		f->l = 1;
	if (f->hh == 1 && f->flags != 'U')
		c->i = (unsigned char)(va_arg(c->ag, unsigned int));
	else if (f->h == 1 && f->flags != 'U')
		c->i = (unsigned short)(va_arg(c->ag, unsigned int));
	else if (f->l == 1 && f->ll == 0)
		c->i = va_arg(c->ag, unsigned long);
	else if (f->ll == 1 || f->flags == 'U' || f->hh == 1)
		c->i = va_arg(c->ag, unsigned long long);
	else
		c->i = va_arg(c->ag, unsigned int);
	c->s = ft_uitoa(c->i);
	c->slen = ft_strlen(c->s);
	handles_d(c, f);
}

void		handles_d(t_conv *c, t_flags *f)
{
	if (f->flags == 'u' || f->flags == 'U')
	{
		f->neg = 1;
		f->space = 0;
		f->signe = 0;
	}
	if (f->signe == 1)
		f->space = 0;
	if (f->left == 1)
		f->zero = 0;
	print_d(c, f);
}
