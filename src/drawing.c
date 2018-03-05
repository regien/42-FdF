/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:49:11 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 01:41:01 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
** VERSION 2.40
*/

void	init_colors(t_total *envi)
{
	int		i;
	float	r[3];
	float	g[3];
	float	b[3];

	i = -1;
	envi->colors = ft_memalloc(sizeof(int) * 100);
	r[0] = (float)(COLOR1 >> 16 & 0xFF);
	r[1] = (float)(COLOR2 >> 16 & 0xFF);
	g[0] = (float)(COLOR1 >> 8 & 0xFF);
	g[1] = (float)(COLOR2 >> 8 & 0xFF);
	b[0] = (float)(COLOR1 & 0xFF);
	b[1] = (float)(COLOR2 & 0xFF);
	while (++i < 100)
	{
		r[2] = (float)(r[0] * i) / 100 + (float)(r[1] * (100 - i)) / 100;
		g[2] = (float)(g[0] * i) / 100 + (float)(g[1] * (100 - i)) / 100;
		b[2] = (float)(b[0] * i) / 100 + (float)(b[1] * (100 - i)) / 100;
		envi->colors[i] = (int)r[2] << 16 | (int)g[2] << 8 | (int)b[2];
	}
	printf("print color = |%d|\n", envi->colors[50]);
	printf("print color = |%d|\n", envi->colors[70]);
}

void	draw_point(int x, int y, int z, t_total *env)
{
	int				i;
	unsigned int	color;
	float			which;

	if (x > WINW || y > WINH || x < 0 \
			|| y < 0)
		return ;
	i = (x) + (y * env->s_line / 4);
	if (i > WINH * WINW)
		return ;
	which = env->which;
	color = env->colors[(int)which];
	env->pix[i] = color;
	env->pix[++i] = color >> 8;
	env->pix[++i] = color >> 16;
}

int		**set_matrix(int scale)
{
	int		**set;
	int		i;
	int		e;

	i = -1;
	set = ft_memalloc(sizeof(int*) * 3);
	while (++i < 4)
		set[i] = ft_memalloc(sizeof(int) * 3);
	i = -1;
	while (++i < 4)
	{
		e = -1;
		while (++e < 4)
			set[i][e] = 0;
	}
	set[0][0] = scale;
	set[1][1] = scale;
	set[2][2] = scale;
	return (set);
}

void	setbresen(t_coord *co0, t_coord *co1, t_bresen *set)
{
	set->w = co1->x - co0->x;
	set->h = co1->y - co0->y;
	set->dx1 = 0;
	set->dy1 = 0;
	set->dx2 = 0;
	set->dy2 = 0;
	set->w < 0 ? set->dx1 = -1 : 0;
	set->w > 0 ? set->dx1 = 1 : 0;
	set->h < 0 ? set->dy1 = -1 : 0;
	set->h > 0 ? set->dy1 = 1 : 0;
	set->w < 0 ? set->dx2 = -1 : 0;
	set->w > 0 ? set->dx2 = 1 : 0;
	set->longest = abs(set->w);
	set->shortest = abs(set->h);
	if (!(set->longest > set->shortest))
	{
		set->longest = abs(set->h);
		set->shortest = abs(set->w);
		set->h < 0 ? set->dy2 = -1 : 0;
		set->h > 0 ? set->dy2 = 1 : 0;
		set->dx2 = 0;
	}
}

#define EVST envi->setting

void	draw_line_ult(t_coord *co0, t_coord *co1, t_total *envi)
{
	int				x0;
	int				y0;

	x0 = co0->x;
	y0 = co0->y;
	setbresen(co0, co1, envi->setting);
	envi->setting->i = -1;
	envi->setting->numerator = envi->setting->longest >> 1;
	while (++(envi->setting->i) <= envi->setting->longest)
	{
		draw_point(x0, y0, co0->z, envi);
		EVST->numerator = EVST->numerator + EVST->shortest;
		if (!(envi->setting->numerator < envi->setting->longest))
		{
			EVST->numerator = EVST->numerator - EVST->longest;
			x0 = x0 + envi->setting->dx1;
			y0 = y0 + envi->setting->dy1;
		}
		else
		{
			x0 = x0 + envi->setting->dx2;
			y0 = y0 + envi->setting->dy2;
		}
	}
}
