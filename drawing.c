/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:49:11 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/09 22:50:01 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	straight_line(int length, int x, int y, void *mlx, void *win)
{
	int i;

	i = -1;
	while (length > i++)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
	}
}

void	straight_line_y(int length, int x, int y, void *mlx, void *win)
{
	int i;

	i = -1;
	while (length > i++)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		y++;
	}
}

void	draw_rectang(int x0, int y0, int x1, int y1, t_env *env)
{
	int temp;

	temp = x0;
	while (y0 < y1)
	{
		x0 = temp;
		while (x0 < x1)
		{
			mlx_pixel_put(env->mlx, env->win, x0, y0, 0x00FFFFFF);
			x0++;
		}
		y0++;
	}
}

void	draw_circle(int x, int y, int radius, t_env *env)
{
	static double pi;
	double i;
	double angle;
	double x1;
	double y1;

	pi = 3.1415926535;
	i = 0;
	while (i < 360)
	{
		angle = (double)i;
		x1 = radius * cos(angle * pi / 180);
		y1 = radius * sin(angle * pi / 180);
		mlx_pixel_put(env->mlx, env->win, x + x1, y + y1, 0x00FFFFFF);
		i = i + 0.1;
	}
}

// el angulo(i) no tiene que ser en decimales
void	draw_circle_fill(int x, int y, int radius, t_env *env)
{
	static double pi;
	double i;
	double angle;
	double x1;
	double y1;

	pi = 3.1415926535;
	while (radius > 0)
	{
		i = 0;
		while (i < 360)
		{
			angle = (double)i;
			x1 = radius * cos(angle * pi / 180);
//			printf("x1 = %f\n", x1);
			y1 = radius * sin(angle * pi / 180);
//			printf("y1 = %f\n", y1);
			mlx_pixel_put(env->mlx, env->win, x + x1, y + y1, 0x00FFFFFF);
			i = i + 0.1;
		}
		radius--;
	}
}

void	b_line(int x0, int y0, int x1, int y1, t_env *envi)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;

	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p = 2 * dy - dx;
	while (x < x1)
	{
		if (p >= 0)
		{
			mlx_pixel_put(envi->mlx, envi->win, x, y, 0x00FFFFFF);
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put(envi->mlx, envi->win, x, y, 0x00FFFFFF);
			p = p + 2 * dy;
		}
		x++;
	}
}

// not fully functional
void	draw_line(int x0, int y0, int x1, int y1, t_env *envi)
{
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	double	err;
	double	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;
	while (!(NULL))
	{
		mlx_pixel_put(envi->mlx, envi->win, x0, y0, 0x00FFFFFF);
		if ((x0 == x1) && (y0 == y1))
			break ;
		e2  = 2 * err;
		if (e2 > -(dy))
		{
			err = err - dy;
			x0 = x0 + sx;
		}
		if (e2 < dx)
		{
			err = err + dy;
			y0 = y0 + sy;
		}
	}
}

/*
#define f(x) 
*/
//doesnt work
void	b_line_3d(int x0, int y0, int z0, int x1, int y1, int z1, t_env *envi)
{
//	int x0;
	double	angle;
	double	ux;
	double	uy;
	double	pi;
	double	distancex;
	double	distancey;

	distancex = x1 - x0;
	distancey = y1 - y0;
	pi = 3.1415926535;
	angle = 45;
	ux = distancex * cos(angle * pi / 180);
	printf("cos = %f && ux = %f\n", cos(angle * pi / 180), ux);
	uy = distancey * sin(angle * pi / 180);
	printf("sin = %f && ux = %f\n", sin(angle * pi / 180), uy);
	b_line(350, 350, 141, 141, envi);
	b_line(x0, y0, (int)ux, (int)uy, envi);
}


void	bre_line(int x0, int y0, int x1, int y1, t_env *envi)
{
	int	mid_new;
	int	error;
	int x;
	int y;
	int	i;

	x = x0;
	y = y0;
	i = 0;
	mid_new = 2 * (y1 - y0);
	error = mid_new - (x1 - x0);
	while (x <= x1)
	{
		mlx_pixel_put(envi->mlx, envi->win, x, y, 0x00FFFFFF);
		error = error + mid_new;
		if (error >= 0)
		{
			y++;
			error = error - (2 * (x1 - x0));
		}
		x++;
	}
}

// PENDEJADAS

void	ho_line(int x0, int y0, int x1, int y1, t_env *envi)
{
	int i;
	int length;
	int x;

	x = MIN(x0, x1);
	length = MAX(x1, x0) - MIN(x1, x0);
	i = -1;
	while (length > ++i)
	{
		mlx_pixel_put(envi->mlx, envi->win, x, y0, 0x00FFFFFF);
		x++;
	}
}

void	ve_line(int x0, int y0, int x1, int y1, t_env *envi)
{
	int i;
	int length;
	int y;

	y = MIN(y0, y1);
	length = MAX(y1, y0) - MIN(y1, y0);
	i = -1;
	while (length > ++i)
	{
		mlx_pixel_put(envi->mlx, envi->win, x0, y, 0x00FFFFFF);
		y++;
	}
}

void	u_bresen(int x0, int y0, int x1, int y1, t_env *envi)
{
	if (x0 < x1)
		bre_line(x0, y0, x1, y1, envi);
	else if (x0 == x1)
		ve_line(x0, y0, x1, y1, envi);
	else if (y0 == y1)
		ho_line(x0, y0, x1, y1, envi);
}

// VERSION 2.40


void	draw_point(int x, int y, int color, t_total *env)
{
	int i;

	if (x > WINW || y > WINH || x < 0 || y < 0)
		return ;
	i = (x) + (y * env->s_line / 4);
	if (i > WINH * WINW)
		return ;
//	env->pix[x + (y * env->s_line / 4)] = color;
	env->pix[i] = color;
//	env->pix[i++] = color;
//	env->pix[i++] = color;
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

void	setbresen(int x0, int y0, int x1, int y1, t_bresen *set)
{
	set->w = x1 - x0;
	set->h = y1 - y0;
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

void	draw_line_ult(int x0, int y0, int x1, int y1, t_total *envi)
{
	t_bresen		*set;
	
	set = envi->setting;
	setbresen(x0, y0, x1, y1, set);
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

void		set_node(int x, int y, int z, t_coord *set)
{
	set->x = x;
	set->y = y;
	set->z = z;
	set->color = 0;
}

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
