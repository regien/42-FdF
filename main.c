/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:40 by regien            #+#    #+#             */
/*   Updated: 2018/02/02 14:26:48 by gmalpart         ###   ########.fr       */
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
	if (keycode == 2)
		envi->theta += 00.01;
	if (keycode == 0)
		envi->theta -= 00.01;
	if (keycode == 13)
		envi->phi += 00.01;
	if (keycode == 1)
		envi->phi -= 00.01;
	if (keycode == 14)
		envi->psi += 00.01;
	if (keycode == 12)
		envi->psi -= 00.01;
	redraw(envi);
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

void	m3d_init(t_total *envi)
{
	int d;
	
	d = -1;
	while(++d < 256)
		{
			envi->sintable[d] = sin(d * M_PI / 128.0);
			envi->costable[d] = cos(d * M_PI / 128.0);
		}
}

void	mat_copy(float source[4][4], float dest[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while(++j < 4)
			dest[i][j] = source[i][j];
	}
}

void	vec_multmatrix(t_coord *coord, float mat[4][4], t_coord *dest)
{
	dest->x = coord->x * mat[0][0] + coord->y * mat[1][0] + \
			coord->z * mat[2][0] + mat[3][0];
	dest->y = coord->x * mat[0][1] + coord->y * mat[1][1] + \
			coord->z * mat[2][1] + mat[3][1];
	dest->z = coord->x * mat[0][2] + coord->y * mat[1][2] + \
			coord->z * mat[2][2] + mat[3][2];
}

void	mat_multi(float mat1[4][4], float mat2[4][4], float dest[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while(++j < 4)
		{
			dest[i][j] = mat1[i][0] * mat2[0][j] + \
						mat1[i][1] * mat2[1][j] + \
						mat1[i][2] * mat2[2][j] + \
						mat1[i][3] * mat2[3][j]; 
		}
	}
}

void	mat_identity(float mat[4][4])
{
	mat[0][0]=1;
	mat[0][1]=0;
	mat[0][2]=0;
	mat[0][3]=0;
    mat[1][0]=0;
	mat[1][1]=1;
	mat[1][2]=0;
	mat[1][3]=0;
	mat[2][0]=0;
	mat[2][1]=0;
	mat[2][2]=1;
	mat[2][3]=0;
	mat[3][0]=0;
	mat[3][1]=0;
	mat[3][2]=0;
	mat[3][3]=1;
}

void	tr_translate(float matrix[4][4], float tx, float ty, float tz)
{
	float tmat[4][4];
	float	mat1[4][4];

	tmat[0][0] = 1;
	tmat[0][1] = 0;
	tmat[0][2] = 0;
	tmat[0][3] = 0;
	tmat[1][0] = 0;
	tmat[1][1] = 1;
	tmat[1][2] = 0;
	tmat[1][3] = 0;
	tmat[2][0] = 0;
	tmat[2][1] = 0;
	tmat[2][2] = 1;
	tmat[2][3] = 0;
	tmat[3][0] = tx;
	tmat[3][1] = ty;
	tmat[3][2] = tz;
	tmat[3][3] = 1;
	mat_multi(matrix, tmat, mat1);
	mat_copy(mat1, matrix);
}

void	tr_scale(float matrix[4][4], float sx, float sy, float sz)
{
	float smat[4][4];
	float mat1[4][4];

	smat[0][0] = sx;
	smat[0][1] = 0;
	smat[0][2] = 0;
	smat[0][3] = 0;
	smat[1][0] = 0;
	smat[1][1] = sy;
	smat[1][2] = 0;
	smat[1][3] = 0;
	smat[2][0] = 0;
	smat[2][1] = 0;
	smat[2][2] = sz;
	smat[2][3] = 0;
	smat[3][0] = 0;
	smat[3][1] = 0;
	smat[3][2] = 0;
	smat[3][3] = 1;
	mat_multi(matrix, smat, mat1);
	mat_copy(mat1, matrix);
}

void	setmatrix(float matrix[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while(++j < 4)
			matrix[i][j] = 0;
	}
}

//void	tr_rotate(float matrix[4][4], int ax, int ay, int az, t_total *envi)
void	tr_rotate(float matrix[4][4], t_total *envi)
{
	float xmat[4][4];
	float ymat[4][4];
	float zmat[4][4];
	float mat1[4][4];
	float mat2[4][4];

	setmatrix(xmat);
	setmatrix(ymat);
	setmatrix(zmat);
	xmat[0][0] = 1;
	xmat[1][1] = cos(envi->theta);
	xmat[1][2] = sin(envi->theta);
	xmat[2][1] = -sin(envi->theta);
	xmat[2][2] = cos(envi->theta);
	xmat[3][3] = 1;
	
	ymat[0][0] = cos(envi->phi);
	ymat[0][2] = cos(envi->phi);
	ymat[1][1] = 1;
	ymat[2][0] = sin(envi->phi);
	ymat[2][2] = cos(envi->phi);
	ymat[3][3] = 1;

	zmat[0][0] = cos(envi->psi);
	zmat[0][1] = sin(envi->psi);
	zmat[1][0] = -sin(envi->psi);
	zmat[1][1] = cos(envi->psi);
	zmat[2][2] = 1;
	zmat[3][3] = 1;

	mat_multi(matrix, ymat, mat1);
	mat_multi(mat1, xmat, mat2);
	mat_multi(mat2, zmat, matrix);
}

void	init_align(t_total *envi)
{
	float	global[4][4];
	int		x;
	int		y;
	
	mat_identity(global);
	tr_rotate(global, envi);
	//					scale	width		scale height
	tr_scale(global, (WINW * 1) / 5, (WINH * 1) / 1, 1);
	tr_translate(global, 1, 1, 1);
	y = -1;
	while (++y < 12)
			vec_multmatrix(&(envi->coord[y]), global, &(envi->dest[y]));
}

void	projection(t_coord *dest)
{
	if(!dest->z)
		dest->z = 1;
//											XORIGIN
	dest->x = FOCAL * dest->x / dest->y + 400;
	dest->y = FOCAL * dest->y / dest->y + 400;
}

void	init_global(t_total *envi)
{
	float	global[4][4];
	int		x;
	int		y;
	
	mat_identity(global);
	tr_translate(global, -(50 / 2), -(50 /2), 0);
	tr_scale(global, 1, 1, 0.15);
	y = -1;
	while (++y < 12)
			vec_multmatrix(&(envi->coord[y]), global, &(envi->dest[y]));
//	y = -1;
//	while (++y < 12)
//			projection(&(envi->dest[y]));
}


//  REDRAW -----------------------------------------
void			redraw(t_total *envi)
{
	mlx_clear_window(envi->mlx, envi->win);
	if (envi->img)
		mlx_destroy_image(envi->mlx, envi->img);
	envi->img = mlx_new_image(envi->mlx, WINW, WINH);
	envi->pix = (int*)mlx_get_data_addr(envi->img, &(envi->bits), \
	&(envi->s_line), &(envi->endian));
	init_global(envi);
	init_align(envi);
//	int	**matrix;

//	matrix = set_matrix(1);

	int e;
	e = -1;
	while (++e < 12)
	{
//		xz_rotation(&(envi->coord[e]), envi);
//		yz_rotation(&(envi->coord[e]), envi);
//		xy_rotation(&(envi->coord[e]), envi);
		
	}
	for(e = 0; e < 11; e++)
		draw_line_ult(envi->dest[e].x, envi->dest[e].y, \
		envi->coord[e + 1].x, envi->coord[e + 1].y , envi);

//	mlx_do_key_autorepeatoff(envi->mlx);
	mlx_hook(envi->win, 4, 0, my_key_function, envi);
	mlx_hook(envi->win, 2, 0, my_key_function, envi);
	mlx_put_image_to_window(envi->mlx, envi->win, envi->img, 0, 0);
	printf("pendejada = |%f|\n", envi->theta);
	mlx_loop(envi->mlx);
}


int				main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	void		*img;

	t_total		*envi;

// parser

/*
	if (argc != 2)
	{
		fillit_print_usage(argv[0]);
		return (0);
	}

	// allocating a matrix;
//	matrix = ft_memalloc(sizeof(t_matrx));

	if (parser_argv(argv[1]) == 0 || parser_file(argv[1], &list, &matrix) == 0)
	{
		general_exit(ESCAPE, "invalid file or map\n");
		return (0);
	}
*/
	envi = ft_memalloc(sizeof(t_total));
	envi->setting = ft_memalloc(sizeof(t_bresen));
	envi->coord = ft_memalloc(sizeof(t_coord) * 12);
	envi->dest = ft_memalloc(sizeof(t_coord) * 12);
	envi->mlx = mlx_init();
	envi->win = mlx_new_window(envi->mlx, WINW, WINH, "testing my shit");
	envi->theta = 0;
	envi->phi = 0;
	envi->psi = 0;

	t_coord	*ptr;
	int		xori = 400;
	int		yori = 400;
	ptr = envi->coord;
	set_node(xori + 100, yori + 100, 100, &(ptr[0]));
	set_node(xori - 100, yori - 100, 100, &(ptr[1]));
	set_node(xori - 100, yori + 100, -100, &(ptr[2]));

	set_node(xori + 100, yori + 100, 100, &(ptr[3]));
	set_node(xori - 100, yori - 100, 100, &(ptr[4]));
	set_node(xori + 100, yori - 100, -100, &(ptr[5]));

	set_node(xori - 100, yori + 100, -100, &(ptr[6]));
	set_node(xori + 100, yori - 100, -100, &(ptr[7]));
	set_node(xori + 100, yori + 100, 100, &(ptr[8]));

	set_node(xori - 100, yori + 100, -100, &(ptr[9]));
	set_node(xori + 100, yori - 100, -100, &(ptr[10]));
	set_node(xori - 100, yori - 100, 100, &(ptr[11]));
	m3d_init(envi);
	mat_identity(envi->matrix1);

//	draw_line_ult(0, 700, 300, 0, envi);
//	while ()

//	mlx_clear_window(mlx, win);
//	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);

//	multi loop hook, perfect for stuff like wolf3d and some super weird stuff
//	that you can do in this project.
//	mlx_loop_hook(envi->mlx, my_key_function, envi);
	printf("pendejada\n");

// GOOD SHIT
	redraw(envi);
}

/*
	draw_line_ult(150, 200, 600, 0, envi);
	draw_line_ult(150, 200, 300, 0, envi);
	draw_line_ult(150, 200, 200, 0, envi);
	draw_line_ult(150, 200, 100, 0, envi);
	draw_line_ult(0, 700, 300, 0, envi);
	draw_line_ult(0, 700, 300, 0, envi);
	draw_line_ult(0, 400, 500, 400, envi);
	draw_line_ult(0, 400, 500, 400, envi);
*/
