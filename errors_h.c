/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:05:33 by regien            #+#    #+#             */
/*   Updated: 2018/01/09 23:39:45 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos_elcapitan/mlx.h"

/*
** Print General usage.
*/

void		fillit_print_usage(char *arg)
{
		ft_putstr("usage ");
			ft_putstr(arg);
				ft_putstr(" valid_file.fdf\n");
}

/*
** General Exit.
*/

void		general_exit(int error_code, char *mensaje)
{
	if (error_code < 0)
		ft_putstr(mensaje);
	exit(error_code);
}
