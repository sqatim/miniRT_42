/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:31:32 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/19 12:02:43 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_colour	ft_ambient(t_data *type)
{
	t_colour ambient;
	t_colour scal;

	scal = colour_scal(type->ambient.int_amb, type->ambient.rgb_amb);
	ambient.r = type->objet->colour.r * scal.r;
	ambient.g = type->objet->colour.g * scal.g;
	ambient.b = type->objet->colour.b * scal.b;
	ambient.r = min(1, ambient.r);
	ambient.g = min(1, ambient.g);
	ambient.b = min(1, ambient.b);
	return (ambient);
}

static t_colour	ft_diffuse(t_data *type)
{
	double		dot;
	t_colour	diffuse;
	t_vector	l_norm;

	l_norm = unit_vector(type->objet->light);
	dot = vector_dot(l_norm, type->objet->normal);
	dot = max(0.0, dot) * type->light->int_light;
	diffuse.r = type->light->rgb_light.r * type->objet->colour.r * dot;
	diffuse.g = type->light->rgb_light.g * type->objet->colour.g * dot;
	diffuse.b = type->light->rgb_light.b * type->objet->colour.b * dot;
	return (diffuse);
}

static void		cofficient(t_data *type, double *ks, double *shininess)
{
	if (type->objet->type == PLANE_D ||\
		type->objet->type == TRIANGLE_D || type->objet->type == SQUARE_D)
	{
		*shininess = 1;
		*ks = 0.2;
	}
	else if (type->objet->type == CYLINDER_D)
	{
		*shininess = 2;
		*ks = 0.2;
	}
	else if (type->objet->type == SPHERE_D)
	{
		*shininess = 50;
		*ks = 0.5;
	}
}

t_colour		ft_specular(t_data *type)
{
	double		dot;
	t_vector	scal;
	t_colour	specular;
	double		shininess;
	double		ks;

	cofficient(type, &ks, &shininess);
	dot = 2 * vector_dot(type->objet->normal, type->objet->light);
	scal = vector_scal(dot, type->objet->normal);
	type->objet->reflection = vector_sub(scal, type->objet->light);
	type->objet->view = vector_scal(-1, type->ray.direction);
	type->objet->reflection = unit_vector(type->objet->reflection);
	type->objet->view = unit_vector(type->objet->view);
	dot = vector_dot(type->objet->reflection, type->objet->view);
	dot = max(0, dot);
	specular.r = type->light->rgb_light.r * (pow(dot, shininess)) * ks;
	specular.g = type->light->rgb_light.g * (pow(dot, shininess)) * ks;
	specular.b = type->light->rgb_light.b * (pow(dot, shininess)) * ks;
	return (specular);
}

t_colour		phong(t_data *type, t_colour shadow)
{
	t_light		*light;
	t_colour	somme;
	t_colour	phong_s;

	ft_bzero(&type->phong, sizeof(t_phong));
	light = type->light;
	while (type->light != NULL)
	{
		type->objet->light = vector_sub(type->light->pos, type->objet->point);
		type->phong.diffuse = colour_add(type->phong.diffuse, ft_diffuse(type));
		type->phong.specular = colour_add(type->phong.specular,
								ft_specular(type));
		type->light = type->light->next;
	}
	type->phong.diffuse = colour_scal(255, type->phong.diffuse);
	type->phong.specular = colour_scal(255, type->phong.specular);
	type->phong.ambiant = colour_scal(255, ft_ambient(type));
	somme = colour_add(type->phong.diffuse, type->phong.specular);
	phong_s = colour_prd(shadow, somme);
	phong_s = colour_add(phong_s, type->phong.ambiant);
	type->light = light;
	phong_s = min_max(phong_s);
	return (phong_s);
}
