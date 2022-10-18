# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                          :+:     :+:             #
#                                                     +:+ +:+         +:+      #
#    By: thino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 03:44:47 by thino             #+#    #+#              #
#    Updated: 2022/09/01 02:25:11 by Thinotsuki   ###     ###.br               #
#                                                                              #
# **************************************************************************** #

# +>                                     NAME

NAME	= libftprintf.a

LIBFT	= ../libft.a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                 SOURCE FILES

LIB		= ../../includes

SRCS	= ft_printf.c    \
		  ft_puthex_fd.c \
		  ft_putptr_fd.c \
		  ft_putunbr_fd.c
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                 OBJECT FILES

OBJS	= $(SRCS:.c=.o)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES

RM			= rm -rf
AR			= ar rcs
CC			= cc
INCLUDE		= -I $(LIB)
CFLAGS		= -g -Wall -Wextra -Werror
MAKEFLAGS	+= --silent
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                  TEXT CODES

BLANK		= \e[m
RED			= \e[38;5;9m
YELLOW		= \e[38;5;11m
GREEN		= \e[38;5;2m
BLUE		= \e[38;5;6m
PURPLE		= \e[38;5;5m
PINK		= \e[38;5;13m
WHITE		= \e[38;5;15m

BOLD		= \e[1m
SHADOW		= \e[2m
ITALIC		= \e[3m
UNDLINE		= \e[4m
UPPLINE		= \e[53m
DUNDLINE	= \e[21m
CENSORED	= \e[9m
UPALIGN		= \e[73m
DWALIGN		= \e[74m
FULLER		= \e[7m
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     RULES

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all:		checking $(NAME) created

$(NAME):	$(OBJS)
	@printf "[$(BLUE)$(UNDLINE)Objects of $(NAME)$(BLANK)] $(GREEN)Has Been $(BOLD)Compiled!$(BLANK)\n"
	$(AR) $(NAME) $(OBJS)
	$(AR) $(LIBFT) $(OBJS)

clean:
	$(RM) $(OBJS)
	@printf "[$(BLUE)$(UNDLINE)Objects of $(NAME)$(BLANK)] $(YELLOW)Has Been $(BOLD)Deleted!$(BLANK)\n"

fclean:		clean
	$(RM) $(NAME)
	@printf "[$(BLUE)$(UNDLINE)$(NAME)$(BLANK)] $(RED)Has Been $(BOLD)Deleted!$(BLANK)\n"

re:			fclean all

checking:
	@printf "$(BOLD)Checking [$(BLUE)$(UNDLINE)Objects of $(NAME)$(BLANK)] Wait a minute...\n"

created:
	@printf "[$(BLUE)$(UNDLINE)$(NAME)$(BLANK)] $(GREEN)Has Been $(BOLD)Created!$(BLANK)\n"

.PHONY:		all clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
