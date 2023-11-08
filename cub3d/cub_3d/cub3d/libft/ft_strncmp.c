/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:04:14 by oelboukh          #+#    #+#             */
/*   Updated: 2022/10/25 18:39:56 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while ((char)s1[index] == (char)s2[index]
		&& index < (n - 1) && (char)s1[index] && (char)s2[index])
	{
		index++;
	}
	if ((unsigned char)s1[index] - (char unsigned)s2[index] < 0)
	{
		return (-1);
	}
	if ((char unsigned )s1[index] - (char unsigned)s2[index] > 0)
	{
		return (1);
	}
	return (0);
}
