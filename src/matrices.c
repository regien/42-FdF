/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:11:58 by regien            #+#    #+#             */
/*   Updated: 2018/03/04 23:36:46 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



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
