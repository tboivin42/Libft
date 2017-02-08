/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:27:04 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/12 00:37:46 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char *str;
	unsigned char c1;

	str = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (len != '\0')
	{
		if (*str != c1)
			str++;
		else
			return (str);
		len--;
	}
	return (NULL);
}
