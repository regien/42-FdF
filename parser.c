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

void		rotate_xy(t_coord **coord, t_total *envi)
{
	t_coord	*hold;
	int		x;
	int		y;

	y = -1;
	while (++y < envi->row)
	{
		x = -1;
		while (++x < envi->colum)
		{
			hold = &(coord[y][x]);
			hold->x = (hold->x * cos(envi->theta)) + (hold->y * sin(envi->theta));
			hold->y = (hold->x * -(sin(envi->theta))) + (hold->y * cos(envi->theta));
			hold->z = hold->z * 1;
		}
	}
}

void		align()

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