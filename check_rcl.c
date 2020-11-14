/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rcl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:26:18 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/14 14:08:09 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			check_resolution(t_data *type, char **parc)
{
	int i;

	i = 0;
	if (ft_2strlen(parc) < 3)
		return (miss_or_out(type, resolution_d, 1));
	else if (ft_2strlen(parc) > 3)
		return (miss_or_out(type, resolution_d, 7));
	if (check_numb(parc[1]) == 0 || check_numb(parc[2]) == 0\
			|| ft_atoi(parc[1]) == 0 || ft_atoi(parc[2]) == 0)
	{
		if (check_numb(parc[1]) == 0 || ft_atoi(parc[1]) == 0)
			ft_print_cont(type, "Resolution", resolution_d, 1);
		else if (check_numb(parc[2]) == 0 || ft_atoi(parc[2]) == 0)
			ft_print_cont(type, "Resolution", resolution_d, 2);
	}
	if (type->parcing.r == 1)
	{
		write(1, "You must declare just one Resolution\n", 37);
		free_exit(type, 1);
	}
	return (resolution_d);
}

int			check_ambient(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 3)
		return (miss_or_out(type, ambient_d, 1));
	else if (ft_2strlen(parc) > 3)
		return (miss_or_out(type, ambient_d, 7));
	if (check_double(parc[1]) == 0 ||\
			(ft_atod(parc[1]) < 0 || ft_atod(parc[1]) > 1))
		ft_print_cont(type, "Ambient", ambient_d, 0);
	else if (check_rgb(parc[2]) == 0)
		return (wrong_rgb(type, ambient_d));
	if (type->parcing.a == 1)
		write(1, "You must declare just one Ambient\n", 34);
	return (ambient_d);
}

int			check_light(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, light_d, 1));
	else if (ft_2strlen(parc) > 4)
	{
		if (ft_2strlen(parc) == 5)
		{
			if (check_pos(parc[4]) == 0)
				return (wrong_trans_rot(type, light_d, 1));
			type->tool.tran_rot = 1;
		}
		else if (ft_2strlen(parc) > 5)
			return (miss_or_out(type, light_d, 7));
	}
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, light_d));
	else if (check_double(parc[2]) == 0 ||\
			(ft_atod(parc[2]) < 0 || ft_atod(parc[2]) > 1))
		ft_print_cont(type, "Light", light_d, 0);
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, light_d));
	return (light_d);
}

static void	camera(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 6)
		miss_or_out(type, camera_d, 7);
	if (ft_2strlen(parc) >= 5)
	{
		if (check_pos(parc[4]) == 0)
			wrong_trans_rot(type, camera_d, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 6)
	{
		if (check_rotation(parc[5]) == 0)
			wrong_trans_rot(type, camera_d, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_camera(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, camera_d, 1));
	else if (ft_2strlen(parc) > 4)
		camera(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, camera_d));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, camera_d));
	else if (check_double(parc[3]) == 0 ||\
			(ft_atod(parc[3]) < 0 || ft_atod(parc[3]) > 180))
		ft_print_cont(type, "Camera", camera_d, 0);
	return (camera_d);
}
