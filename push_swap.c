/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/15 16:03:14 by sadawi           ###   ########.fr       */
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

	i = 0;
	j = 0;
	while (*ab[2] > i)
	{
		if (ab[0][i] < n)
			j++;
		i++;
	}
	return (j / (*ab[2] / group_amount));
}

void	smallest_to_top(int **ab)
{
	int smallest;
	int i;

	i = 0;
	smallest = 0;
	while (*ab[2] > ++i)
	{
		if (ab[0][i] < ab[0][smallest])
			smallest = i;
	}
	if (smallest <= *ab[2] / 2)
		while (smallest--)
			operation_print(ab, "ra");
	else
		while (smallest++ < *ab[2])
			operation_print(ab, "rra");
	if (check_order(ab))
		exit(0);
}

void	sort_stack(int **ab)
{
	if (check_order(ab))
		return ;
	ft_putnbr(check_number_group(ab[0][0], ab, 5));
	while (*ab[2])
	{
		smallest_to_top(ab);
		operation_print(ab, "pb");
		if (check_order(ab))
			exit(0);
	}
	while (*ab[3])
	{
		operation_print(ab, "pa");
		if (check_order(ab))
			exit(0);
	}
}

int	main(int argc, char **argv)
{
	int *ab[4];

	if (argc == 1 || (argc == 2 && ft_strequ(argv[1], "-v")))
		return (0);
	if (check_error(argc, argv))
		return(handle_error());
	if (create_stacks(argc, argv, ab))
		return (1);
	if (check_duplicate(ab))
		return (handle_error());
	sort_stack(ab);
	return (0);
}
