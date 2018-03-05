/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathmat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:02:13 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/04 22:03:07 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void     setxmat(float xmat[4][4], t_total *envi)
{
	xmat[0][0] = 1;
	xmat[1][1] = cos(envi->theta);
	xmat[1][2] = sin(envi->theta);
	xmat[2][1] = -sin(envi->theta);
	xmat[2][2] = cos(envi->theta);
	xmat[3][3] = 1;
}

void    setymat(float ymat[4][4], t_total *envi)
{
	ymat[0][0] = cos(envi->phi);
	ymat[0][2] = -sin(envi->phi);
	ymat[1][1] = 1;
	ymat[2][0] = sin(envi->phi);
	ymat[2][2] = cos(envi->phi);
	ymat[3][3] = 1;
}

void    setzmat(float zmat[4][4], t_total *envi)
{
	zmat[0][0] = cos(envi->psi);
	zmat[0][1] = sin(envi->psi);
	zmat[1][0] = -sin(envi->psi);
	zmat[1][1] = cos(envi->psi);
	zmat[2][2] = 1;
	zmat[3][3] = 1;
}

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
    setxmat(xmat, envi);
    setymat(ymat, envi);
    setzmat(zmat, envi);
	mat_multi(matrix, ymat, mat1);
	mat_multi(mat1, xmat, mat2);
	mat_multi(mat2, zmat, matrix);
}
