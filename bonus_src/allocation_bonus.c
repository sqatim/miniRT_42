/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:57:52 by thor              #+#    #+#             */
/*   Updated: 2020/11/17 12:14:56 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_light		*add_light(t_data *type, t_info object)
{
	t_light *tmp;
	t_light *new_light;

	tmp = type->light;
	if (!(new_light = (t_light *)malloc(sizeof(t_light))))
		free_exit(type, 1);
	new_light->previous = NULL;
	new_light->next = NULL;
	new_light->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_light->int_light = object.int_light;
	new_light->rgb_light = make_range(r_g_b(object.colour[0],
				object.colour[1], object.colour[2]));
	if (type->tool.tran_rot > 0)
	{
		new_light->translation = x_y_z(object.translation[0],
				object.translation[1], object.translation[2]);
		new_light->pos = vector_add(new_light->pos, new_light->translation);
	}
	if (type->light == NULL)
		return (new_light);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_light->previous = tmp;
	tmp->next = new_light;
	return (type->light);
}

static void	trans_rot_c(t_data *type, t_camera *new_camera, t_info object)
{
	if (type->tool.tran_rot > 0)
	{
		new_camera->translation = x_y_z(object.translation[0],
				object.translation[1], object.translation[2]);
		new_camera->pos = vector_add(new_camera->pos, new_camera->translation);
		if (type->tool.tran_rot == 2)
		{
			new_camera->rotation = x_y_z(object.rotation[0],
					object.rotation[1], object.rotation[2]);
			new_camera->ort_vec = rot_vector(new_camera->ort_vec,
					new_camera->rotation);
		}
	}
}

t_camera	*add_camera(t_data *type, t_info object)
{
	t_camera *tmp;
	t_camera *new_camera;

	tmp = type->camera;
	if (!(new_camera = (t_camera *)malloc(sizeof(t_camera))))
		free_exit(type, 1);
	new_camera->previous = NULL;
	new_camera->next = NULL;
	new_camera->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_camera->ort_vec = x_y_z(object.vector[0],
			object.vector[1], object.vector[2]);
	new_camera->fov = object.fov;
	trans_rot_c(type, new_camera, object);
	if (type->camera == NULL)
		return (new_camera);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_camera->previous = tmp;
	tmp->next = new_camera;
	return (type->camera);
}
