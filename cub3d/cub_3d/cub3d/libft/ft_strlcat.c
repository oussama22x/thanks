/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:58:10 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/03 16:31:57 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	t;
	size_t	x;
	size_t	z;

	i = 0;
	t = 0;
	z = 0;
	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	while (dest[t])
		t++;
	x = t;
	while (src[i])
		i++;
	if (x >= size)
		return (i + size);
	while (src[z] && z < (size - x - 1))
	{
		dest[t] = src[z];
		z++;
		t++;
	}
	dest[t] = 0;
	return (i + x);
}
