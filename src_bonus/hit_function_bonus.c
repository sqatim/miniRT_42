/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:52:29 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 14:30:15 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_sphere(t_objet *objet, t_ray *ray)
{
	t_varcal	var;

	var.oc = vector_sub(ray->origin, objet->pos);
	var.a = vector_dot(ray->direction, ray->direction);
	var.b = 2.0 * vector_dot(var.oc, ray->direction);
	var.c = vector_dot(var.oc, var.oc) - (objet->radius * objet->radius);
	var.delta = var.b * var.b - 4 * var.a * var.c;
	if (var.delta < 0)
		return (0);
	var.t1 = (-var.b + sqrt(var.delta)) / (2 * var.a);
	var.t2 = (-var.b - sqrt(var.delta)) / (2 * var.a);
	if (var.t1 < 0)
		return (0);
	if (var.t1 > var.t2)
		return (var.t2);
	else
		return (var.t1);
}

double	hit_plane(t_objet *objet, t_ray *ray)
{
	double		a;
	double		t;
	t_vector	oc;

	a = vector_dot(ray->direction, objet->v);
	if (a != 0.0)
	{
		oc = vector_sub(objet->pos, ray->origin);
		t = vector_dot(oc, objet->v) / a;
		if (t > 0.0)
			return (t);
	}
	return (0);
}

double	hit_square(t_objet *objet, t_ray *ray)
{
	t_vector	produit;
	t_vector	point;
	t_vector	v;
	double		edge;
	t_varcal	var;

	var.a = vector_dot(ray->direction, objet->v);
	if (var.a != 0)
	{
		var.oc = vector_sub(ray->origin, objet->pos);
		var.t = -1 * vector_dot(var.oc, objet->v) / var.a;
		if (var.t > 0)
		{
			produit = vector_scal(var.t, ray->direction);
			point = vector_add(ray->origin, produit);
			v = vector_sub(point, objet->pos);
			edge = objet->height / 2;
			if (fabs(v.x) > edge || fabs(v.y) > edge || fabs(v.z) > edge)
				return (0);
			return (var.t);
		}
	}
	return (0);
}

double	hit_cylinder(t_objet *objet, t_ray *ray)
{
	t_varcal	var;
	double		m1;
	double		m2;

	calcul_delta_cy(objet, ray, &var);
	if (var.delta < 0)
		return (0);
	var.t1 = (-var.b + sqrt(var.delta)) / (2 * var.a);
	var.t2 = (-var.b - sqrt(var.delta)) / (2 * var.a);
	if (var.t1 < 0)
		return (0);
	m1 = vector_dot(ray->direction, objet->v) * \
		var.t2 + vector_dot(var.oc, objet->v);
	m2 = vector_dot(ray->direction, objet->v) *\
		var.t1 + vector_dot(var.oc, objet->v);
	if (m1 >= 0 && m1 <= objet->height)
		return (var.t2);
	else if (m2 >= 0 && m2 <= objet->height)
		return (var.t1);
	return (0);
}

double	hit_triangle(t_objet *objet, t_ray *ray)
{
	t_vector	h;
	t_vector	q;
	double		u;
	double		v;
	t_varcal	var;

	var.edge1 = vector_sub(objet->pos1, objet->pos);
	var.edge2 = vector_sub(objet->pos2, objet->pos);
	h = vector_cross(ray->direction, var.edge2);
	var.a = vector_dot(var.edge1, h);
	if (var.a > -0.0000001 && var.a < 0.0000001)
		return (0);
	var.b = 1.0 / var.a;
	u = var.b * vector_dot(vector_sub(ray->origin, objet->pos), h);
	if (u < 0.0 || u > 1.0)
		return (0);
	q = vector_cross(vector_sub(ray->origin, objet->pos), var.edge1);
	v = var.b * vector_dot(ray->direction, q);
	if (v < 0.0 || u + v > 1.0)
		return (0);
	var.t = var.b * vector_dot(var.edge2, q);
	if (var.t > 0.0000001)
		return (var.t);
	else
		return (0);
}
