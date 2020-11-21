/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:52:14 by thor              #+#    #+#             */
/*   Updated: 2020/11/21 17:13:24 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		half_w_h(t_data *type)
{
	double theta;
	double ratio;

	theta = -1 * type->camera->fov * PI / 180;
	if (type->rsl.width >= type->rsl.height)
	{
		ratio = type->rsl.width / type->rsl.height;
		type->rsl.half_height = 2 * tan(theta / 2);
		type->rsl.half_width = ratio * 2 * tan(theta / 2);
	}
	else
	{
		ratio = type->rsl.height / type->rsl.width;
		type->rsl.half_height = ratio * 2 * (tan(theta / 2));
		type->rsl.half_width = 2 * tan(theta / 2);
	}
}

t_vector	calcul_pixel(t_data *type, t_vector left_corner,\
			t_vector u, t_vector v)
{
	double		x;
	double		y;
	t_vector	pixel_x;
	t_vector	pixel_y;
	t_vector	pixel;

	x = type->rsl.x * type->rsl.half_width / type->rsl.width;
	y = type->rsl.y * type->rsl.half_height / type->rsl.height;
	pixel_x = vector_scal(x, u);
	pixel_y = vector_scal(y, v);
	pixel = vector_add(pixel_x, pixel_y);
	pixel = vector_add(left_corner, pixel);
	return (pixel);
}

t_vector	mapper_pixel(t_data *type, t_vector u, t_vector v, t_vector n)
{
	t_vector center;
	t_vector l;
	t_vector left_corner;

	center = vector_sub(type->camera->pos, n);
	l.x = u.x * type->rsl.half_width / 2 + v.x * type->rsl.half_height / 2;
	l.y = u.y * type->rsl.half_width / 2 + v.y * type->rsl.half_height / 2;
	l.z = u.z * type->rsl.half_width / 2 + v.z * type->rsl.half_height / 2;
	left_corner = vector_sub(center, l);
	return (calcul_pixel(type, left_corner, u, v));
}

void		camera_setting(t_data *type)
{
	t_vector u;
	t_vector v;
	t_vector vup;
	t_vector n;

	vup = make_pos(0, 1, 0);
	if (type->camera->ort_vec.y != 0 && (type->camera->ort_vec.z == 0 &&\
		type->camera->ort_vec.x == 0))
		vup = make_pos(0, 0, 1);
	n = vector_scal(-1, type->camera->ort_vec);
	n = unit_vector(n);
	u = vector_cross(vup, n);
	u = unit_vector(u);
	v = vector_cross(n, u);
	half_w_h(type);
	type->camera->pixel = mapper_pixel(type, u, v, n);
}

void		ray(t_data *type)
{
	type->ray.origin = type->camera->pos;
	type->ray.direction = vector_sub(type->camera->pixel, type->ray.origin);
	type->ray.direction = unit_vector(type->ray.direction);
}
