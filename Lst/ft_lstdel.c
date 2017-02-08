/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:08:14 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/12 04:45:13 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;

	if (alst && del)
	{
		while (*alst)
		{
			new = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = new;
		}
		(*alst) = NULL;
	}
}
