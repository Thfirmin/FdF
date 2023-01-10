# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 20:10:53 by marvin            #+#    #+#              #
#    Updated: 2023/01/10 03:20:40 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAME

NAME		= fdf

OS			= $(shell uname)

FT			= $(PTH_FT)$(SRC_FT).a

GNL			= $(PTH_GNL)$(SRC_GNL).a

MLX			= $(PTH_MLX)$(SRC_MLX).a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATH

PTH_TOOL	= tools/
PTH_FT		= $(addprefix $(PTH_TOOL),libft/)
PTH_GNL		= $(addprefix $(PTH_TOOL),get_next_line/)
PTH_MLX		= $(addprefix $(PTH_TOOL),mlx/)

PTH_SRCS	= srcs/
PTH_MDTRY	= $(addprefix $(PTH_SRCS),mandatory/)
PTH_MAP		= $(addprefix $(PTH_SRCS),map/)
PTH_DATA	= $(addprefix $(PTH_SRCS),data/)
PTH_UTILS	= $(addprefix $(PTH_SRCS),utils/)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES

SRC_FT	= libft

SRC_GNL	= libgnl

SRC_MLX	= libmlx

SRC_MDTRY	= fdf_main.c \
			  fdf.c \
			  fdf_sethook.c \
			  fdf_printfdf.c

SRC_MAP		= fdf_is_validmap.c \
			  fdf_initmap.c

SRC_DATA	= fdf_fdfdata.c \
			  fdf_pntdata.c

SRC_UTILS	= fdf_closefile.c \
			  fdf_exit.c \
			  fdf_nbr_utils.c \
			  fdf_putpxl.c \
			  fdf_keyhandler.c \
			  fdf_putline.c \
			  fdf_clr_pass.c

SRCS	= $(addprefix $(PTH_MDTRY),$(SRC_MDTRY)) \
		  $(addprefix $(PTH_MAP),$(SRC_MAP)) \
		  $(addprefix $(PTH_DATA),$(SRC_DATA)) \
		  $(addprefix $(PTH_UTILS),$(SRC_UTILS))

OBJS	= $(SRCS:.c=.o)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

MAKEFLAGS	+= --no-print-directory
CFLAGS		= -Wall -Wextra -Werror
ifeq ($(OS),Linux)
MLXFLAGS	= -lXext -lX11 -lz
DEF			= -D ISLINUX=1
else ifeq ($(OS),Darwin)
MLXFLAGS	= -framework OpenGL -framework AppKit
DEF			= -D ISLINUX=0
endif
INCLUDE		= -Iincludes -I$(PTH_FT) -I$(PTH_GNL) -I$(PTH_MLX)
LINKER		= -L$(PTH_FT) -l$(subst lib,,$(SRC_FT)) \
			  -L$(PTH_GNL) -l$(subst lib,,$(SRC_GNL)) \
			  -L$(PTH_MLX) -l$(subst lib,,$(SRC_MLX)) \
			  -lm
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
	$(CC) $(CFLAGS) $(DEF) -O3 $(INCLUDE) -c $< -o $(<:.c=.o)

all:	update_tools $(NAME)

debug: CFLAGS += -g

debug: update_dbgtools $(NAME)

test:	update_dbgtools
	$(CC) $(CFLAGS) -g -O3 $(INCLUDE) -c main.c -o main.o
	$(CC) $(CFLAGS) -g main.o $(LINKER) $(MLXFLAGS) -o test
	./test

update_tools: $(PTH_MLX)
	make -C $(PTH_FT)
	make -C $(PTH_GNL)
	make -C $(PTH_MLX)

update_dbgtools: $(PTH_MLX)
	make -C $(PTH_FT) debug
	make -C $(PTH_GNL) debug
	make -C $(PTH_MLX) debug

$(PTH_MLX):
	tar -xf tools/minilibx-$(OS).tar -C tools/

$(NAME):	$(FT) $(GNL) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINKER) $(MLXFLAGS) -o $(NAME)

mclean:
ifneq (,$(shell ls $(OBJS) 2> /dev/null))
	rm -rf $(OBJS)
endif

tclean:
	make -C $(PTH_FT) clean
	make -C $(PTH_GNL) clean
ifneq (,$(shell ls $(PTH_MLX) 2> /dev/null))
	make -C $(PTH_MLX) clean
endif

clean: mclean tclean

fclean: clean
	make -C $(PTH_FT) fclean
	make -C $(PTH_GNL) fclean
ifneq (,$(shell ls $(PTH_MLX) 2> /dev/null))
	rm -rf $(PTH_MLX)
endif
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	rm -rf $(NAME)
endif

re:	fclean all

.PHONY: all re mclean tclean clean fclean update_tools debug
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
