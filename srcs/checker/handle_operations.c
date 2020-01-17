/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:28:08 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/10 16:38:21 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"

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

void	handle_pa(int ***ab)
{
	int i;

	i = *(*ab)[2];
	if (*(*ab)[3] == 0)
		return ;
	while (i > 0)
	{
		(*ab)[0][i] = (*ab)[0][i - 1];
		i--;
	}
	(*ab)[0][0] = (*ab)[1][0];
	while (*(*ab)[3] > i)
	{
		(*ab)[1][i] = (*ab)[1][i + 1];
		i++;
	}
	(*(*ab)[2])++;
	(*(*ab)[3])--;
}

void	handle_pb(int ***ab)
{
	int i;

	i = *(*ab)[3];
	if (*(*ab)[2] == 0)
		return ;
	while (i > 0)
	{
		(*ab)[1][i] = (*ab)[1][i - 1];
		i--;
	}
	(*ab)[1][0] = (*ab)[0][0];
	while (*(*ab)[2] > i)
	{
		(*ab)[0][i] = (*ab)[0][i + 1];
		i++;
	}
	(*(*ab)[3])++;
	(*(*ab)[2])--;
}

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
