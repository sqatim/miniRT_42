/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 02:19:52 by thor              #+#    #+#             */
/*   Updated: 2020/11/17 12:14:56 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static t_colour	shadow_intersect(t_data *type)
{
	t_colour zero;

	if (type->shad.degre > 1)
		type->shad.degre = 1;
	zero.r = 1 - type->shad.degre;
	zero.g = 1 - type->shad.degre;
	zero.b = 1 - type->shad.degre;
	return (zero);
}

t_colour		shadows(t_data *type, t_objet *tmp)
{
	t_colour	un;
	t_ray		ombre;
	t_light		*light;

	type->shad.intersect = 0;
	light = type->light;
	type->shad.degre = 0;
	un = make_number(1.0);
	ombre.origin = vector_scal(0.001, type->objet->normal);
	ombre.origin = vector_add(type->objet->point, ombre.origin);
	while (type->light != NULL)
	{
		ombre.direction = vector_sub(type->light->pos, type->objet->point);
		ombre.lenght = vector_length(ombre.direction);
		ombre.direction = unit_vector(ombre.direction);
		hit_objet2(type, &ombre, tmp);
		type->light = type->light->next;
	}
	type->light = light;
	if (type->shad.intersect == 1)
		return (shadow_intersect(type));
	return (un);
}
