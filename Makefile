# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 12:14:02 by bbouagou          #+#    #+#              #
#    Updated: 2022/10/08 19:59:50 by bbouagou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -std=c99

DEPS = libft.h

OBJ = ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o\
ft_memset.o ft_strchr.o ft_strlen.o ft_strncmp.o ft_strrchr.o ft_toupper.o ft_tolower.o\
ft_memchr.o ft_bzero.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o\
ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o\
ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o\
ft_putendl_fd.o ft_putnbr_fd.o


OBJBONUS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o\
ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o\
ft_lstmap.o

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJBONUS) $(NAME) $(OBJ)
	ar rcs $(NAME) $(OBJBONUS) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all