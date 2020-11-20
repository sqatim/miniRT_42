/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:11:39 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/20 13:03:36 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_double(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	if (str[0] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1 && str[i] != '.')
			return (0);
		if (str[i] == '.')
		{
			if (check == 1)
				return (0);
			check = 1;
		}
		i++;
	}
	return (1);
}

int	check_rotation(char *parc)
{
	int		check;
	char	**rot;

	rot = ft_split(parc, ',');
	if (ft_2strlen(rot) != 3)
		return (0);
	if ((check = check_double(rot[0])) == 0 ||\
			(ft_atod(rot[0]) < -360 || ft_atod(rot[0]) > 360))
		return (0);
	if ((check = check_double(rot[1])) == 0 ||\
			(ft_atod(rot[1]) < -360 || ft_atod(rot[1]) > 360))
		return (0);
	if ((check = check_double(rot[2])) == 0 ||\
			(ft_atod(rot[2]) < -360 || ft_atod(rot[2]) > 360))
		return (0);
	return (1);
}

int	check_rgb(char *parc)
{
	char	**rgb;
	int		check;

	rgb = ft_split(parc, ',');
	if (ft_2strlen(rgb) != 3)
		return (0);
	if ((check = check_double(rgb[0])) == 0 ||\
			(ft_atod(rgb[0]) < 0.0 || ft_atod(rgb[0]) > 255.0))
		return (0);
	if ((check = check_double(rgb[1])) == 0 ||\
			(ft_atod(rgb[1]) < 0.0 || ft_atod(rgb[1]) > 255.0))
		return (0);
	if ((check = check_double(rgb[2])) == 0 ||\
			(ft_atod(rgb[2]) < 0.0 || ft_atod(rgb[2]) > 255.0))
		return (0);
	return (1);
}

int	check_pos(char *parc)
{
	char **pos;

	pos = ft_split(parc, ',');
	if (ft_2strlen(pos) != 3)
		return (0);
	if (check_double(pos[0]) == 0 ||\
			check_double(pos[1]) == 0 || check_double(pos[2]) == 0)
		return (0);
	return (1);
}

int	check_vec_ort(char *parc)
{
	int		check;
	char	**vec_ort;

	vec_ort = ft_split(parc, ',');
	if (ft_2strlen(vec_ort) != 3)
		return (0);
	if ((check = check_double(vec_ort[0])) == 0 ||\
			(ft_atod(vec_ort[0]) < -1.0 || ft_atod(vec_ort[0]) > 1.0))
		return (0);
	if ((check = check_double(vec_ort[1])) == 0 ||\
			(ft_atod(vec_ort[1]) < -1.0 || ft_atod(vec_ort[1]) > 1.0))
		return (0);
	if ((check = check_double(vec_ort[2])) == 0 ||\
			(ft_atod(vec_ort[2]) < -1.0 || ft_atod(vec_ort[2]) > 1.0))
		return (0);
	return (1);
}
