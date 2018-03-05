/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:42 by regien            #+#    #+#             */
/*   Updated: 2018/03/04 23:58:58 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
// OS 1 = linux / 0 = Mac
# define OS 0
# define ESCAPE -1
# define KEY_C 8
/*
# define KEY_ESC (OS == 1 ? 65307 : 53)
# define KEY_W (OS == 1 ? 119 : 2)
# define KEY_S (OS == 1 ? 115 : 0)
# define KEY_A (OS == 1 ? 97 : 1)
# define KEY_D (OS == 1? 100 : 13)
# define KEY_E (OS == 1 ? 101 : 14)
# define KEY_Q (OS == 1? 113 : 12)
# define KEY_UP (OS == 1? 65362 : 126)
# define KEY_DOWN (OS == 1? 65364 : 125)
# define KEY_LEFT (OS == 1? 65361 : 123)
# define KEY_RIGHT (OS == 1? 65363 : 124)
# define KEY_T (OS == 1 ? 116 : 5)
# define KEY_G (OS == 1 ? 103 : 17)
*/
# define KEY_ESC 53
# define KEY_W 2
# define KEY_S 0
# define KEY_A 1
# define KEY_D 13
# define KEY_E 14
# define KEY_Q 12
# define KEY_R 15
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
//# define KEY_T 5
# define KEY_G 17
# define COLOR1 0xa7f442
# define COLOR2 0xc542f4

//# define COLOR1 0xff0000
//# define COLOR2 0x00FFff

# include "libft.h"
//# include "minilibx/mlx.h"
//# include "minilibx/mlx_int.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# define WINW 1200
# define WINH 800
# define MIN(X, Y)	((X) < (Y) ? (X) : (Y))
# define MAX(X, Y)	((X) < (Y) ? (Y) : (X))

typedef struct		s_keys
{
	int				q:1;
	int				e:1;
	int				w:1;
	int				s:1;
	int				a:1;
	int				d:1;
	int				left:1;
	int				down:1;
	int				right:1;
	int				up:1;
}					t_keys;

typedef struct		s_bresen
{
	int w;
	int	h;
	int	dx1;
	int dy1;
	int dx2;
	int dy2;
	int longest;
	int shortest;
	int	numerator;
	int	i;
}				t_bresen;

typedef struct		s_coord
{
	float				x;
	float				y;
	float				z;
	int				color;
//	struct s_coord			*next;
}					t_coord;


typedef struct		s_total
{
	void		*mlx;
	void		*win;
	t_bresen	*setting;
	t_coord		**coord;
//	posiblemente no sea necesario un dest
	t_coord		**dest;
	// matrix count
	int			row;
	int			colum;
	// img control
	void		*img;
	int			*pix;
	int			bits;
	int			s_line;
	int			endian;
	float		theta;
	float		phi;
	float		psi;	
//	void		*general;

	float		matrix[4][4];
//	ship x, y, and z // check
	int			pushx;
	int			pushy;
//	translate x and y // check
	int			trax;
	int			tray;
	int			traz;

	float		z_min;
	float		z_max;
//	float		focal;
	int			*colors;
	t_keys		*pressed;

	float		scalex;
	float		scaley;
	float		scalez;
}					t_total;

/*
**	MAIN
*/


//int			mouse_hook(int keycode, t_total *envi);
int			mouse_hook(int keycode, int x, int y, t_total *envi);
t_coord		**init_coord(t_total *envi);
// event functions
//int			my_key_function(int keycode, t_total *envi);

void		init_fdf(t_total *envi);
void		draw_everything(t_total *envi);

/*
**	drawing.c
*/

void	init_colors(t_total *envi);
void	draw_point(int x, int y, int z, t_total *env);
int		**set_matrix(int scale);
void	setbresen(t_coord *co0, t_coord *co1, t_bresen *set);
void	draw_line_ult(t_coord *co0, t_coord *co1, t_total *envi);

/*
**	errors_h.c
*/

void		fillit_print_usage(char *arg);
void		general_exit(int error_code, char *mensaje);
int			destroy_exit(int error_code, char *mensaje, void *mlx, void *win);

/*
**	PARSER
*/

void		man_translation(t_coord **coord, t_total *envi);
void		align(t_coord **coord, t_total *envi);
float		getz_min_max(t_coord **coord, t_total *envi, char letra);

/*
** MOPRASER
*/

int			parser_argv(char *str);
int			splitter(char *str, t_total *envi);
int			count_splt(char **str);
int			parser_line(char *line);
int			parser_file(char *str, t_total *envi);

/*
** EXTRAPARSER
*/

t_coord		**init_coord(t_total *envi);
void		loophole(t_total *envi);
void		storage(char *arg, t_total *envi);
void		set_coordz(t_coord *envi, int i, char *value);
void		parser(char *arg, t_total *envi);

/*
**	matrices.c
*/

// check projection
void	projection(t_coord **dest, t_total *envi);
void	init_global(t_total *envi);
void	mat_multi(float mat1[4][4], float mat2[4][4], float dest[4][4]);
void	vec_multmatrix(t_coord *coord, float mat[4][4], t_coord *dest);
void	mat_copy(float source[4][4], float dest[4][4]);


/*
** PROJECTONS
*/

void	init_align(t_total *envi);
void    set_promatri(float matrix[4][4], float angle, float near, float far);
//void    init_projection(t_total *envi);

/*
** INITMAT
*/

void	mat_identity(float mat[4][4]);
void	tr_scale(float matrix[4][4], float sx, float sy, float sz);
void	tr_translate(float matrix[4][4], float tx, float ty, float tz);

/*
** MATRICES AND SOME MATH
*/

void	setmatrix(float matrix[4][4]);
void    setxmat(float xmat[4][4], t_total *envi);
void    setymat(float ymat[4][4], t_total *envi);
void    setzmat(float zmat[4][4], t_total *envi);
void	tr_rotate(float matrix[4][4], t_total *envi);

/*
** HOOKS AND EXTRA HOOKS
*/


int			key_pressed(int keycode, t_total *envi);
int			key_release(int keycode, t_total *envi);
int			expose_hook(t_total *envi);
int			my_key_function(t_total *envi);
int			key_extras(int keycode, t_total *envi);

/*
** RENDER
*/

void		draw_row(t_coord **cord, t_total *envi);
void		draw_colum(t_coord **cord, t_total *envi);
void		set_xy(t_coord **coord, t_total	*envi);
float		getting_min(t_coord **coord, t_total *envi, char letra);
float		getting_max(t_coord **coord, t_total *envi, char letra);

#endif