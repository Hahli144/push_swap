/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
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

int		handle_input(int **ab, char *input, int debug_mode)
{
	if (!handle_operation(ab, input))
		return (1);
	if (debug_mode)
		debug_print(ab);
	return (0);
}

int		handle_sorting(int **ab, int debug_mode)
{
	char *input;

	while (1)
	{
		if (get_next_line(0, &input) == 0)
			break ;
		if (handle_input(ab, input, debug_mode))
			return (0);
		free(input);
	}
	return (1);
}

int		handle_operation(int **ab, char *input)
{
	if (ft_strequ(input, "sa"))
		handle_sa(&ab);
	else if (ft_strequ(input, "sb"))
		handle_sb(&ab);
	else if (ft_strequ(input, "ss"))
		handle_ss(&ab);
	else if (ft_strequ(input, "pa"))
		handle_pa(&ab);
	else if (ft_strequ(input, "pb"))
		handle_pb(&ab);
	else if (ft_strequ(input, "ra"))
		handle_ra(&ab);
	else if (ft_strequ(input, "rb"))
		handle_rb(&ab);
	else if (ft_strequ(input, "rr"))
		handle_rr(&ab);
	else if (ft_strequ(input, "rra"))
		handle_rra(&ab);
	else if (ft_strequ(input, "rrb"))
		handle_rrb(&ab);
	else if (ft_strequ(input, "rrr"))
		handle_rrr(&ab);
	else
		return (0);
	return (1);
}
