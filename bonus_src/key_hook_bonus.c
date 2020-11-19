/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 01:10:37 by thor              #+#    #+#             */
/*   Updated: 2020/11/19 12:01:29 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	change_prev(t_data *type)
{
	if (type->key.type == CAMERA_D && type->camera->previous != NULL)
	{
		type->camera = type->camera->previous;
		minirt(type);
	}
	else if (check_objet(type->key.type) &&\
		type->clone.objet->previous != NULL)
	{
		type->clone.objet = type->clone.objet->previous;
		type->key.type = type->clone.objet->type;
	}
	else if (type->key.type == LIGHT_D &&\
			type->clone.light->previous != NULL)
		type->clone.light = type->clone.light->previous;
}

void		change_element(t_data *type)
{
	if (type->key.key == 0)
		change_prev(type);
	else if (type->key.key == 2)
	{
		if (type->key.type == CAMERA_D && type->camera->next != NULL)
		{
			type->camera = type->camera->next;
			minirt(type);
		}
		else if (check_objet(type->key.type) && type->clone.objet->next != NULL)
		{
			type->clone.objet = type->clone.objet->next;
			type->key.type = type->clone.objet->type;
		}
		else if (type->key.type == LIGHT_D && type->clone.light->next != NULL)
			type->clone.light = type->clone.light->next;
	}
}

static void	rot_or_tra(int keycode, t_data *type)
{
	type->key.key = keycode;
	if (type->key.tr_rt == 0 && check_direction(keycode))
	{
		type->key.renitialise = 1;
		translation(type);
		minirt(type);
	}
	if (type->key.tr_rt == 1)
	{
		type->key.renitialise = 1;
		check_xyz(type, keycode);
		if (type->key.rot_xyz != 0 || check_direction(keycode))
		{
			rotation(type);
			minirt(type);
		}
	}
}

int			key_press(int keycode, t_data *type)
{
	if (hook_element(type, keycode))
		type->key.check = 1;
	if ((type->key.check == 1 || type->key.renitialise == 1)\
		&& check_trans_rot(type, keycode))
		type->key.check = 2;
	if (type->key.check == 2)
		rot_or_tra(keycode, type);
	if (keycode == 0 || keycode == 2)
	{
		type->key.key = keycode;
		change_element(type);
	}
	if (keycode == 53)
		free_exit(type, 0);
	mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr,\
		type->mlx.img_ptr, 0, 0);
	return (0);
}

int			ft_close(t_data *type)
{
	(void)type;
	return (free_exit(type, 0));
}
