/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:38:23 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/14 19:38:24 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hast(t_conv *c, t_flags *f)
{
	get_zero(c, f);
	if (f->zero == 1)
		c->s = ft_strjoin(c->ze, c->s);
	get_sign(c, f);
	get_space(c, f);
	c->s = ft_strjoin(c->sp, c->s);
	if (f->left == 1)
	{
		ft_putchar(c->c);
		ft_putstr(c->s);
	}
	else
	{
		ft_putstr(c->s);
		ft_putchar(c->c);
	}
	c->final_len += ft_strlen(c->s) + 1;
}

void	conv_hast(t_conv *c, t_flags *f)
{
	c->c = '%';
	c->slen = 1;
	f->signe = 0;
	f->space = 0;
	print_hast(c, f);
}
