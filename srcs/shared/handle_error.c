/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:43:57 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		handle_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int		check_error(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (!check_array_int(argc, argv))
		return (1);
	return (0);
}
