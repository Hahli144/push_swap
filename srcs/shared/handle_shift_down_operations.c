/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shift_down_operations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:28:08 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:43:01 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	handle_rra(int ***ab)
{
	int i;
	int tmp;

	i = *(*ab)[2];
	if (*(*ab)[2] == 0)
		return ;
	tmp = (*ab)[0][*(*ab)[2] - 1];
	while (i > 0)
	{
		(*ab)[0][i] = (*ab)[0][i - 1];
		i--;
	}
	(*ab)[0][0] = tmp;
}

void	handle_rrb(int ***ab)
{
	int i;
	int tmp;

	i = *(*ab)[3];
	if (*(*ab)[3] == 0)
		return ;
	tmp = (*ab)[1][*(*ab)[3] - 1];
	while (i > 0)
	{
		(*ab)[1][i] = (*ab)[1][i - 1];
		i--;
	}
	(*ab)[1][0] = tmp;
}

void	handle_rrr(int ***ab)
{
	handle_rra(ab);
	handle_rrb(ab);
}
