/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:40 by regien            #+#    #+#             */
/*   Updated: 2018/01/10 05:38:36 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
	vas  a usar estructuras como negro
*/

// cambiar escapes de fillit
// MENSAJES PERSONALIZADOS - CODIGO DE ERROR
// 
int			my_key_function(int keycode, void *param, void *mlx, void *win)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		general_exit(ESCAPE, "gracias por usar esta pendejada\n");
	return (0);
}


/*
int			my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
//	mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
	return (0);
}
*/


// for now only works with parsing the name, now we are opening the file
// and build a valid matrix and start creating the structure
// FIRST PART PARSER 
int			parser_argv(char *str)
{
	int		i;
	int		dots;

	dots = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_strlen(str) == 4)
			return (0);
		if (str[i] == '.')
			dots++;
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || dots >= 2)
			return (0);
	}
	if ((ft_strequ((ft_strstr(str, ".fdf")), ".fdf")) == 0)
		return (0);
	return (1);
}


/*
t_list		*bitch_me_a_list(t_list **list, char **pendejada)
{
	t_list	*iter;
	t_node	*iterdata;

	if ()
}
*/

// take care of is_valid_hex
int			parser_line(char *str)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			if (line[i + 1] == ' ' || line[i + 1] == '\0')
				return (0);
		if ()
	}
}

int			parser_file(char *str, **list)
{
	int		fd;
	char	*line;
	int		i;
	int		matrix;

	matrix = 0;
	i = -1;
	fd = open(str, O_RDONLY);
	while((get_next_line(fd, &line)) > 0)
	{
		if (parser_line(line) == 1)
		{
			// funcion para agregar a lista y setear matrix number
		}
		else
			return (0);
	}
	
}


// los mensajes dentro de la proteccion no son necesarios, puedes sacarlos
// con "general_exit"
int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		*list;

	list = NULL;
	if (argc != 2)
	{
		fillit_print_usage(argv[0]);
		return (0);
	}
	if (parser_argv(argv[1]) == 0 && parser_file(argv[1], &list) == 0)
	{
		general_exit(ESCAPE, "invalid file or map\n");
		return (0);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "testing my shit");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x< 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, my_key_function, mlx);
	straight_line(200, 0,0, mlx, win);
	straight_line_y(200, 200, 0, mlx, win);
	bitch_line(300, 500, 600, 700, mlx, win);
//	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	mlx_loop(mlx);
}
