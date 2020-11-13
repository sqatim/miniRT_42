/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_objet2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:16:50 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/13 14:35:17 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objet *add_cylinder(t_data *type, t_info object)
{
    t_objet *tmp;
    t_objet *new_cylinder;

    tmp = type->objet;
    if (!(new_cylinder = (t_objet *)malloc(sizeof(t_objet))))
        return (NULL);
    new_cylinder->previous = NULL;
    new_cylinder->next = NULL;
    new_cylinder->type = cylinder_d;
    new_cylinder->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
    new_cylinder->v = x_y_z(object.vector[0], object.vector[1], object.vector[2]);
    new_cylinder->v = unit_vector(new_cylinder->v);
    new_cylinder->colour = make_range(r_g_b(object.colour[0], object.colour[1], object.colour[2]));
    new_cylinder->radius = object.radius / 2;
    new_cylinder->height = object.height;
    trans_rot(type, new_cylinder, object);
    new_cylinder->i = type->tool.index;
    type->tool.index++;
    if (type->objet == NULL)
        return (new_cylinder);
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_cylinder->previous = tmp;
    tmp->next = new_cylinder;
    return (type->objet);
}

t_objet *add_triangle(t_data *type, t_info object)
{
    t_objet *tmp;
    t_objet *new_triangle;

    tmp = type->objet;
    if (!(new_triangle = (t_objet *)malloc(sizeof(t_objet))))
        return (NULL);
    new_triangle->previous = NULL;
    new_triangle->next = NULL;
    new_triangle->type = triangle_d;
    new_triangle->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
    new_triangle->pos1 = x_y_z(object.pos1[0], object.pos1[1], object.pos1[2]);
    new_triangle->pos2 = x_y_z(object.pos2[0], object.pos2[1], object.pos2[2]);
    new_triangle->colour = make_range(r_g_b(object.colour[0], object.colour[1], object.colour[2]));
    trans_rot(type, new_triangle, object);
    new_triangle->i = type->tool.index;
    type->tool.index++;
    if (type->objet == NULL)
        return (new_triangle);
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_triangle->previous = tmp;
    tmp->next = new_triangle;
    return (type->objet);
}