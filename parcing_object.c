/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:29:08 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/02 14:30:52 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void parc_sphere(t_data *type, char *line)
{
    char **sphere;
    char **pos;
    char **colour;
    double diametre;

    sphere = ft_space_split(line);
    pos = ft_split(sphere[1], ',');
    colour = ft_split(sphere[3], ',');
    diametre = ft_atod(sphere[2]);

    type->objet = add_sphere(type, pos, colour, diametre);
}

void parc_plane(t_data *type, char *line)
{
    char **plane;
    char **pos;
    char **vector;
    char **colour;

    plane = ft_space_split(line);
    pos = ft_split(plane[1], ',');
    vector = ft_split(plane[2], ',');
    colour = ft_split(plane[3], ',');

    type->objet = add_plane(type, pos, vector, colour);
}

void parc_square(t_data *type, char *line)
{
    char **square;
    char **pos;
    char **normal;

    square = ft_space_split(line);
    pos = ft_split(square[1], ',');
    normal = ft_split(square[2], ',');

    type->objet = add_square(type, pos, normal, square);
}

void parc_cylinder(t_data *type, char *line)
{
    char **cylinder;
    char **pos;
    char **v;

    cylinder = ft_space_split(line);
    pos = ft_split(cylinder[1], ',');
    v = ft_split(cylinder[2], ',');

    type->objet = add_cylinder(type, pos, v, cylinder);
}

void parc_triangle(t_data *type, char *line)
{
    char **triangle;
    char **pos;
    char **pos1;
    char **pos2;

    triangle = ft_space_split(line);
    pos = ft_split(triangle[1], ',');
    pos1 = ft_split(triangle[2], ',');
    type->objet = add_triangle(type, pos, pos1, triangle);
}