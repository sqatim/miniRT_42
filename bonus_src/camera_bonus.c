/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:52:14 by thor              #+#    #+#             */
/*   Updated: 2020/11/23 14:47:08 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void		half_w_h(t_data *type)
{
	double theta;
	double ratio;

	theta = type->camera->fov * M_PI / 180;
	ratio = (double)type->rsl.width / (double)type->rsl.height;
	type->rsl.half_height = 2 * tan(theta / 2);
	type->rsl.half_width = ratio * type->rsl.half_height;
}

void		calcul_pixel(t_data *type)
{
	double		x;
	double		y;
	t_vector	pixel_x;
	t_vector	pixel_y;
	t_vector	pixel;

	x = (type->rsl.x + 0.5) * type->rsl.half_width / (double)type->rsl.width;
	y = (type->rsl.y + 0.5) * type->rsl.half_height / (double)type->rsl.height;
	pixel_x = vector_scal(x, type->camera->u);
	pixel_y = vector_scal(y, type->camera->v);
	pixel = vector_add(pixel_x, pixel_y);
	pixel = vector_sub(type->camera->l, pixel);
	type->camera->pixel = pixel;
}

void		mapper_pixel(t_data *type)
{
	t_vector center;
	t_vector l;

	center = vector_sub(type->camera->pos, type->camera->n);
	l.x = type->camera->u.x * type->rsl.half_width / 2\
		+ type->camera->v.x * type->rsl.half_height / 2;
	l.y = type->camera->u.y * type->rsl.half_width / 2\
		+ type->camera->v.y * type->rsl.half_height / 2;
	l.z = type->camera->u.z * type->rsl.half_width / 2\
		+ type->camera->v.z * type->rsl.half_height / 2;
	type->camera->l = vector_add(center, l);
}

void		camera_setting(t_data *type)
{
	t_vector vup;

	vup = make_pos(0, 1, 0);
	if (type->camera->ort_vec.y != 0 && (type->camera->ort_vec.z == 0 &&\
		type->camera->ort_vec.x == 0))
		vup = make_pos(0, 0, 1);
	half_w_h(type);
	type->camera->n = vector_scal(-1, type->camera->ort_vec);
	type->camera->n = unit_vector(type->camera->n);
	type->camera->u = vector_cross(vup, type->camera->n);
	type->camera->u = unit_vector(type->camera->u);
	type->camera->v = vector_cross(type->camera->n, type->camera->u);
	mapper_pixel(type);
}

void		ray(t_data *type)
{
	calcul_pixel(type);
	type->ray.origin = type->camera->pos;
	type->ray.direction = vector_sub(type->camera->pixel, type->ray.origin);
	type->ray.direction = unit_vector(type->ray.direction);
}
