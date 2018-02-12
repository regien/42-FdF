/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:42 by regien            #+#    #+#             */
/*   Updated: 2018/01/12 12:16:21 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ESCAPE -1
# define KEY_C 8
# define KEY_ESC 53
# include "libft/includes/libft.h"
//# include "minilibx/mlx.h"
//# include "minilibx/mlx_int.h"
# include "minilibx_macos_sierra/mlx.h"
# include <math.h>
# include <stdio.h>

# define WINW 1200
# define WINH 800
# define MIN(X, Y)	((X) < (Y) ? (X) : (Y))
# define MAX(X, Y)	((X) < (Y) ? (Y) : (X))
# define SIN(x) envi->sintable[abs((int)x&255)]
# define COS(x) envi->costable[abs((int)x&255)]
# define FOCAL 200
//# include "minilibx_macos_elcapitan/mlx_int.h"

// KINDA NEW START
// VA DENTRO DE UNA ESTRUCURA MAS GRANDE
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

	// kinda 3d world
	float		sintable[256];
	float		costable[256];
	float		matrix1[4][4];
//	ship x, y, and z
	int			pushx;
	int			pushy;
//	translate x and y
	int			trax;
	int			tray;
	int			traz;
	
	float		focal;
}					t_total;



// PENDEJADA ANTIGUA |||


typedef struct		s_node
{
	float		*x;
	float		*y;
	float		*z;
	int		*color;
}			t_node;


typedef struct		s_env
{
	void		*win;
	void		*mlx;
}			t_env;


/*
**	EVENTS FUNCTIONS
*/

int			my_key_function(int keycode, t_total *envi);

/*
**	ERRORS HANDLINGS MESSAGES
*/

void		fillit_print_usage(char *arg);
void		fillit_print_error(int error_code);
void		general_exit(int error_code, char *mensaje);
void		destroy_exit(int error_code, char *mensaje, void *mlx, void *win);

/*
 **	FUNCTIONS EXCLUSIVE
 ** This is basically me playing around with the minilibx library and see
 ** what can i do.
*/

void			straight_line(int length, int x, int y, void *mlx, void *win);
void			straight_line_y(int length, int x, int y, void *mlx, void *win);
void			b_line(int x0, int y0, int x1, int y1, t_env *envi);
void			draw_rectang(int x0, int y0, int x1, int y1, t_env *env);
void			draw_circle(int x, int y, int radius, t_env *env);
void			draw_circle_fill(int x, int y, int radius, t_env *env);
void	b_line_3d(int x0, int y0, int z0, int x1, int y1, int z1, t_env *envi);
void	draw_line(int x0, int y0, int x1, int y1, t_env *envi);
void	bre_line(int x0, int y0, int x1, int y1, t_env *envi);


void	ho_line(int x0, int y0, int x1, int y1, t_env *envi);
void	ve_line(int x0, int y0, int x1, int y1, t_env *envi);
void	u_bresen(int x0, int y0, int x1, int y1, t_env *envi);

// EXCLUSIVE VERSION 2.0

void	setbresen(int x0, int y0, int x1, int y1, t_bresen *set);
void	draw_line_ult(int x0, int y0, int x1, int y1, t_total *envi);
void	draw_point(int x, int y, int color, t_total *env);
int		**set_matrix(int scale);
void		set_node(int x, int y, int z, t_coord *set);

void		xy_rotation(t_coord *set, t_total *envi);
void		xz_rotation(t_coord *set, t_total *envi);
void		yz_rotation(t_coord *set, t_total *envi);
void			redraw(t_total *envi);
void	m3d_init(t_total *envi);
// scale - 1
void	mat_identity(float mat[4][4]);
void	mat_multi(float mat1[4][4], float mat2[4][4], float dest[4][4]);
void	vec_multmatrix(t_coord *coord, float mat[4][4], t_coord *dest);
void	mat_copy(float source[4][4], float dest[4][4]);


void	tr_scale(float matrix[4][4], float sx, float sy, float sz);
void	tr_translate(float matrix[4][4], float tx, float ty, float tz);
void	setmatrix(float matrix[4][4]);
//void	tr_rotate(float matrix[4][4], int ax, int ay, int az, t_total *envi);
void	tr_rotate(float matrix[4][4], t_total *envi);
void	projection(t_coord *dest);
void	init_global(t_total *envi);
void	init_align(t_total *envi);


/*
**	REFACTOR
*/

void		parser(char *arg, t_total *envi);
int			parser_file(char *str, t_total *envi);
void		storage(char *arg, t_total *envi);
//void		set_coord(t_coord *coord, int z);
//t_coord		*set_coord(int z);
void		set_coordz(t_coord *envi, int i, char *value);
void		set_shit(t_coord *coord, int z);
//t_coord		*init_coord(t_total *envi);
t_coord		**init_coord(t_total *envi);
int			mouse_hook(int keycode, t_total *envi);
void		loophole(t_total *envi);
void		set_xy(t_coord **coord, t_total	*envi);
void		draw_row(t_coord **cord, t_total *envi);
void		draw_colum(t_coord **cord, t_total *envi);
//void		rotate_xy(t_coord **coord, t_total *envi);
void		align(t_coord **coord, t_total *envi);
void		man_translation(t_coord **coord, t_total *envi);
void		rotate_xy(t_coord **coord, t_coord **dest, t_total *envi);
void		rotate_yz(t_coord **coord, t_coord **dest, t_total *envi);
void		rotate_xz(t_coord **coord, t_coord **dest, t_total *envi);
void		perspective_tra(t_coord **coord, t_total *envi);

float		getting_min(t_coord **coord, t_total *envi, char letra);
float		getting_max(t_coord **coord, t_total *envi, char letra);

// linked list mine for this project

void		coord_add_listback(t_coord **list, t_coord *new);
void		adder(t_coord **list, char *str);
t_coord		*create_node(char *str);

#endif