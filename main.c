/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 19:13:40 by regien            #+#    #+#             */
/*   Updated: 2018/01/12 12:24:52 by gmalpart         ###   ########.fr       */
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
int			my_key_function(int keycode, t_env *envi)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		destroy_exit(ESCAPE, "gracias por usar esta pendejada\n", envi->mlx, envi->win);
	return (0);
}

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

///		HELPER LINKED LIST FUNCTION

/*
// NOT OPTIMAZED
t_list		*create_node(char *str)
{
	t_new		*new;

	if(!(new = ft_memalloc(sizeof(t_hola))))
		return (0);
	new->dato = dato;
	new->heap = ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
	ft_strcpy(new->heap, str);
	return (ft_lstnew(new, sizeof(t_hola)));
}


// NOT OPTIMAZED || have to be lst_add_back
void		add_list(t_list **lista, int dato, char *str)
{
	if (*lista)
		ft_lst_addback(lista, create_node(dato, str));
	else
		*lista = create_node(dato, str);
}
*/

// NO ENDING | suppose to have a list as an argument to storage the linked list
int		splitter(char *str)
{
	char	**temp;

	temp = ft_strsplit(str, ' ');
	// calcular de que tamano es el doble pointer
	return (1);
}


// take care of is_valid_hex || NOT HERE, IN THE SPLIT
int			parser_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (i == 0 && line[i] == ' ')
			return (0);
		if (line[i] == '\t')
			return (0);
		if (line[i] == ' ')
			if (line[i + 1] == ' ' || line[i + 1] == '\0')
				return (0);
	}
	return (1);
}

// suposse to have a linked as an argument / storage purpose
int			parser_file(char *str, t_node **list)
{
	int		fd;
	char	*line;
	int		i;
	int		matrix;

	// HERE NULLIFYING THE LIST <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	*list = NULL;
	matrix = 0;
	i = -1;
	fd = open(str, O_RDONLY);
	// change to if so only reads once / testing only
	printf("PENDEJADA\n");
	if ((get_next_line(fd, &line)) > 0)
	{
		if (parser_line(line) == 1 && splitter(line) == 1)
		{
			printf("wowowowowbypass\n");
			// returning just for testing only
			return (1);
			// funcion para agregar a lista y setear matrix number
		}
		else
			return (0);
	}
	return (0);
}

void			draw_rectang(int x0, int y0, int x1, int y1, t_env *env)
{
	int			temp;

	temp = x0;
	while (y0 < y1)
	{
		x0 = temp;
		while (x0 < x1)
		{
			mlx_pixel_put(env->mlx, env->win, x0, y0, 0x00FFFFFF);
			x0++;
		}
		y0++;
	}
}

int				main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_node		*list;
	t_env		*envi;

// parser
/*
	if (argc != 2)
	{
		fillit_print_usage(argv[0]);
		return (0);
	}
	if (parser_argv(argv[1]) == 0 || parser_file(argv[1], &list) == 0)
	{
		general_exit(ESCAPE, "invalid file or map\n");
		return (0);
	}
*/
	envi = ft_memalloc(sizeof(t_env));
	envi->mlx = mlx_init();
	envi->win = mlx_new_window(envi->mlx, 800, 800, "testing my shit");
	y = 50;
/*
	while (y < 150)
	{
		x = 50;
		while (x< 150)
		{
			mlx_pixel_put(envi->mlx, envi->win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	*/
	draw_rectang(50, 50, 150, 150, envi);
//	mlx_key_hook(win, my_key_function, mlx);
	mlx_key_hook(envi->win, my_key_function, envi);
	straight_line(200, 0,0, envi->mlx, envi->win);
	straight_line_y(200, 200, 0, envi->mlx, envi->win);
	bitch_line(300, 500, 600, 700, envi->mlx, envi->win);
//	mlx_clear_window(mlx, win);
//	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	mlx_loop(envi->mlx);
}
