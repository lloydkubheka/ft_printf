# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 08:29:14 by xkubheka          #+#    #+#              #
#    Updated: 2018/08/24 12:19:10 by xkubheka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = *.c

OBJS = *.o

RMV = rm -f
all : $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRCS)
	ar -rc $(NAME) $(OBJS)

clean:
	$(RMV) $(OBJS)

fclean:
	$(RMV) $(NAME) $(OBJS)

re: fclean all
