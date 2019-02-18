#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/31 19:07:09 by skarev            #+#    #+#              #
#    Updated: 2019/01/31 19:07:10 by skarev           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CFLAG = -O3 -Wall -Wextra -lmlx -framework OpenGL -framework AppKit

SRCS = main.c parce.c tools.c init_stuff.c draw.c controls.c lgnl.c \
		controls_2.c rotating.c

LIBS = ./libft/libft.a

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft
	@gcc $(CFLAG) -o $(NAME) $(SRCS) $(LIBS)

clean:
		@make -C libft clean

fclean: clean
		@make -C libft fclean
		@/bin/rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re