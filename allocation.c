/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:57:52 by thor              #+#    #+#             */
/*   Updated: 2020/04/02 20:23:17 by thor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minirt.h"

t_light *add_light(t_data *type, char **pos, double int_light,char **rgb)
{
    t_light *tmp;
    t_light *new_light;

    tmp = type->light;
    if (!(new_light = (t_light *)malloc(sizeof(t_light))))
        return (NULL);
    new_light->previous = NULL;
    new_light->next = NULL;
    new_light->pos = x_y_z(pos[0], pos[1], pos[2]);
    new_light->int_light = int_light;
    new_light->rgb_light = make_range(r_g_b(rgb[0], rgb[1], rgb[2]));
    if (type->light == NULL)
        return (new_light);  
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_light->previous = tmp;
    tmp->next = new_light;
    return (type->light);
}

t_camera *add_camera(t_data *type, char **pos, char **ort_vec,double fov)
{
    t_camera *tmp;
    t_camera *new_camera;

    tmp = type->camera;
    if (!(new_camera = (t_camera *)malloc(sizeof(t_camera))))
        return (NULL);
    new_camera->previous = NULL;
    new_camera->next = NULL;
    new_camera->pos = x_y_z(pos[0], pos[1], pos[2]);
    new_camera->ort_vec =  x_y_z(ort_vec[0], ort_vec[1], ort_vec[2]);
    new_camera->fov = fov;
    if (type->camera == NULL)
        return (new_camera);
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_camera->previous = tmp;
    tmp->next = new_camera;
    return (type->camera);
}
