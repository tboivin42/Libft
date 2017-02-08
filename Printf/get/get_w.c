/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_w.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:05:42 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/15 06:05:43 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_zero_w(t_conv *c, t_flags *f)
{
	f->espace = f->champ - ft_strnwlen(c, f);
	if (f->espace < 0)
		f->espace = 0;
	c->ze = ft_strset('0', f->espace);
}

void	get_space_w(t_conv *c, t_flags *f)
{
	f->espace = f->champ - ft_strnwlen(c, f);
	if (f->espace < 0)
		f->espace = 0;
	c->sp = ft_strset(' ', f->espace);
}
