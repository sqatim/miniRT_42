/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rcl_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:26:18 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/20 11:59:37 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int			check_resolution(t_data *type, char **parc)
{
	int i;

	i = 0;
	if (ft_2strlen(parc) < 3)
		return (miss_or_out(type, RESOLUTION_D, 1));
	else if (ft_2strlen(parc) > 3)
		return (miss_or_out(type, RESOLUTION_D, 7));
	if (check_numb(parc[1]) == 0 || check_numb(parc[2]) == 0\
			|| ft_atoi(parc[1]) == 0 || ft_atoi(parc[2]) == 0)
	{
		if (check_numb(parc[1]) == 0 || ft_atoi(parc[1]) == 0)
			ft_print_cont(type, "Error\nResolution", RESOLUTION_D, 1);
		else if (check_numb(parc[2]) == 0 || ft_atoi(parc[2]) == 0)
			ft_print_cont(type, "Error\nResolution", RESOLUTION_D, 2);
	}
	if (type->parcing.r == 1)
	{
		write(1, "Error\nYou must declare just one Resolution\n", 37);
		free_exit(type, 1);
	}
	return (RESOLUTION_D);
}

int			check_ambient(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 3)
		return (miss_or_out(type, AMBIENT_D, 1));
	else if (ft_2strlen(parc) > 3)
		return (miss_or_out(type, AMBIENT_D, 7));
	if (check_double(parc[1]) == 0 ||\
			(ft_atod(parc[1]) < 0 || ft_atod(parc[1]) > 1))
		ft_print_cont(type, "Error\nAmbient", AMBIENT_D, 0);
	else if (check_rgb(parc[2]) == 0)
		return (wrong_rgb(type, AMBIENT_D));
	if (type->parcing.a == 1)
		write(1, "Error\nYou must declare just one Ambient\n", 34);
	return (AMBIENT_D);
}

int			check_light(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, LIGHT_D, 1));
	else if (ft_2strlen(parc) > 4)
	{
		if (ft_2strlen(parc) > 5)
			return (miss_or_out(type, LIGHT_D, 7));
		if (ft_2strlen(parc) >= 5)
		{
			if (check_pos(parc[4]) == 0)
				return (wrong_trans_rot(type, LIGHT_D, 1));
			type->tool.tran_rot = 1;
		}
	}
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, LIGHT_D));
	else if (check_double(parc[2]) == 0 ||\
			(ft_atod(parc[2]) < 0 || ft_atod(parc[2]) > 1))
		ft_print_cont(type, "Error\nLight", LIGHT_D, 0);
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, LIGHT_D));
	return (LIGHT_D);
}

static void	camera(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 6)
		miss_or_out(type, CAMERA_D, 7);
	if (ft_2strlen(parc) >= 5)
	{
		if (check_pos(parc[4]) == 0)
			wrong_trans_rot(type, CAMERA_D, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 6)
	{
		if (check_rotation(parc[5]) == 0)
			wrong_trans_rot(type, CAMERA_D, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_camera(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, CAMERA_D, 1));
	else if (ft_2strlen(parc) > 4)
		camera(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, CAMERA_D));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, CAMERA_D));
	else if (check_double(parc[3]) == 0 ||\
			(ft_atod(parc[3]) < 0 || ft_atod(parc[3]) > 180))
		ft_print_cont(type, "Error\nCamera", CAMERA_D, 0);
	return (CAMERA_D);
}
