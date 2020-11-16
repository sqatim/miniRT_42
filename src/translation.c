/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:07:00 by thor              #+#    #+#             */
/*   Updated: 2020/11/16 11:04:39 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	translation_r_l(t_data *type)
{
	double pos;

	pos = 0.03;
	if (type->key.key == right)
	{
		if (type->key.type == CAMERA_D)
			type->clone.camera->pos.x += pos;
		else if (type->key.type == type->clone.objet->type)
			transl_objet_x(type, pos, 0);
		else if (type->key.type == LIGHT_D)
			type->clone.light->pos.x += pos;
	}
	if (type->key.key == left)
	{
		if (type->key.type == CAMERA_D)
			type->clone.camera->pos.x -= pos;
		else if (type->key.type == type->clone.objet->type)
			transl_objet_x(type, pos, 1);
		else if (type->key.type == LIGHT_D)
			type->clone.light->pos.x -= pos;
	}
}

void	translation_u_d(t_data *type)
{
	double pos;

	pos = 0.03;
	if (type->key.key == up)
	{
		if (type->key.type == CAMERA_D)
			type->clone.camera->pos.y += pos;
		else if (type->key.type == type->clone.objet->type)
			transl_objet_y(type, pos, 0);
		else if (type->key.type == LIGHT_D)
			type->clone.light->pos.y += pos;
	}
	if (type->key.key == down)
	{
		if (type->key.type == CAMERA_D)
			type->clone.camera->pos.y -= pos;
		else if (type->key.type == type->clone.objet->type)
			transl_objet_y(type, pos, 1);
		else if (type->key.type == LIGHT_D)
			type->clone.light->pos.y -= pos;
	}
}

void	translation_a_b(t_data *type)
{
	double pos;

	pos = 0.03;
	if (type->key.key == ahead)
	{
		if (type->key.type == CAMERA_D)
			type->clone.camera->pos.z += pos;
		else if (type->key.type == type->clone.objet->type)
			transl_objet_z(type, pos, 0);
		else if (type->key.type == LIGHT_D)
			type->clone.light->pos.z += pos;
	}
	if (type->key.key == back)
	{
		if (type->key.type == CAMERA_D)
			type->clone.camera->pos.z -= pos;
		else if (type->key.type == type->clone.objet->type)
			transl_objet_z(type, pos, 1);
		else if (type->key.type == LIGHT_D)
			type->clone.light->pos.z -= pos;
	}
}

void	translation(t_data *type)
{
	if (type->key.key == right || type->key.key == left)
		translation_r_l(type);
	if (type->key.key == up || type->key.key == down)
		translation_u_d(type);
	if (type->key.key == ahead || type->key.key == back)
		translation_a_b(type);
}
