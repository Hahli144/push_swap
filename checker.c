/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:58:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/09 17:43:44 by sadawi           ###   ########.fr       */
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

int	*create_array(int argc, char **argv)
{
	int i;
	int *arr;

	if (!(arr = (int *)malloc(sizeof(int) * (argc - 1))))
		return (NULL);
	i = 0;
	while (argc > ++i)
		arr[i - 1] = ft_atoi(argv[i]);
	return (arr);
}

int	check_order(int size, int *arr)
{
	while (--size > 0)
		if (arr[size] < arr[size - 1])
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

int	handle_input(int size, int *a, char *input)
{
	(void)size;
	(void)a;
	(void)input;
	if (!check_input(input))
		return (1);
	return (0);
}

int	handle_sorting(int size, int *a)
{
	char *input;

	(void)size;
	(void)a;
	while (1)
	{
		if (get_next_line(0, &input) == 0)
			break;
		if (handle_input(size, a, input))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int *a;

	if (check_error(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}	
	a = create_array(argc, argv);
	if (handle_sorting(argc - 1, a))
	{
		if (check_order(argc - 1, a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
