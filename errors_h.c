/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:05:33 by regien            #+#    #+#             */
/*   Updated: 2018/01/07 12:53:02 by regien           ###   ########.fr       */
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

void		fillit_print_error(int error_code)
{
		if (error_code < 0)
					ft_putstr("error\n");
			exit(error_code);
}
