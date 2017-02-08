/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 03:56:31 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/09 01:30:28 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t l;

	i = 0;
	l = ft_strlen(s2);
	if (!s2)
		return ((char *)s1);
	while (s1[i] != '\0' && l + i <= len)
	{
		if ((ft_strncmp(s1 + i, s2, l)) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
