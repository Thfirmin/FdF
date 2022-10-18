# **************************************************************************** #
                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 06:08:08 by thfirmin          #+#    #+#              #
#    Updated: 2022/09/25 05:48:10 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAME 

NAME	= fdf

LIBFT	= $(addprefix $(LIBFT_PATH), $(LIBFT_SRC))

GNL		= $(addprefix $(GNL_PATH), $(GNL_SRC))

MLX		= $(addprefix $(MLX_PATH), $(MLX_SRC))

FDF_NAMES	= $(LIBFT) \
			  $(GNL)   \
			  $(MLX)   \
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

RM			= rm -rf
CC			= cc

CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

INCLUDE		= -I $(LIBFT_PATH) -I $(GNL_PATH) -I $(MLX_PATH)

LIBFT_PATH	= libft/
GNL_PATH	= get_next_line/
MLX_PATH	= mlx/

#MAKEFLAGS	+= --silent
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

SRCS		= fdf.c               \
			  fdf_error_handler.c \
			  fdf_map_analysis.c  \
			  fdf_utils.c         \
			  fdf_pnt_utils.c     \
			  fdf_window_info.c   \

OBJS		= $(SRCS:.c=.o)

LIBFT_SRC	= libft.a

GNL_SRC		= getnextline.a

MLX_SRC		= libmlx.a
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
	$(CC) -g $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o) 

all:		$(LIBFT) $(GNL) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(GNL):
	make -C $(GNL_PATH)

$(MLX):
	make -C $(MLX_PATH)

$(NAME):	$(OBJS)
	$(CC) -g $(CFLAGS) $(MLXFLAGS) $(INCLUDE) $(OBJS) $(FDF_NAMES) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(GNL_PATH) clean
	make -C $(MLX_PATH) clean

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(GNL_PATH) fclean
	make -C $(MLX_PATH) clean

re:			fclean all

.PHONY:		all clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
