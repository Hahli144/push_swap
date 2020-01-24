#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 12:10:11 by sadawi            #+#    #+#              #
#    Updated: 2020/01/20 15:03:01 by sadawi           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=checker
NAME2=push_swap
SRCS_CHECKER=srcs/checker/checker.c
SRCS_SHARED= srcs/shared/check_arguments.c srcs/shared/check_order.c \
srcs/shared/create_stacks.c srcs/shared/handle_error.c srcs/shared/print.c \
srcs/shared/handle_input.c srcs/shared/handle_push_operations.c \
srcs/shared/handle_shift_down_operations.c \
srcs/shared/handle_shift_up_operations.c srcs/shared/handle_swap_operations.c
SRCS_PUSH_SWAP=srcs/push_swap/push_swap.c srcs/push_swap/b_stack_lookahead.c \
srcs/push_swap/check_group.c srcs/push_swap/sort_stack.c \
srcs/push_swap/find_number.c srcs/push_swap/move_number.c \
srcs/push_swap/compare_numbers.c
OBJS_CHECKER=$(notdir $(SRCS_CHECKER:.c=.o))
OBJS_SHARED=$(notdir $(SRCS_SHARED:.c=.o))
OBJS_PUSH_SWAP=$(notdir $(SRCS_PUSH_SWAP:.c=.o))
FLAGS=-Wall -Wextra -Werror
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME) $(NAME2)

$(NAME):
	@$(RUN_LIB)
	gcc $(FLAGS) -c $(SRCS_CHECKER) $(SRCS_SHARED)
	gcc $(FLAGS) -o $(NAME) $(OBJS_CHECKER) $(OBJS_SHARED) libft/libft.a

$(NAME2):
	@$(RUN_LIB)
	gcc $(FLAGS) -c $(SRCS_PUSH_SWAP) $(SRCS_SHARED)
	gcc $(FLAGS) -o $(NAME2) $(OBJS_PUSH_SWAP) $(OBJS_SHARED) libft/libft.a

clean:
	/bin/rm -f $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(OBJS_SHARED)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME) $(NAME2)
	make -C libft/ fclean

re: fclean all
