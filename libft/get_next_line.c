/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:03:29 by gmalpart          #+#    #+#             */
/*   Updated: 2017/12/15 15:15:19 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fdstore		*look_forit(t_fdstore **fdstore, int fd)
{
	t_fdstore			*idata;

	idata = *fdstore;
	while (idata->next)
	{
		if (idata->fd == fd)
			return (idata);
		idata = idata->next;
	}
	if (idata->fd == fd)
		return (idata);
	return (NULL);
}

static t_fdstore		*create_node(t_fdstore **list, int fd)
{
	t_fdstore			*iterdata;
	t_fdstore			*new;

	new = NULL;
	iterdata = *list;
	if (!iterdata)
	{
		iterdata = (t_fdstore*)ft_memalloc(sizeof(*iterdata));
		iterdata->fd = fd;
		if (!iterdata->str)
			if (!(iterdata->str = ft_strnew(0)))
				return (NULL);
	}
	else if (look_forit(list, fd) == NULL)
	{
		if (!(new = (t_fdstore*)ft_memalloc(sizeof(*iterdata))))
			return (NULL);
		new->fd = fd;
		if (!new->str)
			if (!(new->str = ft_strnew(0)))
				return (NULL);
		new->next = iterdata;
		iterdata = new;
	}
	return (iterdata);
}

static t_fdstore		*resize_node(t_fdstore **list, int fd, char *buf)
{
	t_fdstore			*idata;
	char				*temp;

	idata = *list;
	while (fd != idata->fd)
		idata = idata->next;
	temp = ft_strjoin(idata->str, buf);
	free(idata->str);
	idata->str = temp;
	return (idata);
}

int						doit(t_fdstore **list, char **line, int fd, char *buf)
{
	char				*holder;
	int					pst;
	t_fdstore			*idata;

	free(buf);
	idata = look_forit(list, fd);
	pst = 0;
	while (idata->str[pst] && idata->str[pst] != '\n')
		pst++;
	if (idata->str[pst] == '\n')
	{
		*line = ft_strsub(idata->str, 0, pst);
		holder = ft_strdup(idata->str + (pst + 1));
		free(idata->str);
		idata->str = holder;
	}
	else if (!idata->str[pst])
	{
		*line = ft_strdup(idata->str);
		free(idata->str);
		idata->str = NULL;
	}
	return (1);
}

int						get_next_line(const int fd, char **line)
{
	static t_fdstore	*list;
	char				*buf;
	int					ret;

	if (fd < 0 || !line)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		list = create_node(&list, fd);
		buf[ret] = '\0';
		resize_node(&list, fd, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (!ret && (!((look_forit(&list, fd)->str))
				|| !((look_forit(&list, fd)->str[0]))))
		return (0);
	return (doit(&list, line, fd, buf));
}
