/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:56:06 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/04 14:56:07 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_zero(t_conv *c, t_flags *f)
{
	len_espace(c, f);
	if (f->flags == 's' && f->zero == 1)
		f->espace = f->champ - ft_strlen(c->s);
	if (f->flags == '%' && f->zero == 1)
		f->espace = f->champ - c->slen;
	if (f->espace < 0)
		f->espace = 0;
	c->ze = ft_strset('0', f->espace);
}

void	get_sign(t_conv *c, t_flags *f)
{
	if (f->signe == 1 && c->i >= 0)
		c->s = ft_strjoin("+", c->s);
	if (f->space == 1 && c->i >= 0)
		c->s = ft_strjoin(" ", c->s);
	if (c->i < 0 && f->neg != 1)
		c->s = ft_strjoin("-", c->s);
}

void	get_space(t_conv *c, t_flags *f)
{
	if (f->flags == 'c' || f->flags == '%')
		f->champ -= 1;
	if (f->flags == 'C')
		f->espace = f->champ - ft_wcharlen(c->wc);
	else
		f->espace = f->champ - ft_strlen(c->s);
	if (f->espace < 0)
		f->espace = 0;
	c->sp = ft_strset(' ', f->espace);
}
