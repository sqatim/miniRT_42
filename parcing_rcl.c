/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_rcl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:36:24 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/13 11:50:54 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void parc_resl(t_data *type, char *line)
{
    char **res = ft_space_split(line);
    type->rsl.width = ft_atoi(res[1]);
    type->rsl.height = ft_atoi(res[2]);
    if (type->rsl.width > 2560)
        type->rsl.width = 2560;
    if (type->rsl.height > 1440)
        type->rsl.height = 1440;
    type->parcing.r = 1;
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
    type->parcing.a = 1;
}

void parc_camera(t_data *type, char *line)
{
    char **camera;
    t_info object;

    camera = ft_space_split(line);
    object.pos = ft_split(camera[1], ',');
    object.vector = ft_split(camera[2], ',');
    object.fov = ft_atod(camera[3]);
    if (type->tool.tran_rot > 0)
    {
        object.translation = ft_split(camera[4], ',');
        if (type->tool.tran_rot == 2)
            object.rotation = ft_split(camera[5], ',');
    }
    type->camera = add_camera(type, object);
}

void parc_light(t_data *type, char *line)
{
    char **light;
    t_info object;

    light = ft_space_split(line);
    object.pos = ft_split(light[1], ',');
    object.colour = ft_split(light[3], ',');
    object.int_light = ft_atod(light[2]);

    type->light = add_light(type, object);
}
