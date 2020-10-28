/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:15:50 by thor              #+#    #+#             */
/*   Updated: 2020/10/28 14:45:24 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int check_orient(int type)
{
    if (type == sphere_d || type == triangle_d)
        return (0);
    else
        return (1);
}
void rotation_x(t_data *type)
{
    double orient;

    orient = -PI/11;
    double y; 
    double z;

    if (type->key.key == ahead)
    {
        if (type->key.type == camera_d)
        {
            y = type->clo.camera->ort_vec.y;
            z = type->clo.camera->ort_vec.z;
            type->clo.camera->ort_vec.y = y * cos(orient) - z * sin(orient);
            type->clo.camera->ort_vec.z = y * sin(orient) + z * cos(orient);

        }
        else if (check_orient(type->clo.objet->type))
        {
            y = type->clo.objet->v.y;
            z = type->clo.objet->v.z;

            type->clo.objet->v.y = y * cos(orient) - z * sin(orient);
            type->clo.objet->v.z = y * sin(orient) + z * cos(orient);
        }
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
    if (type->key.key == back)
    {
        orient *= -1;
       if (type->key.type == camera_d)
        {
            y = type->clo.camera->ort_vec.y;
            z = type->clo.camera->ort_vec.z;
            type->clo.camera->ort_vec.y = y * cos(orient) - z * sin(orient);
            type->clo.camera->ort_vec.z = y * sin(orient) + z * cos(orient);

        }
        else if (check_orient(type->clo.objet->type))
        {
            y = type->clo.objet->v.y;
            z = type->clo.objet->v.z;
            type->clo.objet->v.y = y * cos(orient) - z * sin(orient);
            type->clo.objet->v.z = y * sin(orient) + z * cos(orient);
        }
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
}
void rotation_y(t_data *type)
{
    double orient;

    orient = -PI/11;
    double x; 
    double z;

    if (type->key.key == up)
    {
        if (type->key.type == camera_d)
        {
            x = type->clo.camera->ort_vec.x;
            z = type->clo.camera->ort_vec.z;
            type->clo.camera->ort_vec.x = z * sin(orient) + x * cos(orient);
            type->clo.camera->ort_vec.z = z * cos(orient) - x * sin(orient);

            type->clo.camera->ort_vec.z += orient;
        }
        else if (check_orient(type->clo.objet->type))
        {
            x = type->clo.objet->v.x;
            z = type->clo.objet->v.z;

            type->clo.objet->v.x = z * sin(orient) + x * cos(orient);
            type->clo.objet->v.z = z * cos(orient) - x * sin(orient);
        }
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
    if (type->key.key == down)
    {
        orient *= -1;
       if (type->key.type == camera_d)
        {
            x = type->clo.camera->ort_vec.x;
            z = type->clo.camera->ort_vec.z;
           type->clo.camera->ort_vec.x = z * sin(orient) + x * cos(orient);
            type->clo.camera->ort_vec.z = z * cos(orient) - x * sin(orient);

        }
        else if (check_orient(type->clo.objet->type))
        {
            x = type->clo.objet->v.x;
            z = type->clo.objet->v.z;
            type->clo.objet->v.x = z * sin(orient) + x * cos(orient);
            type->clo.objet->v.z = z * cos(orient) - x * sin(orient);
        }
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
}
void rotation_z(t_data *type)
{
    double orient;

    orient = -PI/11;
    double x; 
    double y;

    if (type->key.key == right)
    {
        if (type->key.type == camera_d)
        {
            x = type->clo.camera->ort_vec.x;
            y = type->clo.camera->ort_vec.y;
            type->clo.camera->ort_vec.x = x * cos(orient) - y * sin(orient);
            type->clo.camera->ort_vec.y = x * sin(orient) + y * cos(orient);

        }
        else if (check_orient(type->clo.objet->type))
        {
            x = type->clo.objet->v.x;
            y = type->clo.objet->v.y;
            type->clo.objet->v.x = x * cos(orient) - y * sin(orient);
            type->clo.objet->v.y = x * sin(orient) + y * cos(orient);
        }
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
    if (type->key.key == left)
    {
        orient *= -1;
       if (type->key.type == camera_d)
        {
            x = type->clo.camera->ort_vec.x;
            y = type->clo.camera->ort_vec.y;
            type->clo.camera->ort_vec.x = x * cos(orient) - y * sin(orient);
            type->clo.camera->ort_vec.y = x * sin(orient) + y * cos(orient);

        }
        else if (check_orient(type->clo.objet->type))
        {
            x = type->clo.objet->v.x;
            y = type->clo.objet->v.y;
            type->clo.objet->v.x = x * cos(orient) - y * sin(orient);
            type->clo.objet->v.y = x * sin(orient) + y * cos(orient);
        }
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
}

void rotation(t_data *type)
{

        if (type->key.rot_xyz == 1 && (type->key.key == ahead || type->key.key == back))
            rotation_x(type);
        if (type->key.rot_xyz == 2 && (type->key.key == up || type->key.key == down))
            rotation_y(type);
        if (type->key.rot_xyz == 3 && (type->key.key == right || type->key.key == left))
        {
            rotation_z(type);
        }
}