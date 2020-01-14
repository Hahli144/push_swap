#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 12:10:11 by sadawi            #+#    #+#              #
#    Updated: 2020/01/13 16:48:45 by sadawi           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=checker
SRCS=checker.c handle_operations.c
OBJS=*.o
FLAGS=-Wall -Wextra -Werror
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME):
	@$(RUN_LIB)
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a

clean:
	/bin/rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
