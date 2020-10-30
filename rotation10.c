/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:15:50 by thor              #+#    #+#             */
/*   Updated: 2020/10/30 10:32:37 by sqatim           ###   ########.fr       */
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
void rotation_r_l(t_data *type)
{
    double orient;

    orient = 0.1;
    if (type->key.key == right)
    {
        if (type->key.type == camera_d)
            type->clone.camera->ort_vec.x -= orient;
        else if (check_orient(type->clone.objet->type))
            type->clone.objet->v.x += orient;
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clone.objet->v.x, type->clone.objet->v.y, type->clone.objet->v.z);
    }
    if (type->key.key == left)
    {
        if (type->key.type == camera_d)
            type->clone.camera->ort_vec.x += orient;
        else if (check_orient(type->clone.objet->type))
            type->clone.objet->v.x -= orient;
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clone.objet->v.x, type->clone.objet->v.y, type->clone.objet->v.z);
    }
}
void rotation_u_d(t_data *type)
{
    double orient;

    orient = 0.1;
    if (type->key.key == up)
    {
        if (type->key.type == camera_d)
            type->clone.camera->ort_vec.y -= orient;
        else if (check_orient(type->clone.objet->type))
        {
            type->clone.objet->v.y += orient;
            // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clone.objet->v.x, type->clone.objet->v.y, type->clone.objet->v.z);
        }
    }
    if (type->key.key == down)
    {
        if (type->key.type == camera_d)
            type->clone.camera->ort_vec.y += orient;
        else if (check_orient(type->clone.objet->type))
        {
            type->clone.objet->v.y -= orient;
            // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clone.objet->v.x, type->clone.objet->v.y, type->clone.objet->v.z);
        }
    }
}
void rotation_a_b(t_data *type)
{
    double orient;

    orient = 0.05;
    if (type->key.key == ahead)
    {
        if (type->key.type == camera_d)
            type->clone.camera->ort_vec.z += orient;
        else if (check_orient(type->clone.objet->type))
            type->clone.objet->v.z += orient;
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clone.objet->v.x, type->clone.objet->v.y, type->clone.objet->v.z);
    }
    if (type->key.key == back)
    {
        if (type->key.type == camera_d)
            type->clone.camera->ort_vec.z -= orient;
        else if (check_orient(type->clone.objet->type))
            type->clone.objet->v.z -= orient;
        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clone.objet->v.x, type->clone.objet->v.y, type->clone.objet->v.z);
    }
}

void rotation(t_data *type)
{

        if (type->key.rot_xyz == 1)
            rotation_r_l(type);
        if (type->key.key == up || type->key.key == down)
            rotation_u_d(type);
        if (type->key.key == ahead || type->key.key == back)
        {
            rotation_a_b(type);
        }
}