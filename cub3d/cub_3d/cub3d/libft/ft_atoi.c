/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:14:53 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/03 16:56:34 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_whit_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r' )
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long			x;
	long			sing;
	unsigned long	result;

	result = 0;
	sing = 1;
	x = handle_whit_spaces((char *)str);
	if (str[x] == '-')
		sing *= -1;
	if (str[x] == '-' || str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10 + (str[x] - '0');
		if (result > LLONG_MAX && sing == 1)
			return (-1);
		if (result > LLONG_MAX && sing == -1)
			return (0);
		x++;
	}
	return ((int)result * sing);
}
