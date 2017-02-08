/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:28:44 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/07 20:32:06 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	len_espace(t_conv *c, t_flags *f)
{
	if (c->i < 0 || ((f->signe == 1 || f->space == 1) && c->i >= 0))
	{
		c->slen += 1;
		if (f->point == 1)
			c->slen -= 1;
	}
	f->preci = (f->point == 0) ? f->champ : f->preci;
	f->espace = f->preci - c->slen;
	if (f->preci < 0)
		f->champ = f->preci * -1;
	if (f->zero == 0 && f->point == 0)
		f->espace = 0;
	if (f->preci <= 0 && f->point == 1 && (ft_atoi(c->s)) == 0)
		c->s = ft_strnew(0);
	if ((f->flags == 'O' || f->flags == 'o') && f->hast == 1)
		f->espace -= 1;
	if (f->espace < 0)
		f->espace = 0;
}

void	print_d(t_conv *c, t_flags *f)
{
	get_zero(c, f);
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
