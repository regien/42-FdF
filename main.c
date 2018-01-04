/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:40 by regien            #+#    #+#             */
/*   Updated: 2018/01/01 17:10:15 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos_elcapitan/mlx.h"
#include <stdio.h>

/*
	vas  a usar estructuras como negro
*/


int			my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
//	mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
	return (0);
}

void			straight_line(int length, int x, int y, void mlx, void win)
{
	int		i;

	i = -1;
	while (length > i++)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
	}
}

int			main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "testing my shit");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x< 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, my_key_funct, mlx);
//	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	mlx_loop(mlx);
}
