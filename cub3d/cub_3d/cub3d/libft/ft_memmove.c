/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:48:54 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/03 13:38:54 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*srcc;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	i = 0;
	dest = (char *) dst;
	srcc = (char *) src;
	if (src < dst)
	{
		while (len--)
		dest[len] = srcc[len];
	}
	else
	{
		while (i < len)
		{
			dest[i] = srcc[i];
			i++;
		}
	}
	return (dst);
}
