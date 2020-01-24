/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shift_up_operations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:28:08 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:43:01 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	handle_ra(int ***ab)
{
	int i;
	int tmp;

	i = 0;
	if (*(*ab)[2] == 0)
		return ;
	tmp = (*ab)[0][0];
	while (*(*ab)[2] > i)
	{
		(*ab)[0][i] = (*ab)[0][i + 1];
		i++;
	}
	(*ab)[0][i - 1] = tmp;
}

void	handle_rb(int ***ab)
{
	int i;
	int tmp;

	i = 0;
	if (*(*ab)[3] == 0)
		return ;
	tmp = (*ab)[1][0];
	while (*(*ab)[3] > i)
	{
		(*ab)[1][i] = (*ab)[1][i + 1];
		i++;
	}
	(*ab)[1][i - 1] = tmp;
}

void	handle_rr(int ***ab)
{
	handle_ra(ab);
	handle_rb(ab);
}
