# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 01:21:51 by thfirmin          #+#    #+#              #
#    Updated: 2022/10/15 01:48:03 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES 

NAME	= libft.a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

SRCS_PAT	= srcs/

SRCS_LIB	= libft \
			  ft_printf \

SRCS		= $(addprefix $(SRCS_PAT),$(SRCS_LIB))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

MAKE	= make -C
RM		= rm -rf
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CODE 

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

all:	$(NAME)

$(NAME): $(SRCS_PAT)$(NAME)
	cp $(SRCS_PAT)$(NAME) ./

$(SRCS_PAT)$(NAME):
	$(foreach srcs, $(SRCS), $(MAKE) $(srcs);)

clean:
ifneq (, $(shell ls $(SRCS_PAT)$(NAME) 2> /dev/null))
	$(RM) $(SRCS_PAT)$(NAME)
endif
	$(foreach srcs, $(SRCS), $(MAKE) $(srcs) clean;)


fclean:
ifneq (, $(shell ls $(SRCS_PAT)$(NAME) 2> /dev/null))
	$(RM) $(SRCS_PAT)$(NAME)
endif
ifneq (, $(shell ls $(NAME) 2> /dev/null))
	$(RM) $(NAME)
endif
	$(foreach srcs, $(SRCS), $(MAKE) $(srcs) fclean;)

re:			fclean all

acessed:
	echo ACESSED

.PHONY:		all clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
