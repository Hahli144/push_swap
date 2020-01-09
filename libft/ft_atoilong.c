/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:32:47 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/08 18:15:34 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoilong(const char *str)
{
	long	result;
	int		i;
	int		j;
	int		flag;

	i = 0;
	result = 0;
	flag = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	while (i > j && ft_isdigit(str[j]))
	{
		result = result * 10 + str[j] - '0';
		j++;
	}
	return (result * flag);
}
