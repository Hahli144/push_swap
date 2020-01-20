/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/20 14:43:27 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		check_if_digits(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			break ;
		if (!str[++i])
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int		check_string_ints(char *str)
{
	int i;

	i = 0;
	if (!check_if_digits(str))
		return (0);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (ft_atoilong(&str[i]) > 2147483647 ||
			ft_atoilong(&str[i]) < -2147483648)
			return (0);
		if (str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (1);
}

int		check_array_int(int argc, char **argv)
{
	int i;

	i = 0;
	if (ft_strequ(argv[1], "-v"))
		i++;
	while (argc > ++i)
	{
		if (!check_string_ints(argv[i]))
			return (0);
	}
	return (1);
}

int		check_duplicate(int **ab)
{
	int i;
	int j;

	j = 0;
	while (*ab[2] > j)
	{
		i = j;
		while (*ab[2] > ++i)
			if (ab[0][j] == ab[0][i])
				return (1);
		j++;
	}
	return (0);
}
