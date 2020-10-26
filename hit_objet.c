/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:16:55 by sqatim            #+#    #+#             */
/*   Updated: 2020/10/22 12:03:06 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void just_calcul(t_data *type, double has_inter)
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

double hit_sphere(t_objet *objet, t_ray *ray)
{
	double a;
	double b;
	double c;
	double t;
	double discriminant;
	double t1;
	double t2;

	t_vector oc = {ray->origin.x - objet->pos.x, ray->origin.y - objet->pos.y, ray->origin.z - objet->pos.z};
	a = vector_dot(ray->direction, ray->direction);
	b = 2.0 * vector_dot(oc, ray->direction);
	c = vector_dot(oc, oc) - (objet->radius * objet->radius);
	discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
		return (0);

	t1 = (-b + sqrt(discriminant)) / (2 * a);
	t2 = (-b - sqrt(discriminant)) / (2 * a);
	if (t1 < 0)
		return (0);

	if (t1 > t2)
		t = t2;
	else
		t = t1;

	return t;
}

double hit_plane(t_objet *objet, t_ray *ray)
{
	double a;
	double b;
	double t;
	t_vector oc;

	a = vector_dot(ray->direction, objet->v);
	if (a != 0.0)
	{
		oc = vector_sub(objet->pos, ray->origin);
		t = vector_dot(oc, objet->v) / a;
		if (t > 0.0)
			return (t);
	}
	return 0;
}

double hit_square(t_objet *objet, t_ray *ray)
{
	double a;
	double b;
	double t;
	t_vector produit;
	t_vector point;
	t_vector oc;
	t_vector v;
	double edge;
	double proj1;
	double proj2;

	a = vector_dot(ray->direction, objet->v);

	if (a != 0)
	{
		oc = vector_sub(ray->origin, objet->pos);
		t = -1 * vector_dot(oc, objet->v) / a;
		if (t > 0)
		{

			produit = vector_scal(t, ray->direction);
			point = vector_add(ray->origin, produit);
			
			v = vector_sub(point, objet->pos);

			edge = objet->height/2;
			if (fabs(v.x) > edge || fabs(v.y) > edge || fabs(v.z) > edge)
				return (0);
			return (t);
		}
	}
	return 0;
}



double hit_cylinder(t_objet *objet, t_ray *ray)
{
	double a;
	double b;
	double c;
	double discriminant;
	t_vector x;
	double t;
	double t1;
	double t2;
	double m1;
	double m2;
	
	//objet->v = unit_vector(objet->v);
	x = vector_sub( ray->origin, objet->pos);
	
	a = vector_dot(ray->direction, ray->direction) - (vector_dot(ray->direction, objet->v) * vector_dot(ray->direction, objet->v));
	b = 2 * (vector_dot(ray->direction, x) - (vector_dot(ray->direction, objet->v) * vector_dot(x, objet->v)));
	c = vector_dot(x, x) - (vector_dot(x, objet->v) * vector_dot(x, objet->v)) - (objet->radius/2 * objet->radius/2);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
		
	t1 = (-b + sqrt(discriminant)) / (2 * a);
	t2 = (-b - sqrt(discriminant)) / (2 * a);
	
	if (t1 < 0)
		return (0);


	m1 = vector_dot(ray->direction, objet->v) * t2 + vector_dot(x, objet->v);
	m2 = vector_dot(ray->direction, objet->v) * t1 + vector_dot(x, objet->v);
	
	if (m1 >= 0 && m1 <= objet->height )
	{	
		return (t2);
	}
	
	else if (m2 >= 0 && m2 <= objet->height )
	 {
		return (t1);
	 }
	return 0;
}

double hit_triangle(t_objet *objet, t_ray *ray)
{
	double epsilon = 0.0000001;
	t_vector edge1;
	t_vector edge2;
	t_vector h;
	t_vector s;
	t_vector q;
	double a;
	double f;
	double u;
	double v;
	double t;

	edge1 = vector_sub(objet->pos1, objet->pos);
	edge2 = vector_sub(objet->pos2, objet->pos);
	h = vector_cross(ray->direction, edge2);
	a = vector_dot(edge1, h);

	if (a > -epsilon && a < epsilon)
		return (0);
	f = 1.0 / a;
	s = vector_sub(ray->origin, objet->pos);
	u = f * vector_dot(s, h);
	if (u < 0.0 || u > 1.0)
		return (0);
	q = vector_cross(s, edge1);
	v = f * vector_dot(ray->direction, q);
	if (v < 0.0 || u + v > 1.0)
		return (0);
	t = f * vector_dot(edge2, q);
	if (t > epsilon)
		return (t);
	else
		return (0);
}

void hit_objet(t_data *type, double *t1)
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
		if (type->objet->type == sphere_d)
		{
			has_inter = hit_sphere(type->objet, ray);
		}
		else if (type->objet->type == plane_d)
		{
			has_inter = hit_plane(type->objet, ray);
		}
		else if (type->objet->type == square_d)
		{
			has_inter = hit_square(type->objet, ray);
		}
		else if (type->objet->type == cylinder_d)
			has_inter = hit_cylinder(type->objet, ray);
		else if (type->objet->type == triangle_d)
			has_inter = hit_triangle(type->objet, ray);
		if (has_inter > 0 && has_inter < *t1)
		{
			// hna dart structure t_tool bash nhtafad bles donnes
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
