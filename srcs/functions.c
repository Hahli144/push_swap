/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
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



int		count_arguments(int argc, char **argv)
{
	int i;
	int j;
	int total;

	i = 0;
	total = 0;
	if (ft_strequ(argv[1], "-v"))
		i++;
	while (argc > ++i)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]))
				total++;
			while (ft_isdigit(argv[i][j]))
				j++;
		}
	}
	return (total);
}

void	store_string_ints(int argc, char **argv, int **ab)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (ft_strequ(argv[1], "-v"))
		i++;
	while (argc > ++i)
	{
		j = 0;
		while (argv[i][j])
		{
			ab[0][k++] = ft_atoi(&argv[i][j]);
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-')
				j++;
			while (ft_isdigit(argv[i][j]))
				j++;
			while (argv[i][j] == ' ')
				j++;
		}
	}
}

int		create_stacks(int argc, char **argv, int **ab)
{
	int i;
	int size;

	i = 0;
	size = count_arguments(argc, argv);
	if (!(ab[0] = (int*)ft_memalloc(sizeof(int) * size)))
		return (1);
	if (!(ab[1] = (int*)ft_memalloc(sizeof(int) * size)))
		return (1);
	if (!(ab[2] = (int*)ft_memalloc(sizeof(int))))
		return (1);
	if (!(ab[3] = (int*)ft_memalloc(sizeof(int))))
		return (1);
	ab[2][0] = size;
	ab[3][0] = 0;
	store_string_ints(argc, argv, ab);
	return (0);
}

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
