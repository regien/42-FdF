/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:11:58 by regien            #+#    #+#             */
/*   Updated: 2018/02/15 11:12:14 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/*
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
*/

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

    setxmat(xmat, envi);
    setymat(ymat, envi);
    setzmat(zmat, envi);

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

//#define CORTO(k) &(envi->projected)[y][x]->k


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