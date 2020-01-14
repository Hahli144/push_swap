/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:27:35 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/13 16:33:53 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

int		check_duplicate(int argc, char **argv);

int		check_error(int argc, char **argv);

int		create_stacks(int argc, char **argv, int **ab);

int		check_order(int **ab);

int		check_input(char *input);

void	handle_operation(int **ab, char *input);

void	debug_print(int **ab);

int		handle_input(int **ab, char *input, int debug_mode);

int		handle_sorting(int **ab, int debug_mode);

#endif
