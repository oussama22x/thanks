/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:01:00 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/03 15:23:17 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	ft_free(char **list, int p)
{
	int	i;

	i = 0;
	while (i < p)
		free(list[i++]);
	return ;
}

static void	dupword(char **list, char const *str, char sep)
{
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (*str || (i > 0 && *str == '\0'))
	{
		if (*str != sep && *str != '\0')
			i++;
		else
		{
			list[p] = malloc(sizeof (char) * i + 1);
			if (list[p] == NULL)
				ft_free(list, p);
			if (*str == '\0')
				break ;
			i = 0;
			p++;
			while (*str == sep)
				str++;
			str--;
		}
		str++;
	}
}

static void	cpy(char **list, char const *str, char sep, int i)
{
	int		c;
	int		p;

	if (!str)
		return ;
	p = 0;
	c = 0;
	while (str[i] || (c > 0 && str[i] == '\0'))
	{
		if (str[i] != sep && str[i] != '\0')
			list[p][c++] = str[i];
		else
		{
			list[p++][c] = '\0';
			c = 0;
			if (str[i] == '\0')
				break ;
			while (str[i] == sep)
				i++;
			i--;
		}
		i++;
	}
	list[p] = (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	numword;
	size_t	i;
	char	**wordlist;

	if (!s)
		return ((char **)s);
	numword = count_words(s, c);
	i = 0;
	wordlist = malloc(sizeof(char *) * (numword + 1));
	if (wordlist == NULL)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	dupword(wordlist, s + i, c);
	cpy (wordlist, s + i, c, 0);
	return (wordlist);
}
