/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_objet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:28:40 by thor              #+#    #+#             */
/*   Updated: 2020/10/22 09:19:32 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objet *add_sphere(t_data *type, char **pos, char **colour, double diametre)
{
    t_objet *tmp;
    t_objet *new_sphere;

    tmp = type->objet;
    if (!(new_sphere = (t_objet *)malloc(sizeof(t_objet))))
        return (NULL);
    new_sphere->previous = NULL;
    new_sphere->next = NULL;
    new_sphere->type = sphere_d;
    new_sphere->pos = x_y_z(pos[0], pos[1], pos[2]);
    new_sphere->colour = make_range(r_g_b(colour[0], colour[1], colour[2]));
    new_sphere->radius = diametre/2;
    new_sphere->i = type->tool.index;
    type->tool.index++;
    if (type->objet == NULL)
        return (new_sphere);
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_sphere->previous = tmp;
    tmp->next = new_sphere;
    return (type->objet);
}

t_objet *add_plane(t_data *type, char **pos, char **vector, char **colour)
{
    t_objet *tmp;
    t_objet *new_plane;

    tmp = type->objet;
    if (!(new_plane = (t_objet *)malloc(sizeof(t_objet))))
        return (NULL);
    new_plane->previous = NULL;
    new_plane->next = NULL;
    new_plane->type = plane_d;
    new_plane->pos = x_y_z(pos[0], pos[1], pos[2]);
    new_plane->v = x_y_z(vector[0], vector[1], vector[2]);
    new_plane->v = unit_vector(new_plane->v);
    new_plane->colour = make_range(r_g_b(colour[0], colour[1], colour[2]));
    new_plane->i = type->tool.index;
    type->tool.index++;
    if (type->objet == NULL)
        return (new_plane);
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_plane->previous = tmp;
    tmp->next = new_plane;
    return (type->objet);
}

static void extr_square(t_objet *new_square, char **square)
{
    char **colour;
    double height;

    colour = ft_split(square[4], ',');
    height = ft_atod(square[3]);
    new_square->colour = make_range(r_g_b(colour[0], colour[1], colour[2]));
    new_square->height = height;
}

t_objet *add_square(t_data *type, char **pos, char **normal, char **square)
{
    t_objet *tmp;
    t_objet *new_square;

    tmp = type->objet;
    if (!(new_square = (t_objet *)malloc(sizeof(t_objet))))
        return (NULL);
    new_square->previous = NULL;
    new_square->next = NULL;
    new_square->type = square_d;
    new_square->pos = x_y_z(pos[0], pos[1], pos[2]);
    new_square->v = x_y_z(normal[0], normal[1], normal[2]);
    extr_square(new_square, square);
    new_square->i = type->tool.index;
    type->tool.index++;
    if (type->objet == NULL)
        return (new_square);
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_square->previous = tmp;
    tmp->next = new_square;
    return (type->objet);
}

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
    // new_cylinder->v = unit_vector(new_cylinder->v);
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