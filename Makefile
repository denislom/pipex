# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/02 18:19:36 by dlom              #+#    #+#              #
#    Updated: 2023/09/02 18:21:44 by dlom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		=	pipex.c
OBJS		=	${SRCS:.c=.o}
NAME		=	pipex
INCS		=	pipex.h
LIBC		=	ar rc
RM			=	rm -f
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

all: ${NAME}

%.o: %.c ${INCS}
	${CC} ${CFLAGS} -c ${SRCS}

$(NAME): ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus