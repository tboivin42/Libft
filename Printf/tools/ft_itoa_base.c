/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 07:58:41 by tboivin           #+#    #+#             */
/*   Updated: 2017/01/10 07:58:44 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long int n, int b, int conv)
{
	int				len;
	long int		nb_tmp;
	char			*str;
	char			*base;

	base = (conv == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	if (!n)
		return (ft_strdup("0"));
	len = 0;
	nb_tmp = n;
	while (++len && nb_tmp)
		nb_tmp /= b;
	if (!(str = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	while (n != 0)
	{
		if (n % b >= 10)
			str[--len] = base[n % b];
		else
			str[--len] = '0' + (n % b);
		n /= b;
	}
	return (str);
}

char	*ft_itoa_base_neg(unsigned long int n, int b, int conv)
{
	int						len;
	unsigned long int		nb_tmp;
	char					*str;
	char					*base;

	base = (conv == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	if (!n)
		return (ft_strdup("0"));
	len = 0;
	nb_tmp = n;
	while (++len && nb_tmp)
		nb_tmp /= b;
	if (!(str = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	while (n != 0)
	{
		if (n % b >= 10)
			str[--len] = base[n % b];
		else
			str[--len] = '0' + (n % b);
		n /= b;
	}
	return (str);
}
