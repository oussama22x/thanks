/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:04:31 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/01 20:03:18 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	len_cpy(const char *s1, char *new, int x)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		new[x] = s1[i];
		i++;
		x++;
	}
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	char	*new;
	int		aloc;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	i = 0;
	x = 0;
	i = count(s1);
	x = count(s2);
	aloc = (i + x);
	new = malloc(sizeof(char) * (aloc) + 1);
	if (!new)
		return (NULL);
	i = 0;
	i = len_cpy (s1, new, i);
	i = len_cpy (s2, new, i);
	new[i] = 0;
	return (new);
}
