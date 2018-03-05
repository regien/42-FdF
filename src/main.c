/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:40 by regien            #+#    #+#             */
/*   Updated: 2018/03/05 00:09:11 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// cambiar escapes de fillit
// MENSAJES PERSONALIZADOS - CODIGO DE ERROR
//

// for now only works with parsing the name, now we are opening the file
// and build a valid matrix and start creating the structure
// FIRST PART PARSER

void		draw_everything(t_total *envi)
{
	if (envi->img)
		mlx_destroy_image(envi->mlx, envi->img);
	envi->img = mlx_new_image(envi->mlx, WINW, WINH);
	envi->pix = (int*)mlx_get_data_addr(envi->img, &(envi->bits), \
	&(envi->s_line), &(envi->endian));
	init_align(envi);
	envi->z_min = getz_min_max(envi->dest, envi, 'u');
	envi->z_max = getz_min_max(envi->dest, envi, 'a');
	align(envi->dest, envi);
	man_translation(envi->dest, envi);
	draw_row(envi->dest, envi);
	draw_colum(envi->dest, envi);
	mlx_put_image_to_window(envi->mlx, envi->win, envi->img, 0, 0);
}

void		loophole(t_total *envi)
{
	envi->pressed = ft_memalloc(sizeof(t_keys));
	mlx_expose_hook(envi->win, expose_hook, envi);
//	mlx_mouse_hook(envi->win, key_extras,envi);
	mlx_hook(envi->win, 2, 0, key_pressed, envi);
//	mlx_hook(envi->win, 6, 0, key_extras, envi);
	mlx_hook(envi->win, 3, 0, key_release, envi);
	mlx_hook(envi->win, 17, 0, destroy_exit, envi);
	mlx_hook(envi->win, 4, 5, mouse_hook, envi);
	mlx_loop_hook(envi->mlx, my_key_function, envi);
//	mlx_loop_hook(envi->mlx, mouse_hook, envi);
	mlx_loop(envi->mlx);
}

void		init_fdf(t_total *envi)
{
	envi->tray = 0;
	envi->trax = 0;
	envi->traz = 0;
	envi->theta = 0;
	envi->phi = 0;
	envi->psi = 0;
	envi->scalex = 1;
	envi->scaley = 1;
	envi->scalez = 1;
	envi->z_min = 2147483647;
	envi->z_max = -2147483648;
	envi->z_min = getz_min_max(envi->coord, envi, 'u');
	envi->z_max = getz_min_max(envi->coord, envi, 'a');
	init_colors(envi);
	set_xy(envi->coord, envi);
}


int				main(int argc, char **argv)
{
	t_total		*envi;

	envi = ft_memalloc(sizeof(t_total));
// parser
	if (argc != 2)
		fillit_print_usage(argv[0]);
	parser(argv[1], envi);
	envi->setting = ft_memalloc(sizeof(t_bresen));
//	printf("testing = = = |%d|", envi->pressed->d);
	envi->mlx = mlx_init();
	envi->win = mlx_new_window(envi->mlx, WINW, WINH, "42 - FDF _ MEXVersion");
	
	init_fdf(envi);

	int y = -1;
	int x = -1;
	printf("pendejada = |%f|\n", envi->theta);

// TESTING ONLY
	while (++x < envi->row)
	{
		y = 0;
		while (y < envi->colum)
		{
		printf("pendejada[x] = |%f|\n", envi->coord[x][y].x);
		printf("pendejada[y] = |%f|\n", envi->coord[x][y].y);
		printf("pendejada[z] = |%f|\n\n\n", envi->coord[x][y].z);
		y++;
		}
	}

/// INITIALIZING COORDINATES
	envi->dest = init_coord(envi);
//	envi->projected = init_coord(envi);

	loophole(envi);
}
