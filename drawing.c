/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:49:11 by gmalpart          #+#    #+#             */
/*   Updated: 2018/02/07 05:32:03 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


// VERSION 2.40


void	draw_point(int x, int y, int color, t_total *env)
//void	draw_point(t_coord *coord, t_total *env)
{
	int i;

	if (x > WINW || y > WINH || x < 0 \
	|| y < 0)
		return ;
	i = (x) + (y * env->s_line / 4);
	if (i > WINH * WINW)
		return ;
//	env->pix[x + (y * env->s_line / 4)] = color;
	env->pix[i] = color;
	env->pix[i + 1] = color;
//	env->pix[i + 2] = color;
}

// COMPLEJIDAD 3x3 MATRIX para -- hay otra mas pendeja de 4
// INCOMPLETO

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

//void	setbresen(int x0, int y0, int x1, int y1, t_bresen *set)
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

//void	draw_line_ult(int x0, int y0, int x1, int y1, t_total *envi)
void	draw_line_ult(t_coord *co0, t_coord *co1, t_total *envi)
{
	t_bresen		*set;
	int				x0;
	int				y0;

	x0 = co0->x;
	y0 = co0->y;
	set = envi->setting;
	setbresen(co0, co1, set);
	set->i = -1;
	set->numerator = set->longest >> 1;
	while (++(set->i) <= set->longest)
	{
		draw_point(x0, y0, 0x145400, envi);
		set->numerator = set->numerator + set->shortest;
		if (!(set->numerator < set->longest))
		{
			set->numerator = set->numerator - set->longest;
			x0 = x0 + set->dx1;
			y0 = y0 + set->dy1;
		}
		else
		{
			x0 = x0 + set->dx2;
			y0 = y0 + set->dy2;
		}
	}
}
/*
void		set_node(int x, int y, int z, t_coord *set)
{
	set->x = x;
	set->y = y;
	set->z = z;
	set->color = 0;
}
*/
//this doesnt 
/*
void		xy_rotation(t_coord *set, t_total *envi)
{
	envi->theta = 0.50;
	set->x = (set->x * cos(envi->theta)) + (set->y * sin(envi->theta));
	set->y = (set->x * -(sin(envi->theta))) + (set->y * cos(envi->theta));
	set->z = set->z * 1;
}

void		yz_rotation(t_coord *set, t_total *envi)
{
	envi->theta = 0.50;
	set->y = (set->y * cos(envi->theta)) + (set->z * -(sin(envi->theta)));
	set->z = (set->y * sin(envi->theta)) + (set->z * cos(envi->theta));
	set->x = set->x * 1;
}

// this one work
void		xz_rotation(t_coord *set, t_total *envi)
{
	set->x = (set->x * cos(envi->theta)) + (set->z * sin(envi->theta));
	set->z = (set->x * -(sin(envi->theta))) + (set->z * cos(envi->theta));
	set->y = set->y * 1;
}
*/


/*
void		xy_rotation(t_coord *set, t_total *envi)
{
//	envi->theta = 0.50;
	set->x = (set->x * cos(envi->theta)) + (set->y * sin(envi->theta));
	set->y = (set->x * -(sin(envi->theta))) + (set->y * cos(envi->theta));
	set->z = set->z * 1;
}

void		yz_rotation(t_coord *set, t_total *envi)
{
//	envi->theta = 0.50;
	set->y = (set->y * cos(envi->phi)) + (set->z * -(sin(envi->phi)));
	set->z = (set->y * sin(envi->phi)) + (set->z * cos(envi->phi));
	set->x = set->x * 1;
}

// this one work
void		xz_rotation(t_coord *set, t_total *envi)
{
	set->x = (set->x * cos(envi->psi)) + (set->z * sin(envi->psi));
	set->z = (set->x * -(sin(envi->psi))) + (set->z * cos(envi->psi));
	set->y = set->y * 1;
}
*/