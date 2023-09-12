# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/02 18:19:36 by dlom              #+#    #+#              #
#    Updated: 2023/09/12 22:33:30 by dlom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# env
PROGRAM = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# header for pipex
HEADER = pipex.h

# main part of pipex
SRC_M = pipex.c pipex_utils.c
OBJ_M = $(SRC_M:.c=.o)

# functions from libft
SRC_LIBFT = ft_split.c \
			ft_strdup.c \
			ft_strncmp.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strlen.c 
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)


# make
%.o: %.c 		$(HEADER) Makefile
						@$(CC) $(FLAGS) -c $< -o $@

(PROGRAM):		$(OBJ_M) $(OBJ_LIBFT) $(OBJ_GNL)
						@echo "Give me a second, I am not your slave!"
						@$(CC) $(OBJ_M) $(OBJ_LIBFT) -o $(PROGRAM)
						@echo "$(PROGRAM) created!"

all: $(PROGRAM)

clean:
						@$(RM) $(OBJ_M)
						@$(RM) $(OBJ_LIBFT)
						@echo "Object files deleted!"

fclean:			clean
						@$(RM) $(PROGRAM)
						@echo "Everything was deleted!"

re:				fclean all