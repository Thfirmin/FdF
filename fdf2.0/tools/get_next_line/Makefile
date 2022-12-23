# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 15:28:11 by thfirmin          #+#    #+#              #
#    Updated: 2022/12/23 16:31:04 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a

SRCS	= get_next_line.c \
		  get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -g -Wall -Wextra -Werror

CC	= cc

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
