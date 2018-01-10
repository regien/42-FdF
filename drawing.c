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

void			straight_line(int length, int x, int y, void *mlx, void *win)
{
	int		i;

	i = -1;
	while (length > i++)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
	}
}

void			straight_line_y(int length, int x, int y, void *mlx, void *win)
{
	int		i;

	i = -1;
	while (length > i++)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		y++;
	}
}

void			bitch_line(int x0, int y0, int x1, int y1, void *mlx , void *win)
{
	int			dx;
	int			dy;
	int			p;
	int			x;
	int			y;
	
	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p = 2 * dy - dx;
	while (x < x1)
	{
		if (p >= 0)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			p = p + 2 * dy;
		}
		x++;
	}
}
