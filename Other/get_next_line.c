/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 03:13:14 by tboivin           #+#    #+#             */
/*   Updated: 2016/12/13 04:02:36 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			read_line(int const fd, char **line, char **stock)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		*line = *stock;
		*stock = ft_strjoin(*line, buff);
		ft_strdel(line);
		*line = ft_strchr(*stock, '\n');
		return (1);
	}
	if (ret == 0)
	{
		*line = ft_strchr(*stock, '\n');
		if (*line == NULL)
		{
			*line = ft_strchr(*stock, '\0');
			if (!ft_strlen(*stock))
				return (0);
		}
		return (1);
	}
	return (-1);
}

t_stock		*create_list(int fd)
{
	t_stock		*stock;

	stock = (t_stock*)malloc(sizeof(t_stock));
	if (!stock)
		return (NULL);
	stock->fd = fd;
	stock->data = ft_strnew(0);
	stock->next = NULL;
	return (stock);
}

t_stock		*get_list(int fd)
{
	static t_stock	*stock = NULL;
	t_stock			*tmp;

	tmp = stock;
	if (fd < 0)
		return (0);
	while (tmp)
	{
		if (fd == tmp->fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (stock)
	{
		tmp = stock;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_list(fd);
		return (tmp->next);
	}
	else
		return (stock = create_list(fd));
}

int			get_next_line(int const fd, char **line)
{
	int			i;
	char		*tmp;
	t_stock		*stock;

	i = 0;
	if (!line)
		return (-1);
	*line = NULL;
	if (!(stock = get_list(fd)))
		return (-1);
	while (*line == NULL && i != -1)
		i = read_line(stock->fd, line, &stock->data);
	if (i == -1)
		return (-1);
	tmp = *line;
	if (!(*line = ft_strsub(stock->data, 0, *line - stock->data)))
		return (-1);
	if (i == 0)
		return (0);
	if (!(stock->data = ft_strdup(tmp + 1)))
		return (-1);
	return (1);
}
