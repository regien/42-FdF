/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:40 by regien            #+#    #+#             */
/*   Updated: 2018/02/07 05:33:00 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
	vas  a usar estructuras como negro
*/

// cambiar escapes de fillit
// MENSAJES PERSONALIZADOS - CODIGO DE ERROR
//
int			my_key_function(int keycode, t_total *envi)
{
	printf("key event %d\n", keycode);
	if (keycode == KEY_ESC)
		destroy_exit(ESCAPE, "gracias por usar esta pendejada\n", envi->mlx, envi->win);
	if (keycode == KEY_C)
		mlx_clear_window(envi->mlx, envi->win);
	if (keycode == KEY_D)
		envi->theta += 00.01;
	if (keycode == KEY_A)
		envi->theta -= 00.01;
	if (keycode == KEY_W)
		envi->phi += 00.01;
	if (keycode == KEY_S)
		envi->phi -= 00.01;
	if (keycode == KEY_E)
		envi->psi += 00.01;
	if (keycode == KEY_Q)
		envi->psi -= 00.01;
// flechas
	if (keycode == KEY_RIGHT)
		envi->trax += 1;
	if (keycode == KEY_LEFT)
		envi->trax -= 1;
	if (keycode == KEY_DOWN)
		envi->tray += 1;
	if (keycode == KEY_UP)
		envi->tray -= 1;
	
// triying focal distance	
	if (keycode == KEY_T)
		envi->focal -= 0.1;
	if (keycode == KEY_G)
		envi->focal += 0.1;
	// H
	if (keycode == 104)
	{
		int y = -1;
		while (++y < envi->row)
		{
			int x = -1;
			while (++x < envi->colum)
			{
				printf("pendejada = |%f|\n", envi->projected[y][x].x);
				printf("pendejada = |%f|\n", envi->projected[y][x].y);
				printf("pendejada = |%f|\n\n", envi->projected[y][x].z);
			}
		}
	}
	loophole(envi);
	return (0);
}

int			mouse_hook(int keycode, t_total *envi)
{
	printf("key event %d\n", keycode);
	if (keycode == 1)
		;
//		envi->phi -= 00.01;
	return (0);
}

// for now only works with parsing the name, now we are opening the file
// and build a valid matrix and start creating the structure
// FIRST PART PARSER
int			parser_argv(char *str)
{
	int		i;
	int		dots;

	dots = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_strlen(str) == 4)
			return (0);
		if (str[i] == '.')
			dots++;
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || dots >= 2)
			return (0);
	}
	if ((ft_strequ((ft_strstr(str, ".fdf")), ".fdf")) == 0)
		return (0);
	return (1);
}

int			count_splt(char **str)
{
		int	i;

		i = 0;
		while (str[i] != NULL)
			i++;
		return (i);
}

// NO ENDING | suppose to have a list as an argument to storage the linked list
int		splitter(char *str, t_total *envi)
{
	static char	**temp;
	int					i;

	i = -1;
	printf("matrix = %i\n", count_splt(ft_strsplit(str, ' ')));
	temp = ft_strsplit(str, ' ');
	// tamaño calculado
	if (envi->colum != 0)
	{
		if (envi->colum != count_splt(temp))
			general_exit(-1, "invalid map\n");
	}
	else
		envi->colum = count_splt(temp);
	i = -1;
	while (++i < envi->colum)
		free(temp[i]);
	// calcular de que tamano es el doble pointer
//	while (++i < envi->row)
//		add_list(list, temp[i]);
	return (1);
}

// take care of is_valid_hex || NOT HERE, IN THE SPLIT
int			parser_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (i == 0 && line[i] == ' ')
			return (0);
		if (line[i] == '\t')
			return (0);
// no todo los mapas deben ser tan exactos
//		if (line[i] == ' ')
//			if (line[i + 1] == ' ' || line[i + 1] == '\0')
//				return (0);
		if ((line[i] >= 'g' && line[i] <= 'z') || \
		(line[i] >= 'G' && line[i] <= 'Z'))
			return (0);
	}
	return (1);
}

// this is for parsing colors
/*
int			parser_island(char *island)
{
	int		i;

	i = -1;
	while(island[++i])
	{
		if (island[i] == ',')
			if (island[i + 1] == '0')
				if (island[i + 2] == 'x')
					
	}
}
*/

int			parser_file(char *str, t_total *envi)
{
	int		fd;
	static char	*line;
//	t_total		*envi;
	
//	envi = *envire;
	envi->row = 0;
	envi->colum = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
			general_exit(-1, "invalid file\n");
	// change to if so only reads once / testing only
	printf("PENDEJADA\n");
	while ((get_next_line(fd, &line) > 0))
	{
		(envi->row)++;
		printf("matrix->row = %d\n", envi->row);
		if (parser_line(line) == 0 || splitter(line, envi) == 0)
		{
		//	printf("falla, falla en el parser dentro\n");
			return (0);
			// returning just for testing only
			// funcion para agregar a lista y setear matrix number
		}
		free(line);
	}
	close(fd);
	return (1);
}

t_coord		**init_coord(t_total *envi)
{
	t_coord **holder;
	int x;
	int y;

	x = -1;
	holder = ft_memalloc(sizeof(t_coord*) * envi->row);
	while (++x < envi->row)
		holder[x] = ft_memalloc(sizeof(t_coord) * envi->colum);
	return (holder);
}


void		set_coordz(t_coord *envi, int i, char *value)
{
	envi->x = 0;
	envi->y = 0;
	envi->z = (float)atoi(value);
	envi->color = 0x012345;
	// PARSE ISLAND IS SUPOSSE TO BE HERE
}

void		storage(char *arg, t_total *envi)
{
	int		fd;
	static char	*line;
	static char **temp;
	int		y;
	int		x;

	if ((fd = open(arg, O_RDONLY)) < 0)
			general_exit(-1, "invalid file\n");
	printf("just checking, row = |%d| column = |%d|\n", envi->row, envi->colum);
	envi->coord = init_coord(envi);
	x =-1;
	while (get_next_line(fd, &line) > 0 && ++x < envi->row)
	{
		y = 0;
		temp = ft_strsplit(line, ' ');
		while (y < envi->colum)
		{
			set_coordz(&(envi->coord[x][y]), x, (temp[y]));
			y++;
		}
		free(line);
		y = -1;
		while (++y < envi->colum)
			free(temp[y]);
	}
	ft_putstr("done\n");
	close(fd);
}

void		parser(char *arg, t_total *envi)
{
	t_coord *temp;

	if (parser_argv(arg) == 0 || parser_file(arg, envi) == 0)
		general_exit(-1, "invalid file\n");
	else
		storage(arg, envi);
}

void		loophole(t_total *envi)
{
	if (envi->img)
		mlx_destroy_image(envi->mlx, envi->img);
	envi->img = mlx_new_image(envi->mlx, WINW, WINH);
	envi->pix = (int*)mlx_get_data_addr(envi->img, &(envi->bits), \
	&(envi->s_line), &(envi->endian));
	set_xy(envi->coord, envi);
	init_align(envi);
//	rotate_xy(envi->coord, envi);
//	rotate_xy(envi->coord, envi->dest, envi);
	projection(envi->dest, envi);
//	init_projection(envi);

// uncomment me
//	rotate_yz(envi->coord, envi->dest, envi);
//	rotate_xz(envi->dest, envi->dest, envi);

// REAL CENTER
		align(envi->dest, envi);
// manual translation
	man_translation(envi->dest, envi);

//	perspective_tra(envi->dest, envi);

	draw_row(envi->dest, envi);
	draw_colum(envi->dest, envi);
	mlx_put_image_to_window(envi->mlx, envi->win, envi->img, 0, 0);
	mlx_hook(envi->win, 2, 0, my_key_function, envi);
	mlx_hook(envi->win, 4, 5, mouse_hook, envi);
	mlx_loop(envi->mlx);
}

int				main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	void		*img;

	t_total		*envi;

	envi = ft_memalloc(sizeof(t_total));
// parser
	if (argc != 2)
		fillit_print_usage(argv[0]);
	parser(argv[1], envi);
	envi->setting = ft_memalloc(sizeof(t_bresen));
	envi->mlx = mlx_init();
	envi->win = mlx_new_window(envi->mlx, WINW, WINH, "testing my shit");
//	envi->pushx = 250;
//	envi->pushy = 700;
	envi->tray = 0;
	envi->trax = 0;
	envi->traz = 0;
//	envi->img = mlx_new_image(envi->mlx, WINW, WINH);
//	envi->pix = (int*)mlx_get_data_addr(envi->img, &(envi->bits), \
	&(envi->s_line), &(envi->endian));
	envi->theta = 0;
	envi->phi = 0;
	envi->psi = 0;
//	envi->focal = -1;
//	envi->theta = 0.20;
//	m3d_init(envi);
//	mat_identity(envi->matrix1);
	set_xy(envi->coord, envi);
	envi->z_min = 2147483647;
	envi->z_max = -2147483648;
	envi->z_min = getz_min_max(envi->coord, envi, 'u');
	envi->z_max = getz_min_max(envi->coord, envi, 'a');
	
	
	int y = -1;
	int x = -1;
	printf("pendejada = |%f|\n", envi->theta);
//	rotate_xy(envi->coord, envi);
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
	envi->projected = init_coord(envi);

//	draw_row(envi->coord, envi);
//	draw_colum(envi->coord, envi);
//	redraw(envi);
	loophole(envi);
}