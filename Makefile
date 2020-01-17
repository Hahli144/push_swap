#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 12:10:11 by sadawi            #+#    #+#              #
#    Updated: 2020/01/17 16:11:28 by sadawi           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=checker
NAME2=push_swap
SRCS=functions.c handle_operations.c
OBJS=functions.o handle_operations.o
FLAGS=-Wall -Wextra -Werror
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME) $(NAME2)

$(NAME):
	@$(RUN_LIB)
	gcc $(FLAGS) -c $(SRCS) $(NAME).c
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(NAME).o libft/libft.a

$(NAME2):
	@$(RUN_LIB)
	gcc $(FLAGS) -c $(SRCS) $(NAME2).c
	gcc $(FLAGS) -o $(NAME2) $(OBJS) $(NAME2).o libft/libft.a

clean:
	/bin/rm -f $(OBJS) $(NAME).o $(NAME2).o
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME) $(NAME2)
	make -C libft/ fclean

re: fclean all
