# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 10:29:25 by ykliek            #+#    #+#              #
#    Updated: 2019/01/14 10:29:28 by ykliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLSGS = -Wall -Wextra -Werror

SRCS = main.c \
		ft_printf.c \
		parser.c \
		ft_itoa_base.c \
		ft_ftoa.c \
		precision.c \
		modifiers.c \
		tools.c

HEADER = printf.h

LIB = ./libft/libft.a

NAME = a.out

all : $(NAME)

$(NAME):
	$(CC) $(CFLSGS) $(SRCS) $(HEADER) $(LIB) 

clean:
	rm -f fillit.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all