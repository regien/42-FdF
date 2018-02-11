/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:15:18 by gmalpart          #+#    #+#             */
/*   Updated: 2018/02/06 18:15:24 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
t_list		*bitch_me_a_list(t_list **list, char **pendejada)
{
	t_list	*iter;
	t_node	*iterdata;

	if ()
}
*/

///		HELPER LINKED LIST FUNCTION

// NOT OPTIMAZED
/*
t_list		*create_node(char *str)
{
	t_node		*new;

	if(!(new = ft_memalloc(sizeof(t_node))))
		return (0);
	new->x = ft_atoi(str);
	new->y = 0;
	new->z = 0;
	new->color = 0x00FFFFFF;
	return (ft_lstnew(new, sizeof(t_node)));
}

void		add_list(t_list **lista, char *str)
{
	if (*lista)
		ft_lst_addback(lista, create_node(str));
	else
		*lista = create_node(str);
}
*/


/* LOL i modified this because i realize how to align i'm less retard
void	set_xy(t_coord **coord, t_total	*envi)
{
	//700 *  600
	float		gapx;
	float		gapy;
	int			x;
	int			y;
	int			y2;
	t_coord		*coordx;

	y = envi->colum;
	gapx = 700 / (envi->colum - 1);
	gapy = 600 / (envi->row - 1);
	y2 = 0;
	while (--y >= 0)
	{
		x = -1;
		while (++x < envi->colum)
			{
				coordx = &(coord[y][x]);
				coordx->x = ((envi->pushx) + (gapx * x));
				coordx->y = ((envi->pushy) - (gapy * y2));
				if(coordx->z == 0)
					coordx->z = 1;
			}
		y2++;
	}
}
*/

void	set_xy(t_coord **coord, t_total	*envi)
{
	//700 *  600
	float		gapx;
	float		gapy;
	int			x;
	int			y;
	int			y2;
	t_coord		*coordx;
	int		midx;
	int		midy;

	gapx = 700 / (envi->colum - 1);
	gapy = 600 / (envi->row - 1);
	midy = 0 - (envi->row / 2);
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		midx = 0 - (envi->colum / 2);
		while (++x < envi->colum)
			{
				coordx = &(coord[y][x]);
				coordx->x = (gapx * midx);
				coordx->y = (gapy * midy);
				if(coordx->z == 0)
					coordx->z = 1;
				midx++;
			}
		midy++;
	}
}

void		draw_row(t_coord **cord, t_total *envi)
{
	t_coord		*holder;
	t_coord		*holdernext;
	int			x;
	int			y;
	
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum - 1)
		{
			holder = &(cord[y][x]);
			holdernext = &(cord[y][x + 1]);
			draw_line_ult(holder->x, holder->y, holdernext->x, \
			holdernext->y, envi);
		}
	}
}

void		draw_colum(t_coord **cord, t_total *envi)
{
	t_coord		*holder;
	t_coord		*holdernext;
	int			x;
	int			y;
	
	y = -1;
	while (++y < envi->row - 1)
	{
		x = -1;
		while (++x < envi->colum)
		{
			holder = &(cord[y][x]);
			holdernext = &(cord[y + 1][x]);
			draw_line_ult(holder->x, holder->y, holdernext->x, \
			holdernext->y, envi);
		}
	}
}

// TRY ROTATION 1
void		rotate_xy(t_coord **coord, t_coord **dest, t_total *envi)
{
	t_coord	*hold;
	t_coord	*holdest;
	int		x;
	int		y;

	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			holdest = &(dest[y][x]);
			holdest->x = (hold->x * cos(envi->theta)) + (hold->y * sin(envi->theta));
			holdest->y = (hold->x * -(sin(envi->theta))) + (hold->y * cos(envi->theta));
			holdest->z = hold->z * 1;
		}
	}
}

void		rotate_yz(t_coord **coord, t_coord **dest, t_total *envi)
{
	t_coord	*set;
	t_coord	*setdest;
	int		x;
	int		y;

	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			set = &(coord[y][x]);
			setdest = &(dest[y][x]);
			setdest->y = (set->y * cos(envi->phi)) + (set->z * -(sin(envi->phi)));
			setdest->z = (set->y * sin(envi->phi)) + (set->z * cos(envi->phi));
			setdest->x = set->x * 1;
		}
	}
}

void		rotate_xz(t_coord **coord, t_coord **dest, t_total *envi)
{
	t_coord	*hold;
	t_coord *holdest;
	int		x;
	int		y;

	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			holdest = &(dest[y][x]);
			holdest->x = (hold->x * cos(envi->psi)) + (hold->z * sin(envi->psi));
			holdest->z = (hold->x * -(sin(envi->psi))) + (hold->z * cos(envi->psi));
			holdest->y = hold->y * 1;
		}
	}
}

void		perspective_tra(t_coord **coord, t_total *envi)
{
	t_coord	*dest;
	int		x;
	int		y;

	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			dest = &(coord[y][x]);
 //           dest->x = (FOCAL * dest->x) / dest->z + (WINW / 2);
 //           dest->x = (FOCAL * dest->x) / dest->z + (WINW / 2);
            dest->y = (FOCAL * dest->y) / dest->z + 0;
            dest->y = (FOCAL * dest->y) / dest->z + 0;
		}
	}

}
////////////////////////////////////////////////

float		getting_min(t_coord **coord, t_total *envi, char letra)
{
	t_coord	*hold;
	int		x;
	int		y;
	float	minx;
	float	miny;

	minx = coord[0][0].x;
	miny = coord[0][0].y;
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			if (hold->x < minx)
				minx = hold->x;
			if (hold->y < miny)
				miny = hold->y;
		}
	}
	if (letra == 'x')
		return (minx);
	else
		return (miny);
}

float		getting_max(t_coord **coord, t_total *envi, char letra)
{
	t_coord	*hold;
	int		x;
	int		y;
	float	maxx;
	float	maxy;

	maxx = coord[0][0].x;
	maxy = coord[0][0].y;
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			if (hold->x > maxx)
				maxx = hold->x;
			if (hold->y > maxy)
				maxy = hold->y;
		}
	}
	if (letra == 'x')
		return (maxx);
	else
		return (maxy);
}

void		align(t_coord **coord, t_total *envi)
{
	t_coord	*hold;
	int		x;
	int 	y;
	float	minx;
	float	miny;
	float	maxx;
	float	maxy;


	minx = getting_min(coord, envi, 'x');
	miny = getting_min(coord, envi, 'y');
	maxx = getting_max(coord, envi, 'x');
	maxy = getting_max(coord, envi, 'y');
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
//			hold->x += ((WINW - (maxx - minx)) / 2);
//			hold->y += ((WINH - (maxy - miny)) / 2);
			hold->x += (WINW / 2);
			hold->y += (WINH / 2);
			hold->z = hold->z * 1;
		}
	}
}
void		man_translation(t_coord **coord, t_total *envi)
{
	t_coord *hold;
	int y;
	int x;
	
	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			hold->x += envi->trax;
			hold->y += envi->tray;
			hold->z += envi->traz;
		}
	}
}