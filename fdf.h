/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:42 by regien            #+#    #+#             */
/*   Updated: 2018/01/03 18:07:41 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"

typedef struct		s_env
{
	void		*win;
	void		*mlx;
}			t_env;

/*
**	ERRORS HANDLING
*/

void		fillit_print_usage(char *arg);
void		fillit_print_error(int error_code);

/*
**	FUNCTIONS EXCLUSIVE
*/

#endif
