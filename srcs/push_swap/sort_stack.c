/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:45:26 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	sort_stack_small(int **ab, int debug_mode)
{
	int i;

	i = 0;
	if (check_order(ab))
		return ;
	if (debug_mode)
		debug_print_wait(ab);
	while (!bigger_than_stack(ab[0][i], ab, 0))
		i++;
	if (i == 0)
		operation_print(ab, "ra", debug_mode);
	if (i == 1)
		operation_print(ab, "rra", debug_mode);
	if (!check_order_stack(ab, 0))
		operation_print(ab, "sa", debug_mode);
}

void	sort_stack_medium(int **ab, int debug_mode)
{
	int i;

	i = 0;
	if (check_order(ab))
		return ;
	if (debug_mode)
		debug_print_wait(ab);
	biggest_to_top(ab, 0);
	if (debug_mode)
		debug_print_wait(ab);
	operation_print(ab, "pb", debug_mode);
	smallest_to_top(ab, 0);
	if (debug_mode)
		debug_print_wait(ab);
	operation_print(ab, "pb", debug_mode);
	sort_stack_small(ab, debug_mode);
	operation_print(ab, "pa", debug_mode);
	operation_print(ab, "pa", debug_mode);
	operation_print(ab, "ra", debug_mode);
}

void	sort_stack_groups(int **ab, int debug_mode)
{
	int group;
	int group_amount;

	if (check_order(ab))
		return ;
	group = 0;
	group_amount = count_group_amount(ab);
	if (debug_mode)
		debug_print_wait(ab);
	while (*ab[2])
	{
		while (stack_contains_group(ab, 0, group, group_amount))
		{
			group_number_to_top(ab, group, group_amount);
			rotate_stack_b(ab);
			operation_print(ab, "pb", debug_mode);
		}
		group++;
	}
	while (*ab[3])
	{
		biggest_to_top(ab, 1);
		operation_print(ab, "pa", debug_mode);
	}
}
