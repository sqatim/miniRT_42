/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_rcl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:36:24 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/02 14:37:15 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void parc_resl(t_data *type, char *line)
{
    char **res = ft_space_split(line);
    type->rsl.width = ft_atoi(res[1]);
    type->rsl.height = ft_atoi(res[2]);
}

void parc_amb(t_data *type, char *line)
{
    char **amb;
    char **rgb;

    amb = ft_space_split(line);
    rgb = ft_split(amb[2], ',');

    type->ambient.int_amb = ft_atod(amb[1]);
    type->ambient.rgb_amb = r_g_b(rgb[0], rgb[1], rgb[2]);
    type->ambient.rgb_amb = make_range(type->ambient.rgb_amb);
}

void parc_camera(t_data *type, char *line)
{
    char **camera;
    char **pos;
    char **ort_vec;
    double fov;

    camera = ft_space_split(line);
    pos = ft_split(camera[1], ',');
    ort_vec = ft_split(camera[2], ',');
    fov = ft_atod(camera[3]);

    type->camera = add_camera(type, pos, ort_vec, fov);
}

void parc_light(t_data *type, char *line)
{
    char **light;
    char **rgb;
    char **pos;
    double int_light;

    light = ft_space_split(line);
    pos = ft_split(light[1], ',');
    rgb = ft_split(light[3], ',');
    int_light = ft_atod(light[2]);

    type->light = add_light(type, pos, int_light, rgb);
}

