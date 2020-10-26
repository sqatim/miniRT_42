/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:15:50 by thor              #+#    #+#             */
/*   Updated: 2020/04/02 20:20:19 by thor             ###   ########.fr       */
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
            type->clo.camera->ort_vec.x -= orient;
        else if (check_orient(type->clo.objet->type))
            type->clo.objet->v.x += orient;
        printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
    if (type->key.key == left)
    {
        if (type->key.type == camera_d)
            type->clo.camera->ort_vec.x += orient;
        else if (check_orient(type->clo.objet->type))
            type->clo.objet->v.x -= orient;
        printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
}
void rotation_u_d(t_data *type)
{
    double orient;

    orient = 0.1;
    if (type->key.key == up)
    {
        if (type->key.type == camera_d)
            type->clo.camera->ort_vec.y -= orient;
        else if (check_orient(type->clo.objet->type))
        {
            type->clo.objet->v.y += orient;
            printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
        }
    }
    if (type->key.key == down)
    {
        if (type->key.type == camera_d)
            type->clo.camera->ort_vec.y += orient;
        else if (check_orient(type->clo.objet->type))
        {
            type->clo.objet->v.y -= orient;
            printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
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
            type->clo.camera->ort_vec.z += orient;
        else if (check_orient(type->clo.objet->type))
            type->clo.objet->v.z += orient;
        printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
    if (type->key.key == back)
    {
        if (type->key.type == camera_d)
            type->clo.camera->ort_vec.z -= orient;
        else if (check_orient(type->clo.objet->type))
            type->clo.objet->v.z -= orient;
        printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type->clo.objet->v.x, type->clo.objet->v.y, type->clo.objet->v.z);
    }
}