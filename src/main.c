/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:22:20 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 11:06:15 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minirt.h"
#include "mlx.h"

static int check_objet(int type)
{
	if (type == SPHERE_D || type == PLANE_D || type == SQUARE_D || type == CYLINDER_D || type == TRIANGLE_D)
		return (1);
	return (0);
}

static void check_xyz(t_data *type, int key)
{
	if (key == 7)
		type->key.rot_xyz = 1;
	else if (key == 16)
		type->key.rot_xyz = 2;
	else if (key == 6)
		type->key.rot_xyz = 3;
}

int check_trans_rot(t_data *type, int key)
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
int check_direction(t_data *type, int key)
{
	if (key == right)
		return (1);
	if (key == left)
		return (1);
	if (key == up)
		return (1);
	if (key == down)
		return (1);
	if (key == back)
		return (1);
	if (key == ahead)
		return (1);
	return (0);
}

void change_element(t_data *type)
{
	if (type->key.key == 0)
	{
		if (type->key.type == CAMERA_D && type->camera->previous != NULL)
			type->camera = type->camera->previous;
		else if (check_objet(type->key.type) && type->clone.objet->previous != NULL)
		{
			type->clone.objet = type->clone.objet->previous;
			type->key.type = type->clone.objet->type;
		}
		else if (type->key.type == LIGHT_D && type->clone.light->previous != NULL)
			type->clone.light = type->clone.light->previous;
	}
	else if (type->key.key == 2)
	{
		if (type->key.type == CAMERA_D && type->camera->next != NULL)
			type->camera = type->camera->next;
		else if (check_objet(type->key.type) && type->clone.objet->next != NULL)
		{
			type->clone.objet = type->clone.objet->next;
			type->key.type = type->clone.objet->type;
		}
		else if (type->key.type == LIGHT_D && type->clone.light->next != NULL)
			type->clone.light = type->clone.light->next;
	}
}

int hook_element(t_data *type, int key)
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

int key_press(int keycode, t_data *type)
{

	if (hook_element(type, keycode))
		type->key.check = 1;
	if ((type->key.check == 1 || type->key.renitialise == 1) && check_trans_rot(type, keycode))
		type->key.check = 2;
	if (type->key.check == 2)
	{
		type->key.key = keycode;
		if (type->key.tr_rt == 0 && check_direction(type, keycode))
		{
			type->key.renitialise = 1;
			translation(type);
			minirt(type);
		}
		if (type->key.tr_rt == 1)
		{
			type->key.renitialise = 1;
			check_xyz(type, keycode);
			if (type->key.rot_xyz != 0 || check_direction(type, keycode))
			{
				rotation(type);
				minirt(type);
			}
		}
	}
	if (keycode == 0 || keycode == 2)
	{
		type->key.key = keycode;
		change_element(type);
	}
	if (keycode == 53)
		free_exit(type,0);
	mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr, type->mlx.img_ptr, 0, 0);

	return (0);
}

int ft_close(t_data *type)
{
	(void)type;
	return(free_exit(type,0));
}
void ft_mlx(t_data *type, int wich)
{
	int bpp;
	int size_line;
	int endian;

	if (wich == 1)
	{
		type->mlx.mlx_ptr = mlx_init();
		type->mlx.img_ptr = mlx_new_image(type->mlx.mlx_ptr, type->rsl.width, type->rsl.height);
		type->mlx.img_data = (int *)mlx_get_data_addr(type->mlx.img_ptr, &type->mlx.bpp, &type->mlx.size_line, &endian);
	}
	else if (wich == 2)
	{
		type->mlx.win_ptr = mlx_new_window(type->mlx.mlx_ptr, type->rsl.width, type->rsl.height, "miniRT");
		mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr, type->mlx.img_ptr, 0, 0);
		mlx_hook(type->mlx.win_ptr, 2, 0, key_press, type);
		mlx_hook(type->mlx.win_ptr, 17, 0, ft_close, type);
		mlx_loop(type->mlx.mlx_ptr);
	}
}

void clone(t_data *type)
{
	type->clone.objet = type->objet;
	type->clone.camera = type->camera;
	type->clone.light = type->light;
}

int main(int ac, char **av)
{
	t_data type;

	ft_bzero(&type, sizeof(t_data));
	parcing(&type, av, ac);
	clone(&type);
	ft_mlx(&type, 1);
	minirt(&type);
	if (type.tool.bmp == 1)
		create_bmp(&type);
	else
		ft_mlx(&type, 2);
	return (0);
}
