/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:44:45 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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

int		count_group_amount(int **ab)
{
	if (*ab[2] < 300)
		return (5);
	else
		return (11);
}
