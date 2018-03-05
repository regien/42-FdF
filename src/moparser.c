/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moparser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:40:06 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 00:15:35 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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

int			count_splt(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

// NO ENDING | suppose to have a list as an argument to storage the linked list
int		splitter(char *str, t_total *envi)
{
	static char	**temp;
	int					i;

	i = -1;
	printf("matrix = %i\n", count_splt(ft_strsplit(str, ' ')));
	temp = ft_strsplit(str, ' ');
	// tamaño calculado
	if (envi->colum != 0)
	{
		if (envi->colum != count_splt(temp))
			general_exit(-1, "invalid map\n");
	}
	else
		envi->colum = count_splt(temp);
	i = -1;
	while (++i < envi->colum)
		free(temp[i]);
	// calcular de que tamano es el doble pointer
	//	while (++i < envi->row)
	//		add_list(list, temp[i]);
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
		if ((line[i] >= 'g' && line[i] <= 'z') || \
				(line[i] >= 'G' && line[i] <= 'Z'))
			return (0);
	}
	return (1);
}

int			parser_file(char *str, t_total *envi)
{
	int		fd;
	static char	*line;
	//	t_total		*envi;

	//	envi = *envire;
	envi->row = 0;
	envi->colum = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		general_exit(-1, "invalid file\n");
	// change to if so only reads once / testing only
	printf("PENDEJADA\n");
	while ((get_next_line(fd, &line) > 0))
	{
		(envi->row)++;
		printf("matrix->row = %d\n", envi->row);
		if (parser_line(line) == 0 || splitter(line, envi) == 0)
		{
			//	printf("falla, falla en el parser dentro\n");
			return (0);
			// returning just for testing only
			// funcion para agregar a lista y setear matrix number
		}
		free(line);
	}
	close(fd);
	return (1);
}
