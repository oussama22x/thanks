/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:28:36 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/03 17:28:09 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
	{
		new = malloc(sizeof(char) * ft_strlen(s + start) + 1);
		if (!new)
			return (NULL);
	}
	else
	{
		new = malloc(sizeof(char) * len + 1);
		if (!new)
			return (NULL);
	}
	while (s[start] && i < len && ft_strlen(s) > start)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
