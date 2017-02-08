/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:58:05 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/04 13:58:06 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_mod(char *s, t_flags *f)
{
	if (*s == 'h' && *(s + 1) == 'h')
		f->hh = 1;
	if (*s == 'h')
		f->h = 1;
	if (*s == 'l' && *(s + 1) == 'l')
		f->ll = 1;
	if (*s == 'l' && f->ll == 0)
		f->l = 1;
	if (*s == 'j')
		f->j = 1;
	if (*s == 'z')
		f->z = 1;
}

void	ft_get_flags(char *s, t_flags *f)
{
	if (*s == '+')
		f->signe = 1;
	if (*s == '0' && f->champ == 0 && f->point == 0)
		f->zero = 1;
	if (*s == ' ')
		f->space = 1;
	if (*s == '-')
		f->left = 1;
	if (*s == '#')
		f->hast = 1;
	if (ft_isdigit(*s) && f->champ == 0 && f->point == 0)
		f->champ = ft_atoi(s);
	if (*s == '.')
	{
		f->point = 1;
		f->preci = ft_atoi(s + 1);
	}
	ft_get_mod(s, f);
}
