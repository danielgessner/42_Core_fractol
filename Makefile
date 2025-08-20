# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 13:33:24 by dgessner          #+#    #+#              #
#    Updated: 2025/06/14 13:23:58 by dgessner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror 
LIBMLX	:= ./MLX42
LIBFT	:= ./libft_ex

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
SRCS	:= 	main.c calculations.c hooks.c graphics.c atof.c
			
OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	cmake -S $(LIBMLX) -B $(LIBMLX)/build
	cmake --build $(LIBMLX)/build --parallel 4

libft:
	$(MAKE) -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME) $(HEADERS)

clean:
	rm -f $(OBJS)
	rm -rf $(LIBMLX)/build
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx