/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/14 16:52:12 by sadawi           ###   ########.fr       */
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
}

void	sort_stack(int **ab)
{
	if (check_order(ab))
		return ;
	while (*ab[2])
	{
		smallest_to_top(ab);
		operation_print(ab, "pb");
	}
	while (*ab[3])
		operation_print(ab, "pa");
}

int	main(int argc, char **argv)
{
	int *ab[4];

	if (argc == 1 || (argc == 2 && ft_strequ(argv[1], "-v")))
		return (0);
	if (check_error(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (create_stacks(argc, argv, ab))
		return (1);
	sort_stack(ab);
	return (0);
}
