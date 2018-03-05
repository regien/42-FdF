/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:05:44 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 01:28:55 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_align(t_total *envi)
{
	float	global[4][4];
	int		x;
	int		y;

	mat_identity(global);
	tr_scale(global, 1, 1, 6);
	tr_scale(global, envi->scalex, envi->scaley, envi->scalez);
	tr_rotate(global, envi);
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			vec_multmatrix(&(envi->coord)[y][x], \
					global, &(envi->dest)[y][x]);
		}
	}
}

void	set_promatri(float matrix[4][4], float angle, float near, float far)
{
	float scale;

	setmatrix(matrix);
	scale = 1 / tan(angle * 0.5 * M_PI / 180);
	matrix[0][0] = scale;
	matrix[1][1] = scale;
	matrix[2][2] = -far / (far - near);
	matrix[3][2] = -far * near / (far - near);
	matrix[2][3] = -1;
	matrix[3][3] = 0;
}
