/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrahooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 21:58:04 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 06:35:56 by gmalpart         ###   ########.fr       */
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
	while (++y < envi->row)
		free(envi->coord[y]);
	y = -1;
	while (++y < envi->row)
		free(envi->dest[y]);
	free(envi->pressed);
	free(envi->setting);
	free(envi->colors);
	free(envi->pix);
	free(envi->img);
	free(envi);
}

void		shuffle_colors(t_total *envi)
{
	srand(time(NULL));
	envi->which = ((rand() % 100) + 1);
}
