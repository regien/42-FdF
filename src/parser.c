/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:15:18 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 00:32:24 by gmalpart         ###   ########.fr       */
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
	int		y;
	float	calc[4];

	calc[0] = getting_min(coord, envi, 'x');
	calc[1] = getting_min(coord, envi, 'y');
	calc[2] = getting_max(coord, envi, 'x');
	calc[3] = getting_max(coord, envi, 'y');
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
	int		y;
	int		x;

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
