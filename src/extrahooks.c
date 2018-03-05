/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrahooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 21:58:04 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 06:18:15 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>

void		free_everything(t_total *envi)
{
	int	x;
	int	y;

	(void)x;
	y = -1;
	while(++y < envi->row)
	{
//		x = -1;
//		while(++x < envi->colum)
			free(envi->coord[y]);
	}
//	free(*(envi->coord));
	y = -1;
	while (++y < envi->row)
		free(envi->dest[y]);
//	free(*(envi->dest));
	free(envi->pressed);
	free(envi->setting);
	free(envi->colors);
	free(envi->pix);
	free(envi->img);
	//free(envi->mlx);
//	free(envi->win);
	free(envi);
}

void		shuffle_colors(t_total *envi)
{
	srand(time(NULL));
	envi->which = ((rand() % 100) + 1);
}
