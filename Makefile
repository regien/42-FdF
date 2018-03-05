# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/25 00:45:02 by regien            #+#    #+#              #
#    Updated: 2018/03/05 00:12:08 by gmalpart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = fdf_test
LIB = libft/
MLX = minilibx/
OSXMLX = minilibx_macos_sierra/
CFlAGS = -Wall -Wextra -Werror
CC = gcc

# linux flags - position of the includes mayvary
# library position may vary per distribution
LFLAGS = -L/usr/include/../lib -lXext -lX11 -lm
# OSX flags- frameworks
MFLAGS = -framework OpenGL -framework AppKit

# When compiling. you need to add your .a lib
# the libraries should be at the end always
# order is important in Linux
CFILES =	errors_h.c \
			drawing.c \
			main.c \
			parser.c \
			matrices.c \
			hooks.c \
			extrahooks.c  \
			mathmat.c \
			projections.c \
			render.c \
			initmat.c \
			moparser.c \
			extraparser.c

HEADERS = -I includes -I libft/includes -I minilibx_macos_elcapitan

CSTFILES = $(addprefix src/, $(CFILES))

LILIB =		$(LIB)libft.a \
			$(MLX)libmlx_Linux.a

OSXLIB =	$(LIB)libft.a \
			$(OSXMLX)libmlx.a

# These options are here in case the lib needs to be recompiled.
# LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

# These options are here in case the minilibx needs to be recompiled.
# LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
MLXM = $(MAKE) $(MLX) re
MLXC = $(MAKE) $(MLX) clean

# These options are here in case the minilibx needs to be recompiled.
# LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
OSXMLXM = $(MAKE) $(OSXMLX) re
OSXMLXC = $(MAKE) $(OSXMLX) clean

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

# It will compile by default for Osx(sierra) with his specific minilibx
$(NAME):
	@$(LIBM)
	@$(OSXMLXM)
	@$(CC) $(CFILES) $(OSXLIB) $(MFLAGS) -o $(NAME)

# not compiling with flags yet becuase of linux errors
# linux erros != mac errors
linux:
	@$(LIBM)
	@$(MLXM)
	@$(CC) $(CFILES) $(LILIB) $(LFLAGS) -o $(NAME)
#gcc main.c minilibx/libmlx_Linux.a -L/usr/include/../lib -lXext -lX11 -lm

# this is for compiling fast without spamming your terminal / lINUX
compli:
	$(CC) -g $(CFILES) $(LILIB) $(LFLAGS) -o $(NAME)

# fast compile for macosx version / MACOSX
comp:
	$(CC) -g $(HEADERS) $(CSTFILES) $(OSXLIB) -Iminilibx_macos_sierra $(MFLAGS) -o $(NAME)

norm:
	norminette $(CSTFILES) Makefile includes/fdf.h

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS)

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
