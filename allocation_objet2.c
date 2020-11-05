/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_objet2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:16:50 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/05 12:20:41 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void extr_cylinder(t_objet *new_cylinder, char **cylinder)
{
    char **colour;
    double height;
    double radius;

    colour = ft_split(cylinder[3], ',');
    radius = ft_atod(cylinder[4]);
    height = ft_atod(cylinder[5]);
    new_cylinder->colour = make_range(r_g_b(colour[0], colour[1], colour[2]));
    new_cylinder->radius = radius/2;
    new_cylinder->height = height;
}

t_objet *add_cylinder(t_data *type, char **pos, char **v, char **cylinder)
{
    t_objet *tmp;
    t_objet *new_cylinder;

    tmp = type->objet;
    if (!(new_cylinder = (t_objet *)malloc(sizeof(t_objet))))
        return (NULL);
    new_cylinder->previous = NULL;
    new_cylinder->next = NULL;
    new_cylinder->type = cylinder_d;
    new_cylinder->pos = x_y_z(pos[0], pos[1], pos[2]);
    new_cylinder->v = x_y_z(v[0], v[1], v[2]);
    extr_cylinder(new_cylinder, cylinder);
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

static void extr_triangle(t_objet *new_triangle, char **triangle)
{
    char **pos2;
    char **colour;

    pos2 = ft_split(triangle[3], ',');
    colour = ft_split(triangle[4], ',');
    new_triangle->colour = make_range(r_g_b(colour[0], colour[1], colour[2]));
    new_triangle->pos2 = x_y_z(pos2[0], pos2[1], pos2[2]);
}

t_objet *add_triangle(t_data *type, char **pos, char **pos1, char **triangle)
{
    t_objet *tmp;
    t_objet *new_triangle;

    tmp = type->objet;
    if (!(new_triangle = (t_objet *)malloc(sizeof(t_objet))))
        return (NULL);
    new_triangle->previous = NULL;
    new_triangle->next = NULL;
    new_triangle->type = triangle_d;
    new_triangle->pos = x_y_z(pos[0], pos[1], pos[2]);
    new_triangle->pos1 = x_y_z(pos1[0], pos1[1], pos1[2]);
    extr_triangle(new_triangle, triangle);
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