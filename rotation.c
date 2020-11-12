/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:15:50 by thor              #+#    #+#             */
/*   Updated: 2020/11/12 13:50:19 by sqatim           ###   ########.fr       */
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
    t_vector vect;
    double angle_rot;

    angle_rot = -PI / 18;
    if (type->key.key == back)
        angle_rot *= -1;
    if (type->key.type == camera_d)
        vect = type->clone.camera->ort_vec;
    else if (check_orient(type->clone.objet->type))
        vect = type->clone.objet->v;
    if (type->key.key == ahead || type->key.key == back)
    {
        vect.y = vect.y * cos(angle_rot) - vect.z * sin(angle_rot);
        vect.z = vect.y * sin(angle_rot) + vect.z * cos(angle_rot);
    }
    if (type->key.type == camera_d)
        type->clone.camera->ort_vec = unit_vector(vect);
    else if (check_orient(type->clone.objet->type))
        type->clone.objet->v = unit_vector(vect);
}

void rotation_y(t_data *type)
{
    t_vector vect;
    double angle_rot;

    angle_rot = -PI / 18;
    if (type->key.key == down)
        angle_rot *= -1;
    if (type->key.type == camera_d)
        vect = type->clone.camera->ort_vec;
    else if (check_orient(type->clone.objet->type))
        vect = type->clone.objet->v;
    if (type->key.key == up || type->key.key == down)
    {
        vect.x = vect.z * sin(angle_rot) + vect.x * cos(angle_rot);
        vect.z = vect.z * cos(angle_rot) - vect.x * sin(angle_rot);
    }
    if (type->key.type == camera_d)
        type->clone.camera->ort_vec = unit_vector(vect);
    else if (check_orient(type->clone.objet->type))
        type->clone.objet->v = unit_vector(vect);
}

void rotation_z(t_data *type)
{
    t_vector vect;
    double angle_rot;

    angle_rot = -PI / 18;
    if (type->key.key == left)
        angle_rot *= -1;
    if (type->key.type == camera_d)
        vect = type->clone.camera->ort_vec;
    else if (check_orient(type->clone.objet->type))
        vect = type->clone.objet->v;
    if (type->key.key == right || type->key.key == left)
    {
        vect.x = vect.x * cos(angle_rot) - vect.y * sin(angle_rot);
        vect.y = vect.x * sin(angle_rot) + vect.y * cos(angle_rot);
    }
    if (type->key.type == camera_d)
        type->clone.camera->ort_vec = unit_vector(vect);
    else if (check_orient(type->clone.objet->type))
        type->clone.objet->v = unit_vector(vect);
}
void rotation(t_data *type)
{

    if (type->key.rot_xyz == 1 && (type->key.key == ahead || type->key.key == back))
        rotation_x(type);
    if (type->key.rot_xyz == 2 && (type->key.key == up || type->key.key == down))
        rotation_y(type);
    if (type->key.rot_xyz == 3 && (type->key.key == right || type->key.key == left))
        rotation_z(type);
}