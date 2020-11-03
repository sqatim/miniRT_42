/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 02:19:52 by thor              #+#    #+#             */
/*   Updated: 2020/11/03 19:11:17 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int hit_objet2(t_data *type, t_ray *ombre, t_objet *tmp)
{
    double has_inter;
    t_objet *temporaire;
    /* modification hna kant dayr :
    int i = 0;
    obadalt fcondition lawla fal boucle 
    
    if(i == type->objet->i && temporaire->next != NULL )
                temporaire = temporaire->next;
    */
    int i = 0;
    // int i = type->tool.index;
    double d_light = vector_dot(type->objet->light, type->objet->light);

    temporaire = tmp;
    has_inter = 0;

    while (temporaire != NULL)
    {

        if (i == type->objet->i)
            temporaire = temporaire->next;
        if (temporaire != NULL)
        {
            if (temporaire->type == sphere_d)
                has_inter = hit_sphere(temporaire, ombre);
            else if (temporaire->type == plane_d)
                has_inter = hit_plane(temporaire, ombre);
            else if (temporaire->type == square_d)
                has_inter = hit_square(temporaire, ombre);
            else if (temporaire->type == cylinder_d)
            {
                has_inter = hit_cylinder(temporaire, ombre);
            }
            else if (temporaire->type == triangle_d)
                has_inter = hit_triangle(temporaire, ombre);
            i++;
            if (has_inter > 0 && has_inter * has_inter < d_light)
            {
                // type->tool.shad = 1;
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
    ombre.origin.x = type->objet->point.x + 0.001 * type->objet->normal.x;
    ombre.origin.y = type->objet->point.y + 0.001 * type->objet->normal.y;
    ombre.origin.z = type->objet->point.z + 0.001 * type->objet->normal.z;
    while (type->light != NULL)
    {
        ombre.direction = vector_sub(type->light->pos, type->objet->point);
        ombre.direction = unit_vector(ombre.direction);
        has_intersect = hit_objet2(type, &ombre, tmp);
        type->light = type->light->next;
    }
    type->light = light;
    if (has_intersect == 1)
        return (zero);
    return (un);
}