/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:45:13 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	group_number_to_top(int **ab, int group, int group_amount)
{
	int first;
	int last;

	first = find_first_group_number(ab, group, group_amount);
	last = find_last_group_number(ab, group, group_amount);
	if (*ab[2] - last + 1 <= first)
		while (++last <= *ab[2])
			if (check_if_b_moves(ab) < 0)
				operation_print(ab, "rrr", 0);
			else
				operation_print(ab, "rra", 0);
	else
		while (first--)
			if (check_if_b_moves(ab) > 0)
				operation_print(ab, "rr", 0);
			else
				operation_print(ab, "ra", 0);
}

void	smallest_to_top(int **ab, int stack)
{
	int smallest;
	int i;

	i = 0;
	smallest = 0;
	while (*ab[stack + 2] > ++i)
	{
		if (ab[stack][i] < ab[stack][smallest])
			smallest = i;
	}
	if (smallest <= *ab[stack + 2] / 2)
		while (smallest--)
			if (stack == 0)
				operation_print(ab, "ra", 0);
			else
				operation_print(ab, "rb", 0);
	else
		while (smallest++ < *ab[stack + 2])
			if (stack == 0)
				operation_print(ab, "rra", 0);
			else
				operation_print(ab, "rrb", 0);
}

void	biggest_to_top(int **ab, int stack)
{
	int biggest;
	int i;

	i = 0;
	biggest = 0;
	while (*ab[stack + 2] > ++i)
	{
		if (ab[stack][i] > ab[stack][biggest])
			biggest = i;
	}
	if (biggest <= *ab[stack + 2] / 2)
		while (biggest--)
			if (stack == 0)
				operation_print(ab, "ra", 0);
			else
				operation_print(ab, "rb", 0);
	else
		while (biggest++ < *ab[stack + 2])
			if (stack == 0)
				operation_print(ab, "rra", 0);
			else
				operation_print(ab, "rrb", 0);
}

void	index_to_top(int index, int **ab, int stack)
{
	if (index <= *ab[stack + 2] / 2)
		while (index--)
			if (stack == 0)
				operation_print(ab, "ra", 0);
			else
				operation_print(ab, "rb", 0);
	else
		while (index++ < *ab[stack + 2])
			if (stack == 0)
				operation_print(ab, "rra", 0);
			else
				operation_print(ab, "rrb", 0);
}

void	rotate_stack_b(int **ab)
{
	int i;

	i = 0;
	if (smaller_than_stack(ab[0][0], ab, 1)
		|| bigger_than_stack(ab[0][0], ab, 1))
	{
		biggest_to_top(ab, 1);
		return ;
	}
}
