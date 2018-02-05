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


void	draw_line_ult(int x0, int y0, int x1, int y1, t_total *envi)
{
	int		w;
	int		h;
	int		dx1;
	int		dy1;
	int		dx2;
	int		dy2;
	int		longest;
	int		shortest;


	w = x1 - x0;
	h = y1 - y0;
	// setting values
	dx1 = 0;
	dy1 = 0;
	dx2 = 0;
	dy2 = 0;
	if (w < 0)
		dx1 = -1;
	else if (w > 0)
		dx1 = 1;
	if (h < 0)
		dy1 = -1;
	else if (h > 0)
		dy1 = 1;
	if (w < 0)
		dx2 = -1;
	else if (w > 0)
		dx2 = 1;
	longest = abs(w);
	shortest = abs(h);
	if (!(longest > shortest))
	{
		longest = abs(h);
		shortest = abs(w);
		if (h < 0)
			dy2 = -1;
		else if (h > 0)
			dy2 = 1;
		dx2 = 0;
	}
	
	int		numerator;
	int		i;
	
	i = -1;
	numerator = longest >> 1;
	while (++i <= longest)
	{
		mlx_pixel_put(envi->mlx, envi->win, x0, y0, 0xFFFFFF);
		numerator = numerator + shortest;
		if (!(numerator < longest))
		{
			numerator = numerator - longest;
			x0 = x0 + dx1;
			y0 = y0 + dy1;
		}
		else
		{
			x0 = x0 + dx2;
			y0 = y0 + dy2;
		}
	}
}
// cambialo mas tarde

/*
void	draw_point(t, t_)
{
	
}


void	draw_line_ult(int x0, int y0, int x1, int y1, t_env *envi)
{
	w = x1 - x0;
	h = y1 - y0;
	// setting values
	dx1 = 0;
	dy1 = 0;
	dx2 = 0;
	dy2 = 0;
	if (w < 0)
		dx1 = -1;
	else if (w > 0)
		dx1 = 1;
	if (h < 0)
		dy1 = -1;
	else if (h > 0)
		dy1 = 1;
	if (w < 0)
		dx2 = -1;
	else if (w > 0)
		dx2 = 1;
	longest = abs(w);
	shortest = abs(h);
	if (!(longest > shortest))
	{
		longest = abs(h);
		shortest = abs(w);
		if (h < 0)
			dy2 = -1;
		else if (h > 0)
			dy2 = 1;
		dx2 = 0;
	}
	
	int		numerator;
	int		i;
	
	i = -1;
	numerator = longest >> 1;
	while (++i <= longest)
	{
		mlx_pixel_put(envi->mlx, envi->win, x0, y0, 0xFFFFFF);
		numerator = numerator + shortest;
		if (!(numerator < longest))
		{
			numerator = numerator - longest;
			x0 = x0 + dx1;
			y0 = y0 + dy1;
		}
		else
		{
			x0 = x0 + dx2;
			y0 = y0 + dy2;
		}
	}
}




*/