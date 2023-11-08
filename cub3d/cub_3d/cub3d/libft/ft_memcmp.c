/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:38:25 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/03 17:22:12 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
			index = 0;
	while (index < (n))
	{
		if (*(unsigned char *)s1 != *(char unsigned *)s2)
			return (*(char unsigned *)s1 - *(char unsigned *)s2);
		index++;
		s1++;
		s2++;
	}
	return (0);
}
