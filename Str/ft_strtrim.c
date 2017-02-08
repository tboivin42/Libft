/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:10:31 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/12 00:36:11 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strnblanks(char *s, int ln)
{
	while (s[ln - 1] == ' ' || s[ln - 1] == '\t' || s[ln - 1] == '\n')
	{
		if (s[ln - 1] == ' ' || s[ln - 1] == '\t' || s[ln - 1] == '\n')
		{
			ln--;
			ft_strnblanks(s, ln);
		}
	}
	return (ln);
}

char			*ft_strtrim(char const *s1)
{
	char	*dst;
	char	*s;
	int		i;
	int		len;
	int		nlen;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	nlen = ft_strnblanks((char*)s1, len);
	s = (char*)s1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (nlen - i <= 0)
		return (ft_strsub(s, i, len));
	dst = (char*)malloc(sizeof(char) * (nlen - i));
	if (!dst)
		return (NULL);
	dst = ft_strsub(s, i, nlen - i);
	return (dst);
}
