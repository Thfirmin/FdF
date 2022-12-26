# **************************************************************************** #
                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 06:08:08 by thfirmin          #+#    #+#              #
#    Updated: 2022/12/26 01:13:50 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAME 

NAME		= fdf

TOOLS		= $(LIBFT_PATH) \
			  $(GNL_PATH) \
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATH

TOOL_PATH	= tools/
LIBFT_PATH	= $(addprefix $(TOOL_PATH),libft/)
GNL_PATH	= $(addprefix $(TOOL_PATH),get_next_line/)

SRCS_PATH	= srcs/
MDTRY_PATH	= $(addprefix $(SRCS_PATH),mandatory/)
UTILS_PATH	= $(addprefix $(SRCS_PATH),utils/)
MAP_PATH	= $(addprefix $(SRCS_PATH),map/)
DATA_PATH	= $(addprefix $(SRCS_PATH),data/)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES

MDTRY_SRCS	= fdf_main.c

MAP_SRCS	= fdf_initmap.c \
			  fdf_is_validmap.c

DATA_SRCS	= fdf_pntnew.c \
			  fdf_pntclear.c \
			  fdf_pntadd_back.c

UTILS_SRCS	= fdf_error.c

SRCS		= $(addprefix $(MDTRY_PATH),$(MDTRY_SRCS)) \
			  $(addprefix $(UTILS_PATH),$(UTILS_SRCS)) \
			  $(addprefix $(MAP_PATH),$(MAP_SRCS)) \
			  $(addprefix $(DATA_PATH),$(DATA_SRCS))

OBJS		= $(SRCS:.c=.o)

LIBFT_SRC	= libft

GNL_SRC		= libgnl
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

RM			= rm -rf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I includes -I$(GNL_PATH) -I$(LIBFT_PATH)
LINKERS		= -L$(GNL_PATH) -l$(subst lib,,$(GNL_SRC)) -L$(LIBFT_PATH) -l$(subst lib,,$(LIBFT_SRC))
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

all:	tools_update $(NAME)

tools_update:
	$(foreach tools,$(TOOLS),make -C $(tools);)

$(NAME):	$(OBJS)
	$(CC) -g $(CFLAGS) $(INCLUDE) $(OBJS) $(LINKERS) -o $(NAME) 

clean:
ifneq (,$(shell ls $(OBJS) 2> /dev/null))
	$(RM) $(OBJS)
endif
	$(foreach tools,$(TOOLS),make -C $(tools) clean;)

fclean: clean
ifneq (,$(ls $(NAME) 2> /dev/null))
	$(RM) $(NAME)
endif
	$(foreach tools,$(TOOLS),make -C $(tools) fclean;)

re:			fclean all

.PHONY:		all clean fclean re tools_update
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
