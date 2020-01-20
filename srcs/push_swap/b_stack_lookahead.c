/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_lookahead.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:44:37 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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
