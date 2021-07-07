# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 13:17:46 by mlecuyer          #+#    #+#              #
#    Updated: 2021/04/29 17:18:32 by mlecuyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NA		=	nasm

NFLAGS	=	-f elf64

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libasm.a

SRCS	=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \
			
INCLUDE	=	libasm.h

OBJS	=	${SRCS:.s=.o}

RM		=	rm -rf

.s.o:
		${NA} ${NFLAGS} $<

.c.o:
		${CC} ${CFLAGS} $<

${NAME}: ${OBJS}
			$ ar rc libasm.a ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean 
		${RM} ${NAME}

test: 
	$ clang -Wall -Wextra -Werror -g3 main.c -L. -lasm -o run_tests


re:		fclean all

.PHONY:	all clean fclean re

