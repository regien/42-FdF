/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 00:06:57 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 06:21:03 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		**init_coord(t_total *envi)
{
	t_coord	**holder;
	int		x;
	int		y;

	(void)y;
	x = -1;
	holder = ft_memalloc(sizeof(t_coord*) * envi->row);
	while (++x < envi->row)
		holder[x] = ft_memalloc(sizeof(t_coord) * envi->colum);
	return (holder);
}

void		set_coordz(t_coord *envi, int i, char *value)
{
	static char **temp;

	(void)i;
	temp = NULL;
	envi->x = 0;
	envi->y = 0;
	if (!(ft_strstr(value, ",")))
		envi->z = (float)atoi(value);
	else
	{
		temp = ft_strsplit(value, ',');
		envi->z = ft_atoi(temp[0]);
	}
	envi->color = 0x012345;
}

void		storage(char *arg, t_total *envi)
{
	int			fd;
	static char	*line;
	static char	**temp;
	int			y;
	int			x;

	if ((fd = open(arg, O_RDONLY)) < 0)
		general_exit(-1, "invalid file\n");
	envi->coord = init_coord(envi);
	x = -1;
	while (get_next_line(fd, &line) > 0 && ++x < envi->row)
	{
		y = 0;
		temp = ft_strsplit(line, ' ');
		while (y < envi->colum)
		{
			set_coordz(&(envi->coord[x][y]), x, (temp[y]));
			y++;
		}
		free(line);
		y = -1;
		while (++y < envi->colum)
			free(temp[y]);
	}
	close(fd);
}

void		parser(char *arg, t_total *envi)
{
	if (parser_argv(arg) == 0 || parser_file(arg, envi) == 0)
		general_exit(-1, "invalid file\n");
	else
		storage(arg, envi);
}
