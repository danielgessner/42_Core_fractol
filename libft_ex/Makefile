# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 04:04:18 by dgessner          #+#    #+#              #
#    Updated: 2025/05/20 13:07:19 by dgessner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS	= -Wall -Werror -Wextra

SRC_DIR    = src
SRCS	= 	$(SRC_DIR)/ft_atoi.c \
            $(SRC_DIR)/ft_bzero.c \
			$(SRC_DIR)/ft_calloc.c \
			$(SRC_DIR)/ft_isalnum.c \
            $(SRC_DIR)/ft_isalpha.c \
            $(SRC_DIR)/ft_isascii.c \
			$(SRC_DIR)/ft_isdigit.c \
			$(SRC_DIR)/ft_isprint.c \
			$(SRC_DIR)/ft_itoa.c \
			$(SRC_DIR)/ft_itoa_unsigned.c \
			$(SRC_DIR)/ft_memchr.c \
            $(SRC_DIR)/ft_memcmp.c \
            $(SRC_DIR)/ft_memcpy.c \
            $(SRC_DIR)/ft_memmove.c \
			$(SRC_DIR)/ft_memset.c \
			$(SRC_DIR)/ft_putchar_fd.c \
			$(SRC_DIR)/ft_putendl_fd.c \
			$(SRC_DIR)/ft_putnbr_fd.c \
			$(SRC_DIR)/ft_putstr_fd.c \
			$(SRC_DIR)/ft_split.c \
			$(SRC_DIR)/ft_strchr.c \
			$(SRC_DIR)/ft_strdup.c \
			$(SRC_DIR)/ft_striteri.c \
			$(SRC_DIR)/ft_strjoin.c \
			$(SRC_DIR)/ft_strlcat.c \
			$(SRC_DIR)/ft_strlcpy.c \
			$(SRC_DIR)/ft_strlen.c \
			$(SRC_DIR)/ft_strmapi.c \
			$(SRC_DIR)/ft_strncmp.c \
			$(SRC_DIR)/ft_strnstr.c \
			$(SRC_DIR)/ft_strrchr.c \
			$(SRC_DIR)/ft_strtrim.c \
			$(SRC_DIR)/ft_substr.c \
			$(SRC_DIR)/ft_tolower.c \
			$(SRC_DIR)/ft_toupper.c \

PRINTF_DIR = printf
PRINTF_SRCS = 	$(PRINTF_DIR)/ft_printf.c \
				$(PRINTF_DIR)/ft_puthexa.c \
				$(PRINTF_DIR)/ft_search_type.c \
				$(PRINTF_DIR)/ft_type_decimal.c \
				$(PRINTF_DIR)/ft_type_string.c \
				$(PRINTF_DIR)/ft_type_char.c \
				$(PRINTF_DIR)/ft_type_pointer.c \
			  	$(PRINTF_DIR)/ft_type_hexa.c \
			  	$(PRINTF_DIR)/ft_type_unsigned.c \
				
OBJS	= ${SRCS:.c=.o} \
			${PRINTF_SRCS:.c=.o}

BONUS_OBJS	= ${BONUS-SRCS:.c=.o}

FLAGS	= -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus:		${OBJS} ${BONUS_OBJS}
			ar -rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean clean bonus all 