/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 02:19:52 by thor              #+#    #+#             */
/*   Updated: 2020/11/09 13:39:05 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_colour shadows(t_data *type, t_objet *tmp)
{
    t_colour zero;
    t_colour un;
    t_ray ombre;
    double has_intersect;
    t_light *light;
    type->shad.intersect = 0;
    // type->tool.shad = 0;
    light = type->light;
    type->shad.degre = 0;

    zero = make_number(zero, 0.0);
    un = make_number(un, 1.0);
    ombre.origin.x = type->objet->point.x + 0.001 * type->objet->normal.x;
    ombre.origin.y = type->objet->point.y + 0.001 * type->objet->normal.y;
    ombre.origin.z = type->objet->point.z + 0.001 * type->objet->normal.z;
    // ombre.origin.x = type->objet->point.x + 0.001 * type->objet->normal.x;
    // ombre.origin.y = type->objet->point.y + 0.001 * type->objet->normal.y;
    // ombre.origin.z = type->objet->point.z + 0.001 * type->objet->normal.z;
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
    {
        if (type->shad.degre > 1)
            type->shad.degre = 1;
        zero.r = 1 - type->shad.degre;
        zero.g = 1 - type->shad.degre;
        zero.b = 1 - type->shad.degre;

        return (zero);
    }
    return (un);
}