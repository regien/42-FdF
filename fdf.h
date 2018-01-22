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

# define WINH 800
# define WINW 800
# define MIN(X, Y)	((X) < (Y) ? (X) : (Y))
# define MAX(X, Y)	((X) < (Y) ? (Y) : (X))
//# include "minilibx_macos_elcapitan/mlx_int.h"

typedef struct		s_node
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_node;


typedef struct		s_env
{
	void		*win;
	void		*mlx;
}			t_env;

typedef struct		s_matrx
{
	int		row;
	int		column;
}			t_matrx;


/*
**	EVENTS FUNCTIONS
*/

int			my_key_function(int keycode, t_env *envi);

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

/*
**	LINKED LIST HELPER
*/


#endif
