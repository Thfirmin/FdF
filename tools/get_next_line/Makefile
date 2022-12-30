# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 15:28:11 by thfirmin          #+#    #+#              #
#    Updated: 2022/12/29 21:39:55 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a

SRCS	= get_next_line.c \
		  get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -g -Wall -Wextra -Werror
MAKEFLAGS	+= --no-print-directory

CC	= cc

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
ifneq (,$(shell ls $(OBJS) 2> /dev/null))
	rm -rf $(OBJS)
endif

fclean:	clean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	rm -rf $(NAME)
endif

re:	fclean all

.PHONY:	all clean fclean re
