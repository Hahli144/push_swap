/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/17 16:52:44 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"
#include "checker.h"

int		check_order(int **ab)
{
	int i;

	i = 0;
	if (*ab[3])
		return (0);
	while (*ab[2] > ++i)
		if (ab[0][i - 1] > ab[0][i])
			return (0);
	return (1);
}

int		check_order_stack(int **ab, int stack)
{
	int i;

	i = 0;
	while (*ab[stack + 2] > ++i)
		if (ab[stack][i - 1] > ab[stack][i])
			return (0);
	return (1);
}
