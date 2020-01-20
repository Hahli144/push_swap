/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:44:08 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	operation_print(int **ab, char *operation, int debug_mode)
{
	handle_operation(ab, operation);
	ft_printf("%s\n", operation);
	if (debug_mode)
		debug_print_wait(ab);
}

void	debug_print(int **ab)
{
	int i;

	i = 0;
	ft_printf("%sStack a:    %sStack b:\n", "\x1B[31m", "\x1B[32m");
	while (*ab[2] > i || *ab[3] > i)
	{
		if (*ab[2] > i)
			ft_printf("%s%-8d  ", "\x1B[31m", ab[0][i]);
		else
			ft_printf("          ");
		if (*ab[3] > i)
			ft_printf("%s  %d", "\x1B[32m", ab[1][i]);
		ft_putendl("");
		i++;
	}
}

void	debug_print_wait(int **ab)
{
	debug_print(ab);
	read(0, NULL, 1);
}
