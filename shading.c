/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 02:19:52 by thor              #+#    #+#             */
/*   Updated: 2020/11/06 14:55:13 by sqatim           ###   ########.fr       */
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
    // type->tool.shad = 0;
    type->tool.shad = 1;
    light = type->light;

    zero = make_number(zero, 0.0);
    un = make_number(un, 1.0);
    ombre.origin.x = type->objet->point.x + 0.001 *  type->objet->normal.x;
    ombre.origin.y = type->objet->point.y + 0.001 *  type->objet->normal.y;
    ombre.origin.z = type->objet->point.z + 0.001 *  type->objet->normal.z;
    while (type->light != NULL)
    {
        ombre.direction = vector_sub(type->light->pos, type->objet->point);
        ombre.lenght = vector_length(ombre.direction);
        ombre.direction = unit_vector(ombre.direction);
        has_intersect = hit_objet2(type, &ombre, tmp);
        type->light = type->light->next;
    }
    type->light = light;
    if (has_intersect == 1)
        return (zero);
    return (un);
}