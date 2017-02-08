/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:04:51 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/10 00:44:56 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *str1;
	char *str2;

	str1 = (char *)src;
	str2 = (char *)dest;
	while (n != '\0')
	{
		if ((*str2++ = *str1++) == c)
			return (str2);
		n--;
	}
	return (NULL);
}
