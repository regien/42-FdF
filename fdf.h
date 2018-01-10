/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:42 by regien            #+#    #+#             */
/*   Updated: 2018/01/09 23:26:22 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ESCAPE -1
# include "libft/includes/libft.h"
//# include "minilibx/mlx.h"
//# include "minilibx/mlx_int.h"
# include "minilibx_macos_elcapitan/mlx.h"
//# include "minilibx_macos_elcapitan/mlx_int.h"

typedef struct		s_node
{
	int		x;
	int		y;
	int		color;
}			t_node;


typedef struct		s_env
{
	void		*win;
	void		*mlx;
}			t_env;

/*
**	ERRORS HANDLINGS MESSAGES
*/

void		fillit_print_usage(char *arg);
void		fillit_print_error(int error_code);
void		general_exit(int error_code, char *mensaje);

/*
 **	FUNCTIONS EXCLUSIVE
*/

void			straight_line(int length, int x, int y, void *mlx, void *win);
void			straight_line_y(int length, int x, int y, void *mlx, void *win);
void			bitch_line(int x0, int y0, int x1, int y1, void *mlx , void *win);

#endif
