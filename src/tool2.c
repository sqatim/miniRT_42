/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:03:56 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 11:06:15 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	x_y_z(char *x, char *y, char *z)
{
	t_vector extr;

	extr.x = ft_atod(x);
	extr.y = ft_atod(y);
	extr.z = ft_atod(z);
	return (extr);
}

void		calcul_delta_cy(t_objet *objet, t_ray *ray, t_varcal *var)
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

static void	free_light(t_data *type)
{
	t_light *tmp_l;

	while (type->light != NULL)
	{
		tmp_l = type->light->next;
		free(type->light);
		type->light = NULL;
		type->light = tmp_l;
	}
}

int			free_exit(t_data *type, int wich)
{
	t_objet		*tmp_o;
	t_camera	*tmp_c;

	while (type->objet != NULL)
	{
		tmp_o = type->objet->next;
		free(type->objet);
		type->objet = NULL;
		type->objet = tmp_o;
	}
	while (type->camera != NULL)
	{
		tmp_c = type->camera->next;
		free(type->camera);
		type->camera = NULL;
		type->camera = tmp_c;
	}
	free_light(type);
	exit(wich);
}

void		witch_object(t_objet *objet, t_ray *ray, double *has_inter)
{
	if (objet->type == SPHERE_D)
		*has_inter = hit_sphere(objet, ray);
	else if (objet->type == PLANE_D)
		*has_inter = hit_plane(objet, ray);
	else if (objet->type == SQUARE_D)
		*has_inter = hit_square(objet, ray);
	else if (objet->type == CYLINDER_D)
		*has_inter = hit_cylinder(objet, ray);
	else if (objet->type == TRIANGLE_D)
		*has_inter = hit_triangle(objet, ray);
}
