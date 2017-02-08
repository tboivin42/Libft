/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:55:24 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/16 11:55:25 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnwchar(t_conv *c, t_flags *f)
{
	unsigned int	v;
	int				size;

	v = (unsigned int)*c->wtmp;
	size = count_bits(*c->wtmp);
	if (size <= 7)
	{
		if (++c->wi > f->preci && (f->preci != 0 || f->point == 1))
			return (-1);
		ft_putchar(*c->wtmp);
		return (0);
	}
	else if (size <= 11)
	{
		if ((c->wi += 2) > f->preci && (f->preci != 0 || f->point == 1))
			return (-1);
		ft_putchar(((v >> 6) & 31) | 192);
		ft_putchar((v & 63) | 128);
	}
	else
		ft_putnwchar_(c, f, v, size);
	return (0);
}

void	ft_putnwstr(t_conv *c, t_flags *f)
{
	c->wi = 0;
	c->wtmp = c->ws;
	while (c->wtmp && *c->wtmp)
	{
		if (ft_putnwchar(c, f) == -1)
			return ;
		c->wtmp++;
	}
}
