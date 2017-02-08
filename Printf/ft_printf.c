/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautboivin <thibautboivin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 22:33:01 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/19 03:00:42 by thibautboiv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_conv(char s, t_flags *f)
{
	int		i;
	char	*flags;

	i = 0;
	flags = "bsSpdDioOuUxXcC%";
	while (flags[i] && flags[i] != s)
		i++;
	if (i >= 16)
		return (-1);
	f->flags = *(flags + i);
	return (i);
}

int		ft_print_until(t_conv *c)
{
	int i;

	i = 0;
	while (c->str[i] && c->str[i] != '%')
	{
		ft_putchar(c->str[i]);
		i++;
	}
	return (i);
}

int		ft_init(t_conv *c)
{
	int		i;
	t_flags *f;

	f = start_struct();
	if (!(c->str = ft_strchr(c->str, '%')))
		return (c->final_len);
	c->str++;
	while ((i = ft_get_conv(*c->str, f)) == -1)
	{
		ft_get_flags(c->str, f);
		c->str++;
	}
	if (c->str)
		c->str++;
	handle(f, c);
	c->final_len += ft_print_until(c);
	c->s = ft_strnew(0);
	ft_init(c);
	free(f);
	return (c->final_len);
}

int		ft_printf(const char *format, ...)
{
	t_conv	*c;
	int		len;
	
	len = 0;
	c = start_conv();
	c->final_len = 0;
	c->str = (char*)format;
	len = ft_print_until(c);
	va_start(c->ag, format);
	len += ft_init(c);
	va_end(c->ag);
	free_struct(c);
	free(c);
	return (len);
}
