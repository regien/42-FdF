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

// contador de cuanto es la matriz
int			count_splt(char **str)
{
		int	i;

		i = 0;
		while (str[i] != NULL)
			i++;
		return (i);
}

// NO ENDING | suppose to have a list as an argument to storage the linked list
int		splitter(char *str, t_list **list, t_matrx *matrix)
{
	static char	**temp;
	int					column;
	int					i;

	i = -1;
	printf("matrix = %i\n", count_splt(ft_strsplit(str, ' ')));
	temp = ft_strsplit(str, ' ');
	// tamaño calculado
	if (matrix->row != 0)
	{
		if (matrix->row != count_splt(temp))
			general_exit(-1, "invalid map\n");
	}
	else
		matrix->row = count_splt(temp);
	// calcular de que tamano es el doble pointer
	while (++i < matrix->row)
		add_list(list, temp[i]);
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
	//	if ((line[i] >= 'g' && line[i] <= 'z') || \
	//	(line[i] >= 'G' && line[i] <= 'Z'))
	//		return (0);
	}
	return (1);
}

// suposse to have a linked as an argument / storage purpose
int			parser_file(char *str, t_list **list, t_matrx **matrix)
{
	int		fd;
	char	*line;
	t_matrx	*holder;
//	static t_matrx		matrix;

	*matrix = ft_memalloc(sizeof(t_matrx));
	holder = *matrix;
	// HERE NULLIFYING THE LIST <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	*list = NULL;
//	matrix = 0;

	if ((fd = open(str, O_RDONLY)) < 0)
			general_exit(-1, "invalid file\n");
	// change to if so only reads once / testing only
	printf("PENDEJADA\n");
	if ((get_next_line(fd, &line)) > 0)
	{
		// row ++ <- para determinar la distancia entra las pendejadas
		(holder->column)++;
		printf("matrix->column = %d\n", holder->column);
		if (parser_line(line) == 1 && splitter(line, list, holder) == 1)
		{
			printf("wowowowowbypass\n");
			// returning just for testing only
			return (1);
			// funcion para agregar a lista y setear matrix number
		}
		else
			return (0);
	}
	close(fd);
	return (0);
}