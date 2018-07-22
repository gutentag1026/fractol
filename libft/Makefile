# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/02 03:11:27 by yhuang            #+#    #+#              #
#    Updated: 2018/07/08 02:24:47 by yhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


SRC = 	ft_strlen.c \
		ft_strdup.c \
		ft_strchr.c \
		ft_strdel.c \
		ft_strjoin.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memalloc.c \
		ft_atoi.c \
		ft_iswspace.c \
		get_next_line.c \
		ft_isdigit.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_str_tolower.c \
		ft_strcmp.c \
		ft_isupper.c
CFLAGS = -Wall -Wextra -Werror -I ./

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "compiling libft"
	gcc -c $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@echo "deleting objects"
	/bin/rm -f $(OBJ)

fclean: clean
	@echo "deleting objects"
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re
