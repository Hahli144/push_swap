/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/16 19:30:54 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"
#include "checker.h"

void	operation_print(int **ab, char *operation)
{
	handle_operation(ab, operation);
	ft_printf("%s\n", operation);
}

int	check_number_group(int n, int **ab, int group_amount)
{
	int i;
	int j;
	float divisor;

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

void	group_number_to_top(int **ab, int group, int group_amount)
{
	int i;
	int first;
	int last;

	i = -1;
	while (*ab[2] > ++i)
		if (check_number_group(ab[0][i], ab, group_amount) == group)
		{
			first = i;
			break;
		}
	i = *ab[2];
	while (1)
		if (check_number_group(ab[0][--i], ab, group_amount) == group)
		{
			last = i;
			break;
		}
	//ft_printf("first: %d, last: %d, group: %d\n", first, last, group); //debug
	if (*ab[2] - last + 1 <= first)
		while (++last <= *ab[2])
		{
			if (check_if_b_moves(ab) < 0)
				operation_print(ab, "rrr");
			else
				operation_print(ab, "rra");
		}
	else
		while (first--)
		{
			if (check_if_b_moves(ab) > 0)
				operation_print(ab, "rr");
			else
				operation_print(ab, "ra");
		}
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
				operation_print(ab, "ra");
			else
				operation_print(ab, "rb");
	else
		while (smallest++ < *ab[stack + 2])
			if (stack == 0)
				operation_print(ab, "rra");
			else
				operation_print(ab, "rrb");
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
				operation_print(ab, "ra");
			else
				operation_print(ab, "rb");
	else
		while (biggest++ < *ab[stack + 2])
			if (stack == 0)
				operation_print(ab, "rra");
			else
				operation_print(ab, "rrb");
}

void	index_to_top(int index, int **ab, int stack)
{
	if (index <= *ab[stack + 2] / 2)
		while (index--)
			if (stack == 0)
				operation_print(ab, "ra");
			else
				operation_print(ab, "rb");
	else
		while (index++ < *ab[stack + 2])
			if (stack == 0)
				operation_print(ab, "rra");
			else
				operation_print(ab, "rrb");
}

int	stack_contains_group(int **ab, int stack, int group, int group_amount)
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

int	smaller_than_stack(int n, int **ab, int stack)
{
	int i;

	i = 0;
	while (*ab[stack + 2] > i)
		if (n > ab[stack][i++])
			return (0);
	return (1);
}

int	bigger_than_stack(int n, int **ab, int stack)
{
	int i;

	i = 0;
	while (*ab[stack + 2] > i)
		if (n < ab[stack][i++])
			return (0);
	return (1);
}

int	smallest_bigger_than(int n, int **ab, int stack)
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
	//int index;

	i = 0;
	if (smaller_than_stack(ab[0][0], ab, 1)
		|| bigger_than_stack(ab[0][0], ab, 1))
	{
		biggest_to_top(ab, 1);
		return ;
	}
	//index = smallest_bigger_than(ab[0][0], ab, 1);
	//index_to_top(index, ab, 1);
}

void	debug_print_wait(int **ab)
{
	debug_print(ab);
	read(0, NULL, 1);
}

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
	{
		operation_print(ab, "ra");
		if (debug_mode)
			debug_print_wait(ab);
	}
	if (i == 1)
	{
		operation_print(ab, "rra");
		if (debug_mode)
			debug_print_wait(ab);
	}
	if (!check_order(ab))
	{
		operation_print(ab, "sa");
		if (debug_mode)
			debug_print_wait(ab);
	}
}

void	sort_stack_medium(int **ab, int debug_mode)
{
	int i;

	i = 0;
	if (check_order(ab))
		return ;
	if (debug_mode)
		debug_print_wait(ab);
	while (*ab[2] > 3)
	{
		operation_print(ab, "pb");
		if (debug_mode)
			debug_print_wait(ab);
	}
	while (!bigger_than_stack(ab[0][i], ab, 0))
		i++;
	if (i == 0)
	{
		operation_print(ab, "ra");
		if (debug_mode)
			debug_print_wait(ab);
	}
	if (i == 1)
	{
		operation_print(ab, "rra");
		if (debug_mode)
			debug_print_wait(ab);
	}
	if (!check_order(ab))
	{
		operation_print(ab, "sa");
		if (debug_mode)
			debug_print_wait(ab);
	}
	if (*ab[3] == 1)
	{
		operation_print(ab, "pa");
		if (debug_mode)
			debug_print_wait(ab);
		operation_print(ab, "ra");
		if (debug_mode)
			debug_print_wait(ab);
	}
	//if (ab[1][0] < ab[1][1]
}

void	sort_stack_groups(int **ab, int debug_mode)
{
	int group;
	int group_amount;

	if (*ab[2] < 300)
		group_amount = 5;
	else
		group_amount = 11;
	if (check_order(ab))
		return ;
	//ft_putnbr(check_number_group(ab[0][0], ab, 5));
	group = 0;
	if (debug_mode)
		debug_print_wait(ab);
	while (*ab[2])
	{
		while (stack_contains_group(ab, 0, group, group_amount))
		{
			group_number_to_top(ab, group, group_amount);
			//ft_putnbr(check_if_b_moves(ab));
			//if (stack_contains_group(ab, 1, group, 5))
				rotate_stack_b(ab);
			//else
				//smallest_to_top(ab, 1);
			//ft_printf("%d\n", ab[0][0]); // debug
			operation_print(ab, "pb");
			//if (ab[1][0] < ab[1][1])
				//operation_print(ab, "sb");
			if (debug_mode)
				debug_print_wait(ab);
		}
		group++;
	}
	while (*ab[3])
	{
		biggest_to_top(ab, 1);
		operation_print(ab, "pa");
		if (debug_mode)
			debug_print_wait(ab);
	}
	//debug_print(ab); //debug
}

int	main(int argc, char **argv)
{
	int *ab[4];

	if (argc == 1 || (argc == 2 && ft_strequ(argv[1], "-v")))
		return (0);
	if (check_error(argc, argv))
		return (handle_error());
	if (create_stacks(argc, argv, ab))
		return (1);
	if (check_duplicate(ab))
		return (handle_error());
	if (*ab[2] < 4)
		sort_stack_small(ab, ft_strequ(argv[1], "-v"));
	else if (*ab[2] < 6)
		sort_stack_medium(ab, ft_strequ(argv[1], "-v"));
	else
		sort_stack_groups(ab, ft_strequ(argv[1], "-v"));
	return (0);
}

//implement sort_stack_medium for 4 and 5 numbers.
