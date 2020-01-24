/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_swap_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:28:08 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:43:01 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	handle_sa(int ***ab)
{
	int tmp;

	if (*(*ab)[2] < 2)
		return ;
	tmp = (*ab)[0][0];
	(*ab)[0][0] = (*ab)[0][1];
	(*ab)[0][1] = tmp;
}

void	handle_sb(int ***ab)
{
	int tmp;

	if (*(*ab)[3] < 2)
		return ;
	tmp = (*ab)[1][0];
	(*ab)[1][0] = (*ab)[1][1];
	(*ab)[1][1] = tmp;
}

void	handle_ss(int ***ab)
{
	handle_sa(ab);
	handle_sb(ab);
}
