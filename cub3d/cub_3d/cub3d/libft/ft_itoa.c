/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:59:56 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/01 10:20:25 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_str(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_revstr(char *tab, int size)
{
	char	c;
	int		i;
	int		x;

	x = size;
	size--;
	i = 0;
	c = 0;
	while (i < (x / 2))
	{
		c = tab[size];
		tab[size] = tab[i];
		tab[i] = c;
		i++;
		size--;
	}
}

static char	*ft_putnbr(int nb)
{
	int		len;
	char	*digstr;

	digstr = NULL;
	if (nb >= 0)
	{
		len = len_str(nb);
		if (len == 0 && nb == 0)
			len++;
		digstr = malloc(sizeof(char ) * len + 1);
		if (!digstr)
			return (0);
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		len = len_str(nb);
		digstr = malloc(sizeof(char) * len + 2);
		if (!digstr)
			return (NULL);
		digstr[len] = '-';
	}
	return (digstr);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*digstr;

	i = 0;
	digstr = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digstr = ft_putnbr(n);
	if (!digstr)
		return (NULL);
	if (n < 0)
		n *= -1;
	while (n >= 0)
	{
		digstr[i++] = (n % 10) + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (digstr[i] == '-')
		digstr[i + 1] = '\0';
	else
		digstr[i] = '\0';
	ft_revstr(digstr, ft_strlen(digstr));
	return (digstr);
}
