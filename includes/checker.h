/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:27:35 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:45:51 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "../libft/get_next_line.h"

void	handle_sa(int ***ab);

void	handle_sb(int ***ab);

void	handle_ss(int ***ab);

void	handle_pa(int ***ab);

void	handle_pb(int ***ab);

void	handle_ra(int ***ab);

void	handle_rb(int ***ab);

void	handle_rr(int ***ab);

void	handle_rra(int ***ab);

void	handle_rrb(int ***ab);

void	handle_rrr(int ***ab);

int		check_array_int(int argc, char **argv);

int		check_duplicate(int **ab);

int		check_error(int argc, char **argv);

int		create_stacks(int argc, char **argv, int **ab);

int		check_order(int **ab);

int		check_order_stack(int **ab, int stack);

int		check_input(char *input);

int		handle_operation(int **ab, char *input);

void	debug_print(int **ab);

void	debug_print_wait(int **ab);

int		handle_input(int **ab, char *input, int debug_mode);

int		handle_sorting(int **ab, int debug_mode);

int		handle_error(void);

int		smaller_than_stack(int n, int **ab, int stack);

int		bigger_than_stack(int n, int **ab, int stack);

int		check_if_b_moves(int **ab);

int		check_if_digits(char *str);

int		check_string_ints(char *str);

int		count_arguments(int argc, char **argv);

void	store_string_ints(int argc, char **argv, int **ab);

void	operation_print(int **ab, char *operation, int debug_mode);

int		check_number_group(int n, int **ab, int group_amount);

int		find_first_group_number(int **ab, int group, int group_amount);

int		find_last_group_number(int **ab, int group, int group_amount);

void	group_number_to_top(int **ab, int group, int group_amount);

void	smallest_to_top(int **ab, int stack);

void	biggest_to_top(int **ab, int stack);

void	index_to_top(int index, int **ab, int stack);

int		stack_contains_group(int **ab, int stack, int group, int group_amount);

int		smaller_than_stack(int n, int **ab, int stack);

int		bigger_than_stack(int n, int **ab, int stack);

int		smallest_bigger_than(int n, int **ab, int stack);

void	rotate_stack_b(int **ab);

void	sort_stack_small(int **ab, int debug_mode);

void	sort_stack_medium(int **ab, int debug_mode);

void	sort_stack_groups(int **ab, int debug_mode);

int		count_group_amount(int **ab);

#endif
