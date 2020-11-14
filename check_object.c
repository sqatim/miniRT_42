/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:25:00 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/14 13:56:25 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			check_sphere(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, sphere_d, 1));
	if (ft_2strlen(parc) > 4)
	{
		if (ft_2strlen(parc) > 5)
			return (miss_or_out(type, sphere_d, 7));
		if (ft_2strlen(parc) >= 5)
		{
			if (check_pos(parc[4]) == 0)
				return (wrong_trans_rot(type, sphere_d, 1));
			type->tool.tran_rot = 1;
		}
	}
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, sphere_d));
	else if (check_double(parc[2]) == 0 || ft_atod(parc[2]) < 0)
		ft_print_cont(type, "Sphere", sphere_d, 0);
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, sphere_d));
	return (sphere_d);
}

static void	plane(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 6)
		miss_or_out(type, plane_d, 7);
	if (ft_2strlen(parc) >= 5)
	{
		if (check_pos(parc[4]) == 0)
			wrong_trans_rot(type, plane_d, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 6)
	{
		if (check_rotation(parc[5]) == 0)
			wrong_trans_rot(type, plane_d, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_plane(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, plane_d, 1));
	else if (ft_2strlen(parc) > 4)
		plane(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, plane_d));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, plane_d));
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, plane_d));
	return (plane_d);
}

int			check_triangle(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 5)
		return (miss_or_out(type, triangle_d, 1));
	else if (ft_2strlen(parc) > 5)
	{
		if (ft_2strlen(parc) > 6)
			return (miss_or_out(type, triangle_d, 7));
		if (ft_2strlen(parc) >= 6)
		{
			if (check_pos(parc[5]) == 0)
				return (wrong_trans_rot(type, triangle_d, 1));
			type->tool.tran_rot = 1;
		}
	}
	if (check_pos(parc[1]) == 0 || check_pos(parc[2]) == 0\
			|| check_pos(parc[3]) == 0)
		return (wrong_pos(type, triangle_d));
	else if (check_rgb(parc[4]) == 0)
		return (wrong_rgb(type, triangle_d));
	return (triangle_d);
}
