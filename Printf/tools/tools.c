/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:07:43 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/06 18:08:28 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_cstrwlen_(t_conv *c, t_flags *f, int size)
{
	if (size <= 16)
	{
		if (c->wi + 3 > f->preci && (f->preci != 0 || f->point == 1))
			return (-1);
		c->wi += 3;
	}
	else
	{
		if (c->wi + 4 > f->preci && (f->preci != 0 || f->point == 1))
			return (-1);
		c->wi += 4;
	}
	return (0);
}

int		ft_cstrwlen(t_conv *c, t_flags *f)
{
	int				size;

	size = count_bits(*c->wtmp);
	if (size <= 7)
	{
		if (c->wi + 1 > f->preci && (f->preci != 0 || f->point == 1))
			return (-1);
		c->wi++;
		return (0);
	}
	else if (size <= 11)
	{
		if (c->wi + 2 > f->preci && (f->preci != 0 || f->point == 1))
			return (-1);
		c->wi += 2;
	}
	else if ((ft_cstrwlen_(c, f, size)) == -1)
		return (-1);
	return (0);
}

size_t	ft_strnwlen(t_conv *c, t_flags *f)
{
	c->wi = 0;
	c->wtmp = c->ws;
	while (c->wtmp && *c->wtmp)
	{
		if (ft_cstrwlen(c, f) == -1)
			return (c->wi);
		c->wtmp++;
	}
	return (c->wi);
}

void	*ft_strset(int c, size_t len)
{
	char *s;

	s = ft_strnew(len);
	while (len > 0)
	{
		len--;
		s[len] = c;
	}
	return (s);
}

int		ft_putnwchar_(t_conv *c, t_flags *f, size_t v, int size)
{
	if (size <= 16)
	{
		if ((c->wi += 3) > f->preci && (f->preci != 0 || f->point == 1))
			return (-1);
		ft_putchar(((v >> 12) & 15) | 224);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	else
	{
		if ((c->wi += 4) > f->preci && (f->preci != 0 || f->point == 1))
			return (-1);
		ft_putchar(((v >> 18) & 7) | 240);
		ft_putchar(((v >> 12) & 63) | 128);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	ft_putchar((v & 63) | 128);
	return (0);
}
