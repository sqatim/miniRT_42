/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_objet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:28:40 by thor              #+#    #+#             */
/*   Updated: 2020/11/16 13:56:30 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	trans_rot(t_data *type, t_objet *new_object, t_info object)
{
	if (type->tool.tran_rot > 0)
	{
		new_object->translation = x_y_z(object.translation[0],\
					object.translation[1], object.translation[2]);
		new_object->pos = vector_add(new_object->pos, new_object->translation);
		if (type->tool.tran_rot == 2)
		{
			new_object->rotation = x_y_z(object.rotation[0],\
					object.rotation[1], object.rotation[2]);
			new_object->v = rot_vector(new_object->v, new_object->rotation);
		}
	}
}

t_objet	*add_sphere(t_data *type, t_info object)
{
	t_objet *tmp;
	t_objet *new_sphere;

	tmp = type->objet;
	if (!(new_sphere = (t_objet *)malloc(sizeof(t_objet))))
		free_exit(type, 1);
	new_sphere->previous = NULL;
	new_sphere->next = NULL;
	new_sphere->type = SPHERE_D;
	new_sphere->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_sphere->colour = make_range(r_g_b(object.colour[0],\
				object.colour[1], object.colour[2]));
	trans_rot(type, new_sphere, object);
	new_sphere->radius = object.radius / 2;
	new_sphere->i = type->tool.index;
	type->tool.index++;
	if (type->objet == NULL)
		return (new_sphere);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_sphere->previous = tmp;
	tmp->next = new_sphere;
	return (type->objet);
}

t_objet	*add_plane(t_data *type, t_info object)
{
	t_objet *tmp;
	t_objet *new_plane;

	tmp = type->objet;
	if (!(new_plane = (t_objet *)malloc(sizeof(t_objet))))
		free_exit(type, 1);
	new_plane->previous = NULL;
	new_plane->next = NULL;
	new_plane->type = PLANE_D;
	new_plane->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_plane->v = x_y_z(object.vector[0], object.vector[1], object.vector[2]);
	new_plane->v = unit_vector(new_plane->v);
	new_plane->colour = make_range(r_g_b(object.colour[0],\
				object.colour[1], object.colour[2]));
	trans_rot(type, new_plane, object);
	new_plane->i = type->tool.index;
	type->tool.index++;
	if (type->objet == NULL)
		return (new_plane);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_plane->previous = tmp;
	tmp->next = new_plane;
	return (type->objet);
}

t_objet	*add_square(t_data *type, t_info object)
{
	t_objet *tmp;
	t_objet *new_square;

	tmp = type->objet;
	if (!(new_square = (t_objet *)malloc(sizeof(t_objet))))
		free_exit(type, 1);
	new_square->previous = NULL;
	new_square->next = NULL;
	new_square->type = SQUARE_D;
	new_square->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_square->v = x_y_z(object.vector[0], object.vector[1], object.vector[2]);
	new_square->v = unit_vector(new_square->v);
	new_square->colour = make_range(r_g_b(object.colour[0],\
				object.colour[1], object.colour[2]));
	new_square->height = object.height;
	trans_rot(type, new_square, object);
	new_square->i = type->tool.index;
	type->tool.index++;
	if (type->objet == NULL)
		return (new_square);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_square->previous = tmp;
	tmp->next = new_square;
	return (type->objet);
}
