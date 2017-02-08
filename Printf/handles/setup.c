/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:56:18 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/04 13:56:21 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*start_struct(void)
{
	t_flags *f;

	if (!(f = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	f->espace = 0;
	f->flags = 0;
	f->signe = 0;
	f->point = 0;
	f->zero = 0;
	f->champ = 0;
	f->space = 0;
	f->left = 0;
	f->base = 0;
	f->preci = 0;
	f->hast = 0;
	f->hh = 0;
	f->h = 0;
	f->l = 0;
	f->ll = 0;
	f->j = 0;
	f->z = 0;
	f->pos = 0;
	f->final_len = 0;
	return (f);
}

t_conv		*start_conv(void)
{
	t_conv *s;

	if (!(s = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	s->s = ft_strnew(0);
	s->i = 0;
	s->str = ft_strnew(0);
	s->sp = ft_strnew(0);
	s->ze = ft_strnew(0);
	s->slen = 0;
	return (s);
}

void		free_struct(t_conv *s)
{
	free(s->s);
	free(s->str);
	free(s->sp);
	free(s->ze);
}
