/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/10 14:25:29 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"

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
		if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
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

int	create_stacks(int argc, char **argv, int **ab)
{
	int i;

	if (!(ab[0] = (int*)ft_memalloc(sizeof(int) * (argc - 1))))
		return (1);
	if (!(ab[1] = (int*)ft_memalloc(sizeof(int) * (argc - 1))))
		return (1);
	if (!(ab[2] = (int*)ft_memalloc(sizeof(int))))
		return (1);
	if (!(ab[3] = (int*)ft_memalloc(sizeof(int))))
		return (1);
	ab[2][0] = argc - 1;
	ab[3][0] = 0;
	i = 0;
	while (argc > ++i)
		ab[0][i - 1] = ft_atoi(argv[i]);
	return (0);
}

int	check_order(int **ab)
{
	int i;

	i = 0;
	while (*ab[2] > ++i)
		if (ab[0][i - 1] > ab[0][i])
			return (0);
	return (1);
}

int	check_input(char *input)
{
	if (ft_strequ(input, "sa") || ft_strequ(input, "sb") ||
		ft_strequ(input, "ss") || ft_strequ(input, "pa") ||
		ft_strequ(input, "pb") || ft_strequ(input, "ra") ||
		ft_strequ(input, "rb") || ft_strequ(input, "rr") ||
		ft_strequ(input, "rra") || ft_strequ(input, "rrb") ||
		ft_strequ(input, "rrr"))
		return (1);
	return (0);
}

int	handle_input(int **ab, char *input)
{
	(void)ab;
	(void)input;
	if (!check_input(input))
		return (1);
	//handle_operation(
	return (0);
}

//void	handle_operation()

int	handle_sorting(int **ab)
{
	char *input;

	while (1)
	{
		if (get_next_line(0, &input) == 0)
			break;
		if (handle_input(ab, input))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int *ab[4];

	if (check_error(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (create_stacks(argc, argv, ab))
		return (1);
	if (handle_sorting(ab))
	{
		if (check_order(ab))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
