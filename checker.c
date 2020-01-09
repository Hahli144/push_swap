/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/09 15:34:00 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"

int	check_array_int(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (argc > ++i)
	{
		j = 0;
		if (ft_atoilong(argv[i]) > 2147483647 ||
			ft_atoilong(argv[i]) < -2147483648)
			return (0);
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		}
	}
	return (1);
}

int	check_duplicate(int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	while (argc > ++j)
	{
		i = j;
		while (argc > ++i)
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (1);
	}
	return (0);
}

int	check_error(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (!check_array_int(argc, argv))
		return (1);
	if (check_duplicate(argc, argv))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_error(argc, argv))
		write(2, "Error\n", 6);
	return (0);
}
