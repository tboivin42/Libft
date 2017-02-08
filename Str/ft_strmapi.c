/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:57:54 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/10 05:19:10 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * ft_strlen(s) + 1);
	if (str != '\0')
	{
		while (s[i] && *s)
		{
			str[i] = (*f)(j, s[i]);
			i++;
			j++;
		}
		str[i] = '\0';
	}
	return (str);
}
