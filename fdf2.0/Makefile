# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 20:10:53 by marvin            #+#    #+#              #
#    Updated: 2022/12/29 17:08:12 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAME 

NAME		= fdf

UNAME		= $(shell uname)

TOOLS		= $(LIBFT_PATH) \
			  $(GNL_PATH) \
			  $(MLX_PATH)

LIBS		= $(LIBFT_PATH)$(LIBFT_SRC).a \
			  $(GNL_PATH)$(GNL_SRC).a \
#			  $(MLX_PATH)$(MLX_SRC).a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATH

TOOL_PATH	= tools/
LIBFT_PATH	= $(addprefix $(TOOL_PATH),libft/)
GNL_PATH	= $(addprefix $(TOOL_PATH),get_next_line/)
MLX_PATH	= $(addprefix $(TOOL_PATH),mlx/)

SRCS_PATH	= srcs/
MDTRY_PATH	= $(addprefix $(SRCS_PATH),mandatory/)
UTILS_PATH	= $(addprefix $(SRCS_PATH),utils/)
MAP_PATH	= $(addprefix $(SRCS_PATH),map/)
DATA_PATH	= $(addprefix $(SRCS_PATH),data/)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES

MDTRY_SRCS	= fdf_main.c \
			  fdf_init_setting.c

MAP_SRCS	= fdf_initmap.c \
			  fdf_is_validmap.c

DATA_SRCS	= fdf_pntnew.c \
			  fdf_pntclear.c \
			  fdf_pntadd_back.c \
			  fdf_pntlast.c \
			  fdf_fdfclear.c

UTILS_SRCS	= fdf_error.c \
			  fdf_hex_utils.c \
			  fdf_isnumber.c \
			  fdf_closefile.c

SRCS		= $(addprefix $(MDTRY_PATH),$(MDTRY_SRCS)) \
			  $(addprefix $(UTILS_PATH),$(UTILS_SRCS)) \
			  $(addprefix $(MAP_PATH),$(MAP_SRCS)) \
			  $(addprefix $(DATA_PATH),$(DATA_SRCS))

OBJS		= $(SRCS:.c=.o)

LIBFT_SRC	= libft

GNL_SRC		= libgnl

#MLX_SRC		= ifneq($(UNAME),Linux)

# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

RM			= rm -rf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I includes -I$(GNL_PATH) -I$(LIBFT_PATH) -I$(MLX_PATH)

LINKERS		=	-lm -L$(GNL_PATH) -l$(subst lib,,$(GNL_SRC)) \
-L$(LIBFT_PATH) -l$(subst lib,,$(LIBFT_SRC)) \
-L$(MLX_PATH) -l$(subst lib,,$(MLX_SRC))

MAKEFLAGS	+= --no-print-directory
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

all:	$(MLX_PATH) tools_update $(NAME)

$(MLX_PATH):
	echo $(UNAME)
ifeq ($(UNAME),Linux)
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
endif


tools_update:
	$(foreach tools,$(TOOLS),make -C $(tools);)

$(NAME):	$(OBJS) $(LIBS)
	$(CC) -g $(CFLAGS) $(OBJS) $(LINKERS) -o $(NAME) 

mclean:
ifneq (,$(shell ls $(OBJS) 2> /dev/null))
	$(RM) $(OBJS)
endif

tclean:
	$(foreach tools,$(TOOLS),make -C $(tools) clean;)

clean: mclean tclean

fclean: clean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	$(RM) $(NAME)
endif
	$(foreach tools,$(TOOLS),make -C $(tools) fclean;)

re:			fclean all

.PHONY:		all clean fclean re tools_update tclean mclean
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
