/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:26:02 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 01:25:36 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_xy(t_coord **coord, t_total *envi)
{
	float		gap[2];
	int			x;
	int			y;
	t_coord		*coordx;
	int			mid[2];

	gap[0] = 700 / (envi->colum - 1);
	gap[1] = 600 / (envi->row - 1);
	mid[1] = 0 - (envi->row / 2);
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		mid[0] = 0 - (envi->colum / 2);
		while (++x < envi->colum)
		{
			coordx = &(coord[y][x]);
			coordx->x = (gap[0] * mid[0]);
			coordx->y = (gap[1] * mid[1]);
			if (coordx->z == 0)
				coordx->z = 1;
			mid[0]++;
		}
		mid[1]++;
	}
}

void		draw_row(t_coord **cord, t_total *envi)
{
	t_coord		*holder;
	t_coord		*holdernext;
	int			x;
	int			y;

	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum - 1)
		{
			holder = &(cord[y][x]);
			holdernext = &(cord[y][x + 1]);
			draw_line_ult(holder, holdernext, envi);
		}
	}
}

void		draw_colum(t_coord **cord, t_total *envi)
{
	t_coord		*holder;
	t_coord		*holdernext;
	int			x;
	int			y;

	y = -1;
	while (++y < envi->row - 1)
	{
		x = -1;
		while (++x < envi->colum)
		{
			holder = &(cord[y][x]);
			holdernext = &(cord[y + 1][x]);
			draw_line_ult(holder, holdernext, envi);
		}
	}
}

float		getz_min_max(t_coord **coord, t_total *envi, char letra)
{
	t_coord	*hold;
	int		x;
	int		y;
	float	minz;
	float	maxz;

	minz = coord[0][0].z;
	maxz = coord[0][0].z;
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			if (hold->z < minz)
				minz = hold->x;
			if (hold->z > maxz)
				maxz = hold->y;
		}
	}
	if (letra == 'a')
		return (maxz);
	else
		return (minz);
}

float		getting_max(t_coord **coord, t_total *envi, char letra)
{
	t_coord	*hold;
	int		x;
	int		y;
	float	maxx;
	float	maxy;

	maxx = coord[0][0].x;
	maxy = coord[0][0].y;
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			if (hold->x > maxx)
				maxx = hold->x;
			if (hold->y > maxy)
				maxy = hold->y;
		}
	}
	if (letra == 'x')
		return (maxx);
	else
		return (maxy);
}
