# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:27:33 by jwisozk           #+#    #+#              #
#    Updated: 2019/07/20 15:38:52 by jwisozk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
CFLAGS = -Wall -Wextra -Werror
HEADERS = fractol.h
LIBMLX = -L minilibx -lmlx -framework OpenGL -framework AppKit
LIBFT = libft/libft.a
MAKE_LIBFT = make -C libft
SOURCE = main.c \
         draw.c  \
         scale.c \
         color.c \
         keys.c \
         mouse.c
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE_LIBFT)
	$(CC) $(CFLAGS) $^ $(LIBFT) $(LIBMLX) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -pthread -c $<

clean:
	rm -f $(OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all fclean re clean
