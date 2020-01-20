/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/17 17:22:47 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"
#include "checker.h"

void	operation_print(int **ab, char *operation, int debug_mode)
{
	handle_operation(ab, operation);
	ft_printf("%s\n", operation);
	if (debug_mode)
		debug_print_wait(ab);
}

int		check_number_group(int n, int **ab, int group_amount)
{
	int		i;
	int		j;
	float	divisor;

	i = 0;
	j = 0;
	divisor = ((float)*ab[2] + (float)*ab[3]) / (float)group_amount;
	while (*ab[2] > i)
	{
		if (ab[0][i] < n)
			j++;
		i++;
	}
	i = 0;
	while (*ab[3] > i)
	{
		if (ab[1][i] < n)
			j++;
		i++;
	}
	return (j / divisor);
}

int		find_first_group_number(int **ab, int group, int group_amount)
{
	int i;

	i = -1;
	while (*ab[2] > ++i)
		if (check_number_group(ab[0][i], ab, group_amount) == group)
			break ;
	return (i);
}

int		find_last_group_number(int **ab, int group, int group_amount)
{
	int i;

	i = *ab[2];
	while (1)
		if (check_number_group(ab[0][--i], ab, group_amount) == group)
			break ;
	return (i);
}

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

int		check_if_b_moves(int **ab)
{
	int biggest;
	int i;

	i = 0;
	biggest = 0;
	if (!smaller_than_stack(ab[0][0], ab, 1)
		&& !bigger_than_stack(ab[0][0], ab, 1))
		return (0);
	while (*ab[3] > ++i)
	{
		if (ab[1][i] > ab[1][biggest])
			biggest = i;
	}
	if (biggest <= *ab[3] / 2)
		return (biggest);
	else
		return ((*ab[3] - biggest) * -1);
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

int		stack_contains_group(int **ab, int stack, int group, int group_amount)
{
	int i;

	i = 0;
	if (!*ab[stack + 2])
		return (0);
	while (*ab[stack + 2] > i)
	{
		if (check_number_group(ab[stack][i], ab, group_amount) == group)
			return (1);
		i++;
	}
	return (0);
}

int		smaller_than_stack(int n, int **ab, int stack)
{
	int i;

	i = 0;
	while (*ab[stack + 2] > i)
		if (n > ab[stack][i++])
			return (0);
	return (1);
}

int		bigger_than_stack(int n, int **ab, int stack)
{
	int i;

	i = 0;
	while (*ab[stack + 2] > i)
		if (n < ab[stack][i++])
			return (0);
	return (1);
}

int		smallest_bigger_than(int n, int **ab, int stack)
{
	int i;
	int smallest;

	i = 0;
	smallest = ab[stack][0];
	while (*ab[stack + 2] > ++i)
	{
		if (ab[stack][i] < smallest && ab[stack][i] > n)
			smallest = ab[stack][i];
	}
	return (smallest);
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

void	debug_print_wait(int **ab)
{
	debug_print(ab);
	read(0, NULL, 1);
}

int		count_group_amount(int **ab)
{
	if (*ab[2] < 300)
		return (5);
	else
		return (11);
}
