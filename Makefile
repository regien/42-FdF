# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/25 00:45:02 by regien            #+#    #+#              #
#    Updated: 2017/12/29 00:07:08 by regien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf_test
LIB = libft/

CFlAGS = -Wall -Wextra -Werror
LFLAGS = -L/usr/include/../lib -lXext -lX11 -lm
CC = gcc

#When compiling. you need to add your .a lib
CFILES = $(LIB)/libft.a \
	main.c


$(NAME):
	gcc main.c minilibx/libmlx_Linux.a -L/usr/include/../lib -lXext -lX11 -lm
