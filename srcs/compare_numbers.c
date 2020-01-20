/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_numbers.c                                  :+:      :+:    :+:   */
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
