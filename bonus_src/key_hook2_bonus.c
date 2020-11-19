/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:50:04 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/19 11:52:25 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int		check_objet(int type)
{
	if (type == SPHERE_D || type == PLANE_D || type == SQUARE_D ||\
			type == CYLINDER_D || type == TRIANGLE_D)
		return (1);
	return (0);
}

void	check_xyz(t_data *type, int key)
{
	if (key == 7)
		type->key.rot_xyz = 1;
	else if (key == 16)
		type->key.rot_xyz = 2;
	else if (key == 6)
		type->key.rot_xyz = 3;
}

int		check_trans_rot(t_data *type, int key)
{
	if (key == 17)
	{
		type->key.tr_rt = 0;
		return (1);
	}
	else if (key == 15)
	{
		type->key.tr_rt = 1;
		return (1);
	}
	return (0);
}

int		check_direction(int key)
{
	if (key == RIGHT)
		return (1);
	if (key == LEFT)
		return (1);
	if (key == UP)
		return (1);
	if (key == DOWN)
		return (1);
	if (key == BACK)
		return (1);
	if (key == AHEAD)
		return (1);
	return (0);
}

int		hook_element(t_data *type, int key)
{
	if (key == 31)
	{
		type->key.type = type->clone.objet->type;
		return (1);
	}
	if (key == 8)
	{
		type->key.type = CAMERA_D;
		return (1);
	}
	if (key == 37)
	{
		type->key.type = LIGHT_D;
		return (1);
	}
	return (0);
}
