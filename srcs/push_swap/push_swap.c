/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:45:19 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		main(int argc, char **argv)
{
	int *ab[4];

	if (argc == 1 || (argc == 2 && ft_strequ(argv[1], "-v")))
		return (0);
	if (check_error(argc, argv))
		return (handle_error());
	if (create_stacks(argc, argv, ab))
		return (1);
	if (check_duplicate(ab))
		return (handle_error());
	if (*ab[2] < 4)
		sort_stack_small(ab, ft_strequ(argv[1], "-v"));
	else if (*ab[2] < 6)
		sort_stack_medium(ab, ft_strequ(argv[1], "-v"));
	else
		sort_stack_groups(ab, ft_strequ(argv[1], "-v"));
	return (0);
}
