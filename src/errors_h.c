/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:05:33 by regien            #+#    #+#             */
/*   Updated: 2018/03/05 01:30:42 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Print General usage.
*/

void	fillit_print_usage(char *arg)
{
	ft_putstr("usage ");
	ft_putstr(arg);
	ft_putstr(" valid_file.fdf\n");
	exit(-1);
}

/*
** General Exit.
*/

void	general_exit(int error_code, char *mensaje)
{
	if (error_code < 0)
		ft_putstr(mensaje);
	exit(error_code);
}

// IMPLIMENTING FREE EVE HERE

int		destroy_exit(int error_code, char *mensaje, t_total *envi)
{
	mlx_destroy_window(envi->mlx, envi->win);
	if (error_code < 0)
		ft_putstr(mensaje);
	free_everything(envi);
	while (1)
	{
		;
	}
	exit(error_code);
	return (0);
}
