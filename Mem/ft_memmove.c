/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:12:51 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/09 03:28:32 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	if (str1 <= str2)
	{
		while (len != '\0')
		{
			len--;
			str2[len] = str1[len];
		}
	}
	else
		ft_memcpy(str2, str1, len);
	return (str2);
}
