/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
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
