/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_split_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:58:00 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/17 12:14:56 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static int		words(char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			i++;
			j++;
		}
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (j);
}

static void		*leak(char **spl, int j)
{
	j = j - 1;
	while (spl[j])
	{
		free(spl[j]);
		j--;
	}
	free(spl);
	return (NULL);
}

static int		carcts(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		i++;
	}
	return (i);
}

static char		*alloc(char **tab, char *src)
{
	int			i;
	int			j;
	int			o;

	j = 0;
	o = 0;
	while (src[o] == ' ' || src[o] == '\t')
		o++;
	while (j < words(src))
	{
		i = 0;
		if (!(tab[j] = malloc(sizeof(char) * (carcts(&src[o]) + 1))))
			return (leak(tab, j));
		while ((src[o] != '\t' && src[o] != ' ') && src[o])
		{
			tab[j][i++] = src[o++];
		}
		tab[j][i] = '\0';
		while ((src[o] == '\t' || src[o] == ' ') && src[o])
			o++;
		j++;
	}
	tab[j] = NULL;
	return (*tab);
}

char			**ft_space_split(char const *s)
{
	int			i;
	int			j;
	int			o;
	char		**tab;
	char		*str;

	o = 0;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	tab = malloc(sizeof(char *) * (words(str) + 1));
	if (!tab)
		return (NULL);
	tab[j] = alloc(tab, str);
	return (tab);
}
