/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:16:55 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/04 14:36:33 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	just_calcul(t_data *type, double has_inter)
{
	t_objet *tmp;

	while (type->objet->i != type->tool.index)
		type->objet = type->objet->next;
	if (type->objet->type == sphere_d)
		sphere_p_n(type, has_inter);
	else if (type->objet->type == plane_d)
		plane_p_n(type, has_inter);
	else if (type->objet->type == square_d)
		square_p_n(type, has_inter);
	else if (type->objet->type == cylinder_d)
		cylinder_p_n(type, has_inter);
	else if (type->objet->type == triangle_d)
		triangle_p_n(type, has_inter);
}

double	hit_sphere(t_objet *objet, t_ray *ray)
{
	t_varCal var;

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
	double		b;
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
	t_varCal	var;

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

void	calcul_delta_cy(t_objet *objet, t_ray *ray, t_varCal *var)
{
	var->oc = vector_sub(ray->origin, objet->pos);
	var->a = vector_dot(ray->direction, ray->direction) -\
	(vector_dot(ray->direction, objet->v)\
	* vector_dot(ray->direction, objet->v));
	var->b = 2 * (vector_dot(ray->direction, var->oc) -\
	(vector_dot(ray->direction, objet->v) *\
	vector_dot(var->oc, objet->v)));
	var->c = vector_dot(var->oc, var->oc)\
	- (vector_dot(var->oc, objet->v) * vector_dot(var->oc, objet->v))\
	- (objet->radius * objet->radius);
	var->delta = var->b * var->b - 4 * var->a * var->c;
}

double	hit_cylinder(t_objet *objet, t_ray *ray)
{
	t_varCal	var;
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
	t_varCal	var;

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

void witch_object(t_objet *objet, t_ray *ray, double *has_inter)
{
	if (objet->type == sphere_d)
		*has_inter = hit_sphere(objet, ray);
	else if (objet->type == plane_d)
		*has_inter = hit_plane(objet, ray);
	else if (objet->type == square_d)
		*has_inter = hit_square(objet, ray);
	else if (objet->type == cylinder_d)
		*has_inter = hit_cylinder(objet, ray);
	else if (objet->type == triangle_d)
		*has_inter = hit_triangle(objet, ray);
}

int		hit_objet2(t_data *type, t_ray *ombre, t_objet *tmp)
{
	double has_inter;
	t_objet *temporaire;
	int i;
	double d_light;

	temporaire = tmp;
	has_inter = 0;
	d_light = vector_dot(type->objet->light, type->objet->light);
	i = 0;
	while (temporaire != NULL)
	{
		if (i == type->objet->i)
			temporaire = temporaire->next;
		if (temporaire != NULL)
		{
			witch_object(temporaire, ombre, &has_inter);
			i++;
			if (has_inter > 0 && has_inter * has_inter < d_light)
			{
				if (type->tool.shad == 0)
					return (0);
				return (1);
			}
			temporaire = temporaire->next;
		}
	}
	type->tool.shad = 0;
	return (0);
}

void	hit_objet(t_data *type, double *t1)
{
	double has_inter;
	t_objet *tmp;
	t_ray *ray;

	ray = &type->ray;
	type->tool.type = 0;
	tmp = type->objet;
	type->tool.intersect = 0;
	has_inter = 0;
	while (type->objet != NULL)
	{
		witch_object(type->objet, ray, &has_inter);
		if (has_inter > 0 && has_inter < *t1)
		{
			type->tool.type = type->objet->type;
			*t1 = has_inter;
			type->tool.index = type->objet->i;
			type->objet->t = has_inter;
			type->tool.intersect = 1;
		}
		type->objet = type->objet->next;
	}
	type->objet = tmp;
	if (type->tool.intersect == 1)
		just_calcul(type, has_inter);
}
