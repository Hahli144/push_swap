/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number.c                                      :+:      :+:    :+:   */
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
