/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:52:14 by thor              #+#    #+#             */
/*   Updated: 2020/10/19 08:39:08 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void affectation(t_data *type)
// {

//     double aspect;
//     double theta = 90 * PI / 180;

//     double half_height;
//     double half_width;
//     if (type->rsl.width >= type->rsl.height)
//     {
//         aspect = type->rsl.width / type->rsl.height;
//         half_height = -1 * (((double)type->rsl.height / 1000) * tan(theta / 2));
//         half_width = ((double)type->rsl.width / 1000) * aspect * tan(theta / 2);
//     }
//     else
//     {
//         aspect = type->rsl.height / type->rsl.width;
//         half_height = -1 * (aspect * ((double)type->rsl.height / 1000) * tan(theta / 2));
//         half_width = ((double)type->rsl.width / 1000) * tan(theta / 2);
//     }

//     double s, t;
//     t_vector u;
//     t_vector v;
//     t_vector w = {0, 0, 1};
//     t_vector pixel;

//     t_vector lookfrom = {0, 0, 0};
//     t_vector lookat = {0, 0, -1};
//     t_vector Vup = {0, 1, 0};

//     type->ray.origin = lookfrom;

//     // w = vector_sub(&lookfrom, &lookat);
//     // w = unit_vector(&w);

//     u = vector_cross(&Vup, &w);
//     u = unit_vector(&u);

//     v = vector_cross(&w, &u);
//     // printf("|v.x ===> %f|\t|v.y ===> %f|\t|v.z ===> %f|\n",v.x, v.y, v.z);
//     /**************************************/

//     t_vector C;
//     t_vector L;

//     C.x = type->ray.origin.x - w.x;
//     C.y = type->ray.origin.y - w.y;
//     C.z = type->ray.origin.z - w.z;

//     L.x = C.x - u.x * half_width / 2 - v.x * half_height / 2;
//     L.y = C.y - u.y * half_width / 2 - v.y * half_height / 2;
//     L.z = C.z - u.z * half_width / 2 - v.z * half_height / 2;

//     pixel.x = L.x + u.x * type->rsl.x * half_width / type->rsl.width + v.x * type->rsl.y * half_height / type->rsl.height;
//     pixel.y = L.y + u.y * type->rsl.x * half_width / type->rsl.width + v.y * type->rsl.y * half_height / type->rsl.height;
//     pixel.z = L.z + u.z * type->rsl.x * half_width / type->rsl.width + v.z * type->rsl.y * half_height / type->rsl.height;

//     type->ray.direction.x = pixel.x - type->ray.origin.x;
//     type->ray.direction.y = pixel.y - type->ray.origin.y;
//     type->ray.direction.z = pixel.z - type->ray.origin.z;
//     type->ray.direction = unit_vector(&type->ray.direction);
// }

void half_w_h(t_data *type)
{
    double theta;
    double ratio;

    theta = type->camera->fov * PI / 180;
    if (type->rsl.width >= type->rsl.height)
    {
        ratio = type->rsl.width / type->rsl.height;
        type->rsl.half_height = -1 * (((double)type->rsl.height / 1000) * tan(theta / 2));
        type->rsl.half_width = ((double)type->rsl.width / 1000) * ratio * tan(theta / 2);
    }
    else
    {
        ratio = type->rsl.height / type->rsl.width;
        type->rsl.half_height = -1 * (ratio * ((double)type->rsl.height / 1000) * tan(theta / 2));
        type->rsl.half_width = ((double)type->rsl.width / 1000) * tan(theta / 2);
    }
}
t_vector calcul_pixel(t_data *type, t_vector left_corner, t_vector u, t_vector v)
{
    t_vector pixel_x;
    t_vector pixel_y;
    double x;
    double y;
    t_vector pixel;

    x =  type->rsl.x * type->rsl.half_width / type->rsl.width;
    y = type->rsl.y * type->rsl.half_height / type->rsl.height;
    pixel_x = vector_scal(x,u);
    // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n",pixel_x.x,pixel_x.y,pixel_x.z);

    pixel_y = vector_scal(y,v);

        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n",pixel_y.x,pixel_y.y,pixel_y.z);

    pixel = vector_add(pixel_x,pixel_y);
    pixel = vector_add(left_corner,pixel);
    return (pixel);
}

t_vector mapper_pixel(t_data *type, t_vector u, t_vector v, t_vector n)
{
    t_vector center;
    t_vector l;
    t_vector left_corner;


    center = vector_sub(type->camera->pos, n);
    l.x = u.x * type->rsl.half_width / 2 + v.x * type->rsl.half_height / 2;
    l.y = u.y * type->rsl.half_width / 2 + v.y * type->rsl.half_height / 2;
    l.z = u.z * type->rsl.half_width / 2 + v.z * type->rsl.half_height / 2;
    
    left_corner = vector_sub(center,l);
    return (calcul_pixel(type,left_corner,u,v));
}
void camera_setting(t_data *type)
{
    t_vector u;
    t_vector v;
    t_vector vup;
    t_vector n;


    vup = make_pos(0, 1, 0);
    n = vector_sub(type->camera->pos,type->camera->ort_vec);
    n = unit_vector(n);
    // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n",n.x,n.y,n.z);
    u = vector_cross(vup, n);
    u = unit_vector(u);
    // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n",u.x,u.y,u.z);


    v = vector_cross(n, u);

        // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n",v.x,v.y,v.z);


    half_w_h(type);
    type->camera->pixel = mapper_pixel(type, u, v, n);
    // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n",type->camera->pixel.x,type->camera->pixel.y,type->camera->pixel.z);

}

void ray(t_data *type)
{
    type->ray.origin = type->camera->pos;
    type->ray.direction = vector_sub(type->camera->pixel,type->ray.origin);
    type->ray.direction = unit_vector(type->ray.direction);
    // printf("x ===> %f|\t|y ===> %f|\t|z ===> %f|\n",type->ray.direction.x, type->ray.direction.y, type->ray.direction.z);

}