# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademenet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 14:07:17 by ademenet          #+#    #+#              #
#    Updated: 2015/12/01 09:11:53 by ademenet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SOURCES = ft_atoi.c\
		  ft_bzero.c\
		  ft_isalnum.c\
		  ft_isalpha.c\
		  ft_isascii.c\
		  ft_isdigit.c\
		  ft_isprint.c\
		  ft_itoa.c\
		  ft_memalloc.c\
		  ft_memccpy.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_memcpy.c\
		  ft_memdel.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_putchar.c\
		  ft_putchar_fd.c\
		  ft_putendl.c\
		  ft_putendl_fd.c\
		  ft_putnbr.c\
		  ft_putnbr_fd.c\
		  ft_putstr.c\
		  ft_putstr_fd.c\
		  ft_strcat.c\
		  ft_strchr.c\
		  ft_strclr.c\
		  ft_strcmp.c\
		  ft_strcpy.c\
		  ft_strdel.c\
		  ft_strdup.c\
		  ft_strequ.c\
		  ft_striter.c\
		  ft_striteri.c\
		  ft_strjoin.c\
		  ft_strlcat.c\
		  ft_strlen.c\
		  ft_strmap.c\
		  ft_strmapi.c\
		  ft_strncat.c\
		  ft_strncmp.c\
		  ft_strncpy.c\
		  ft_strnequ.c\
		  ft_strnew.c\
		  ft_strrchr.c\
		  ft_strsplit.c\
		  ft_strstr.c\
		  ft_strnstr.c\
		  ft_strsub.c\
		  ft_strtrim.c\
		  ft_tolower.c\
		  ft_toupper.c

HEADERS = libft.h

OBJECT = $(SOURCES:.c=.o)

$(NAME): $(OBJECT)
	gcc $(CC_FLAGS) -c $(SOURCES)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

all: $(NAME)

testlib:
	gcc $(FLAGS) test_libft.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c\
		ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c ft_atoi.c\
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c\
		ft_strdel.c ft_strclr.c 

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: clean fclean
