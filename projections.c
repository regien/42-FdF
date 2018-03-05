/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:05:44 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/04 23:22:39 by gmalpart         ###   ########.fr       */
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
	//					scale	width		scale height
//	tr_scale(global, (WINW * 1) / 5, (WINH * 1) / 1, 1);
//	tr_translate(global, 1, 1, 1);
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

void    set_promatri(float matrix[4][4], float angle, float near, float far)
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

void    init_projection(t_total *envi)
{
	float	projection[4][4];
    float   wtocamera[4][4];
    t_coord **temp;
	int		x;
	int		y;

    temp = init_coord(envi);
	set_promatri(projection, 90, 0.01, 100);
    y = -1;
    while (++y < 4)
    {
        x = -1;
        while (++x < 4)
            printf("pendejada[%d][%d] = %f\n", y, x, projection[y][x]);
    }
    setmatrix(wtocamera);
    wtocamera[3][1] = -10;
    wtocamera[3][2] = -20;
//	tr_rotate(global, envi);
	//					scale	width		scale height
//	tr_scale(global, (WINW * 1) / 5, (WINH * 1) / 1, 1);
//	tr_translate(global, 1, 1, 1);
	y = -1;
	while (++y < envi->row)
    {
        x = -1;
        while (++x < envi->colum)
        {
			vec_multmatrix(&(envi->dest)[y][x], \
            wtocamera, &(envi->dest)[y][x]);
			vec_multmatrix(&(envi->dest)[y][x], \
            projection, &(envi->projected)[y][x]);
//            if (CORTO(x) < -1 || CORTO(x) > 1)
        }
    }
}
