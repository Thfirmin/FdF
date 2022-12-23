# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:23:56 by thfirmin          #+#    #+#              #
#    Updated: 2022/12/11 22:05:47 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES 

NAME	= libft.a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

SRCS	= ft_atoi.c       \
		  ft_bzero.c      \
		  ft_calloc.c     \
		  ft_isalnum.c    \
		  ft_isalpha.c    \
		  ft_isascii.c    \
		  ft_isdigit.c    \
		  ft_isprint.c    \
		  ft_memchr.c     \
		  ft_memcmp.c     \
		  ft_memcpy.c     \
		  ft_memmove.c    \
		  ft_memset.c     \
		  ft_strchr.c     \
		  ft_strdup.c     \
		  ft_strlcat.c    \
		  ft_strlcpy.c    \
		  ft_strlen.c     \
		  ft_strncmp.c    \
		  ft_strnstr.c    \
		  ft_strrchr.c    \
		  ft_tolower.c    \
		  ft_toupper.c    \
		  ft_substr.c     \
		  ft_strjoin.c    \
		  ft_strtrim.c    \
		  ft_split.c      \
		  ft_itoa.c       \
		  ft_strmapi.c    \
		  ft_striteri.c   \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c  \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c  \
		  ft_isall.c      \
		  ft_nbrlen.c

BN_SRCS	= ft_lstadd_back_bonus.c  \
		  ft_lstclear_bonus.c     \
		  ft_lstiter_bonus.c      \
		  ft_lstmap_bonus.c       \
		  ft_lstsize_bonus.c      \
		  ft_lstadd_front_bonus.c \
		  ft_lstdelone_bonus.c    \
		  ft_lstnew_bonus.c       \
		  ft_lstlast_bonus.c

OBJS	= $(SRCS:.c=.o)

BN_OBJS	= $(subst .c,.o,$(BN_SRCS))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

PATH_NAME	= ../../
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDE		= -I../../ -I../../includes
BN_UPDATE	= $(findstring $*.c,$?)
BN_ACTUAL	= $(subst .o,.c,$@)
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

all:		$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(PATH_NAME)$(NAME) $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(PATH_NAME)$(NAME)
	ranlib $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

bonus:	all $(BN_OBJS)

$(BN_OBJS):	$(BN_SRCS)
	@if [ "$(BN_ACTUAL)" = "$(BN_UPDATE)" ]; then \
		echo "$(CC) $(CFLAGS) $(INCLUDE) -c $*.c -o $@"; \
		$(CC) $(CFLAGS) $(INCLUDE) -c $*.c -o $@; \
	else \
		touch $@; \
	fi
	@if [ "$@" = "$(lastword $(BN_OBJS))" ]; then \
		echo "ar -rcs $(NAME) $(BN_OBJS)"; \
		ar -rcs $(NAME) $(BN_OBJS); \
		echo "ranlib $(NAME)"; \
		ranlib $(NAME); \
		echo "ar -rcs $(PATH_NAME)$(NAME) $(BN_OBJS)"; \
		ar -rcs $(PATH_NAME)$(NAME) $(BN_OBJS); \
		echo "ranlib $(PATH_NAME)$(NAME)"; \
		ranlib $(PATH_NAME)$(NAME); \
	fi

mclean:
ifneq (,$(shell ls $(OBJS) 2> /dev/null))
	rm -rf $(OBJS)
endif

bclean:
ifneq (,$(shell ls $(BN_OBJS) 2> /dev/null))
	rm -rf $(BN_OBJS)
endif

clean: 		mclean bclean

fclean:		clean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	rm -rf $(NAME)
endif

re:			fclean all

bre:		fclean bonus

.PHONY:		all bonus mclean bclean clean fclean re bre
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
