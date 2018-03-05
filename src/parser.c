/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:15:18 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/04 23:29:48 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		getting_min(t_coord **coord, t_total *envi, char letra)
{
	t_coord	*hold;
	int		x;
	int		y;
	float	minx;
	float	miny;

	minx = coord[0][0].x;
	miny = coord[0][0].y;
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			if (hold->x < minx)
				minx = hold->x;
			if (hold->y < miny)
				miny = hold->y;
		}
	}
	if (letra == 'x')
		return (minx);
	else
		return (miny);
}

void		align(t_coord **coord, t_total *envi)
{
	t_coord	*hold;
	int		x;
	int 	y;
	float	minx;
	float	miny;
	float	maxx;
	float	maxy;


	minx = getting_min(coord, envi, 'x');
	miny = getting_min(coord, envi, 'y');
	maxx = getting_max(coord, envi, 'x');
	maxy = getting_max(coord, envi, 'y');
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			hold->x += (WINW / 2);
			hold->y += (WINH / 2);
			hold->z = hold->z * 1;
		}
	}
}
void		man_translation(t_coord **coord, t_total *envi)
{
	t_coord *hold;
	int y;
	int x;
	
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			hold->x += envi->trax;
			hold->y += envi->tray;
			hold->z += envi->traz;
		}
	}
}
