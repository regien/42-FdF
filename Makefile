# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/25 00:45:02 by regien            #+#    #+#              #
#    Updated: 2017/12/31 18:02:03 by regien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = fdf_test
LIB = libft/
MLX = minilibx/
CFlAGS = -Wall -Wextra -Werror

#linux flags - position of the includes mayvary
LFLAGS = -L/usr/include/../lib -lXext -lX11 -lm
CC = gcc

# When compiling. you need to add your .a lib
# the libraries should be at the end always
# order is important in Linux
CFILES = main.c \
	$(LIB)libft.a \
	$(MLX)libmlx_Linux.a

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

#These options are here in case the minilibx needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
MLXM = $(MAKE) $(MLX) re
MLXC = $(MAKE) $(MLX) clean

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

#not compiling with flags yet becuase of linux errors
#linux erros != mac errors
$(NAME):
	@$(LIBM)
	@$(MLXM)
	@$(CC) $(CFILES) $(LFLAGS) -o $(NAME)
#gcc main.c minilibx/libmlx_Linux.a -L/usr/include/../lib -lXext -lX11 -lm

# this is for compiling fast without spamming your terminal
comp:
	@$(CC) $(CFILES) $(LFLAGS) -o $(NAME)

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS)

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
