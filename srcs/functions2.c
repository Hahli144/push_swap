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





int		count_group_amount(int **ab)
{
	if (*ab[2] < 300)
		return (5);
	else
		return (11);
}
