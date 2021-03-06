/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moparser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:40:06 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/05 06:33:30 by gmalpart         ###   ########.fr       */
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

int			splitter(char *str, t_total *envi)
{
	static char	**temp;
	int			i;

	i = -1;
	temp = ft_strsplit(str, ' ');
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
	return (1);
}

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
	int			fd;
	static char	*line;

	envi->row = 0;
	envi->colum = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		general_exit(-1, "invalid file\n");
	while ((get_next_line(fd, &line) > 0))
	{
		(envi->row)++;
		if (parser_line(line) == 0 || splitter(line, envi) == 0)
		{
			return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}
