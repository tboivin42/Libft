/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:11:57 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/04 14:11:58 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle(t_flags *f, t_conv *c)
{
	if (f->flags == 'd' || f->flags == 'D' || f->flags == 'i')
		return (conv_d(c, f));
	if (f->flags == 'u' || f->flags == 'U')
		return (conv_u(c, f));
	if (f->flags == 'x' || f->flags == 'X' || f->flags == 'p')
		return (conv_x(c, f, 16));
	if (f->flags == 'O' || f->flags == 'o')
		return (conv_x(c, f, 8));
	if (f->flags == 'c' || f->flags == 'C')
		return (conv_c(c, f));
	if (f->flags == 's' || f->flags == 'S')
		return (conv_s(c, f));
	if (f->flags == 'b')
		return (conv_x(c, f, 2));
	if (f->flags == '%')
		return (conv_hast(c, f));
}
