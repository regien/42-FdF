/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrahooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 21:58:04 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/04 21:58:30 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_extras(int keycode, t_total *envi)
{
	// zoom in
	if (keycode == KEY_R)
		init_fdf(envi);
	draw_everything(envi);
	return (0);
}
