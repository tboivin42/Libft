/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:51:27 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/09 03:36:05 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t l;

	i = 0;
	l = ft_strlen(s1);
	while ((i < n) && (s2[i] != '\0'))
	{
		s1[l + i] = s2[i];
		i++;
	}
	s1[l + i] = '\0';
	return (s1);
}