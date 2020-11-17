/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:59:19 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/17 12:14:56 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int				check_numb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

static double	to_double(const char *str, int i, int signe, double resultat)
{
	double sub;
	double dix;
	double div;

	dix = 10;
	div = 0;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sub = str[i] - '0';
		div = div + sub / dix;
		dix *= 10;
		i++;
	}
	return ((div + resultat) * signe);
}

double			ft_atod(const char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' ||\
			str[i] == '\n' || str[i] == '\v' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		return (to_double(str, i, sign, result));
	else
		return (result * sign);
}

int				ft_2strlen(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

t_colour		r_g_b(char *r, char *g, char *b)
{
	t_colour extr;

	extr.r = ft_atod(r);
	extr.g = ft_atod(g);
	extr.b = ft_atod(b);
	return (extr);
}
