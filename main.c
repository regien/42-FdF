/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:40 by regien            #+#    #+#             */
/*   Updated: 2018/01/07 13:14:40 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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


// for now only works with parsing the name, now we are opening the file
// and build a valid matrix and start creating the structure
int			parseate_esta(char *str)
{
	int		i;
	int		dots;

	dots = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			dots++;
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || dots >= 2)
			return (0);
	}
//	printf("strstr = |%s|\n", ft_strstr(str, ".fdf"));
	if ((ft_strequ((ft_strstr(str, ".fdf")), ".fdf")) == 0)
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	if (argc != 2)
	{
		fillit_print_usage(argv[0]);
		return (0);
	}
	if (parseate_esta(argv[1]) == 0)
	{
		ft_putstr("invalid file or map\n");
		return (0);
	}
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
	straight_line(200, 0,0, mlx, win);
	straight_line_y(200, 200, 0, mlx, win);
//	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	mlx_loop(mlx);
}
