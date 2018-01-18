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

/*
#define f(x) 
*/
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