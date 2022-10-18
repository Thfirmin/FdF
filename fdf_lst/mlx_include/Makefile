# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 08:19:13 by thfirmin          #+#    #+#              #
#    Updated: 2022/10/17 22:07:15 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES 

NAME	= fdf

LIBFT	= $(addprefix $(LIBFT_PATH),$(LIBFT_SRC))

MLX		= $(addprefix $(MLX_PATH),$(MLX_SRC))

GNL		= $(addprefix $(GNL_PATH),$(GNL_SRC))

FDF_LIBS	= $(LIBFT) \
			  $(GNL) \
			  $(MLX)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

LIBFT_SRC	= libft.a

MLX_SRC		= libmlx.a

GNL_SRC		= libgnl.a

SRCS	= fdf.c \
		  fdf_error_handler.c \
		  fdf_read_file.c \
		  fdf_conf_utils.c \
		  fdf_graph_utils.c \
		  fdf_point_utils.c

OBJS	= $(SRCS:.c=.o)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

LIBFT_PATH	= libft/
MLX_PATH	= mlx/
GNL_PATH	= get_next_line/

RM	= rm -rf

LD	= ld
CC = cc

CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit
INCLUDE		= -I $(LIBFT_PATH) -I $(GNL_PATH) -I $(MLX_PATH)
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

all:		$(LIBFT) $(GNL) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(GNL):
	make -C $(GNL_PATH)

$(MLX):
	make -C $(MLX_PATH)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(FDF_LIBS) -o $(NAME)


clean:
	$(RM) $(OBJS)
	make -C $(MLX_PATH) clean
	make -C $(GNL_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean:
	$(RM) $(OBJS) $(NAME)
	make -C $(MLX_PATH) clean
	make -C $(GNL_PATH) fclean
	make -C $(LIBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
