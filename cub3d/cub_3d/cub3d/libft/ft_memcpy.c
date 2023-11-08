/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 08:43:36 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/03 17:10:25 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*sr;
	char		*dest;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (ft_memcmp(dst, src, n) == 0)
		return (dst);
	dest = dst;
	sr = src;
	i = 0;
	while ((i < n))
	{
	dest[i] = sr[i];
	i++;
	}
	return (dst);
}
