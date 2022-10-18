# **************************************************************************** #
                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                          :+:     :+:             #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 06:08:08 by thfirmin          #+#    #+#              #
#    Updated: 2022/09/21 04:21:39 by Thinotsuki   ###     ###.br               #
#                                                                              #
# **************************************************************************** #

# +>                                     NAME 

NAME	= fdf

LIBFT	= $(LIBFT_PATH)$(LIBFT_SRC)

MLX		= $(MLX_PATH)libmlx.a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

RM			= rm -rf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit
INCLUDE		= -I $(LIBFT_PATH)includes -I $(MLX_PATH)
#MAKEFLAGS	+= --silent
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

SRCS	= fdf.c \
		  fdf_paint_tools.c

OBJS	= $(SRCS:.c=.o)

LIBFT_SRC	= libft.a

LIBFT_PATH	= libft/

MLX_PATH	= mlx/
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CODES 

BLANK			= \e[m
RED				= \e[38;5;9m
YELLOW			= \e[38;5;11m
GREEN			= \e[38;5;2m
BLUE			= \e[38;5;6m
PURPLE			= \e[38;5;5m
PINK			= \e[38;5;13m
WHITE			= \e[38;5;15m

STRONG			= \e[1m
SHADOW			= \e[2m
ITALIC			= \e[3m
UNDLINE			= \e[4m
UPPLINE			= \e[53m
DUNDLINE		= \e[21m
CENSORED		= \e[9m
UPALIGN			= \e[73m
DWALIGN			= \e[74m
FULLER			= \e[7m
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     RULES 


.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o) 

all:		$(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(MLX):
	make -C $(MLX_PATH)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean:		clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
