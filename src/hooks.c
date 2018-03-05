/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 00:40:29 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 06:17:57 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			expose_hook(t_total *envi)
{
	draw_everything(envi);
	return (0);
}

int			mouse_hook(int keycode, int x, int y, t_total *envi)
{
	(void)x;
	(void)y;
	if (keycode == 5)
	{
		envi->scalex = envi->scalex * 1.1;
		envi->scaley = envi->scaley * 1.1;
		envi->scalez = envi->scalez * 1.1;
	}
	if (keycode == 4)
	{
		envi->scalex = envi->scalex / 1.2;
		envi->scaley = envi->scaley / 1.2;
		envi->scalez = envi->scalez / 1.2;
	}
	if (keycode == 2)
		init_fdf(envi);
	if (keycode == 1)
		shuffle_colors(envi);
	draw_everything(envi);
	return (0);
}

int			my_key_function(t_total *envi)
{
	if (envi->pressed->d)
		envi->theta += 00.05;
	if (envi->pressed->a)
		envi->theta -= 00.05;
	if (envi->pressed->w)
		envi->phi += 00.05;
	if (envi->pressed->s)
		envi->phi -= 00.05;
	if (envi->pressed->e)
		envi->psi += 00.05;
	if (envi->pressed->q)
		envi->psi -= 00.05;
	if (envi->pressed->right)
		envi->trax += 1;
	if (envi->pressed->left)
		envi->trax -= 1;
	if (envi->pressed->down)
		envi->tray += 1;
	if (envi->pressed->up)
		envi->tray -= 1;
	draw_everything(envi);
	return (0);
}

int			key_pressed(int keycode, t_total *envi)
{
	if (keycode == KEY_ESC)
		destroy_exit(ESCAPE, "ty :D\n", envi);
	if (keycode == KEY_W)
		envi->pressed->w = 1;
	else if (keycode == KEY_S)
		envi->pressed->s = 1;
	else if (keycode == KEY_S)
		envi->pressed->s = 1;
	else if (keycode == KEY_A)
		envi->pressed->a = 1;
	else if (keycode == KEY_D)
		envi->pressed->d = 1;
	else if (keycode == KEY_E)
		envi->pressed->e = 1;
	else if (keycode == KEY_Q)
		envi->pressed->q = 1;
	else if (keycode == KEY_RIGHT)
		envi->pressed->right = 1;
	else if (keycode == KEY_LEFT)
		envi->pressed->left = 1;
	else if (keycode == KEY_UP)
		envi->pressed->up = 1;
	else if (keycode == KEY_DOWN)
		envi->pressed->down = 1;
	return (0);
}

int			key_release(int keycode, t_total *envi)
{
	if (keycode == KEY_W)
		envi->pressed->w = 0;
	else if (keycode == KEY_S)
		envi->pressed->s = 0;
	else if (keycode == KEY_A)
		envi->pressed->a = 0;
	else if (keycode == KEY_D)
		envi->pressed->d = 0;
	else if (keycode == KEY_E)
		envi->pressed->e = 0;
	else if (keycode == KEY_Q)
		envi->pressed->q = 0;
	else if (keycode == KEY_RIGHT)
		envi->pressed->right = 0;
	else if (keycode == KEY_LEFT)
		envi->pressed->left = 0;
	else if (keycode == KEY_UP)
		envi->pressed->up = 0;
	else if (keycode == KEY_DOWN)
		envi->pressed->down = 0;
	return (0);
}
