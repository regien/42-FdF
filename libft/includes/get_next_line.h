/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:48:17 by gmalpart          #+#    #+#             */
/*   Updated: 2017/12/28 17:31:48 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"
# include <fcntl.h>

/*
**		CUSTOM LINKED LIST FOR THE PROJECT
*/

typedef	struct			s_fdstore
{
	int					fd;
	char				*str;
	struct s_fdstore	*next;
}						t_fdstore;

int						get_next_line(const int fd, char **line);
#endif
