/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:25:00 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/20 12:01:44 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int			check_sphere(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, SPHERE_D, 1));
	if (ft_2strlen(parc) > 4)
	{
		if (ft_2strlen(parc) > 5)
			return (miss_or_out(type, SPHERE_D, 7));
		if (ft_2strlen(parc) >= 5)
		{
			if (check_pos(parc[4]) == 0)
				return (wrong_trans_rot(type, SPHERE_D, 1));
			type->tool.tran_rot = 1;
		}
	}
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, SPHERE_D));
	else if (check_double(parc[2]) == 0 || ft_atod(parc[2]) < 0)
		ft_print_cont(type, "Error\nSphere", SPHERE_D, 0);
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, SPHERE_D));
	return (SPHERE_D);
}

static void	plane(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 6)
		miss_or_out(type, PLANE_D, 7);
	if (ft_2strlen(parc) >= 5)
	{
		if (check_pos(parc[4]) == 0)
			wrong_trans_rot(type, PLANE_D, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 6)
	{
		if (check_rotation(parc[5]) == 0)
			wrong_trans_rot(type, PLANE_D, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_plane(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, PLANE_D, 1));
	else if (ft_2strlen(parc) > 4)
		plane(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, PLANE_D));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, PLANE_D));
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, PLANE_D));
	return (PLANE_D);
}

int			check_triangle(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 5)
		return (miss_or_out(type, TRIANGLE_D, 1));
	else if (ft_2strlen(parc) > 5)
	{
		if (ft_2strlen(parc) > 6)
			return (miss_or_out(type, TRIANGLE_D, 7));
		if (ft_2strlen(parc) >= 6)
		{
			if (check_pos(parc[5]) == 0)
				return (wrong_trans_rot(type, TRIANGLE_D, 1));
			type->tool.tran_rot = 1;
		}
	}
	if (check_pos(parc[1]) == 0 || check_pos(parc[2]) == 0\
			|| check_pos(parc[3]) == 0)
		return (wrong_pos(type, TRIANGLE_D));
	else if (check_rgb(parc[4]) == 0)
		return (wrong_rgb(type, TRIANGLE_D));
	return (TRIANGLE_D);
}
