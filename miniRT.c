/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:41:19 by sqatim            #+#    #+#             */
/*   Updated: 2020/10/30 10:29:02 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_colour coleur(t_data *type)
{
    t_colour black;
    t_colour phong_s;
    t_colour shadow1 = {1, 1, 1};
    t_objet *tmp;
    t_colour red = {255, 0, 0};

    // ghanrood screen b green bash ntesti 
    t_colour green = {0,255,0};
    tmp = type->objet;
    double t1 = FLT_MAX;
    black = make_number(black, 0);
    //  black = green ;//make_number(black, 0);
    hit_objet(type, &t1);
    // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n",type->objet->pos.x,type->objet->pos.y,type->objet->pos.z);
    if (type->tool.intersect == 1)
    {
         shadow1 = shadows(type, tmp);
        // printf("|r ====> %f|\t|g ====> %f|\t|b ====> %f|\n", shadow1.r,shadow1.g,shadow1.b);
        
        // anzid had blan

        phong_s = phong(type, shadow1);
        type->objet = tmp;
        // printf("|r ====> %f|\t|g ====> %f|\t|b ====> %f|\n", type->objet->colour.r,type->objet->colour.g,type->objet->colour.b);
        // printf("|r ====> %f|\t|g ====> %f|\t|b ====> %f|\n", phong_s.r,phong_s.g,phong_s.b);
        return (phong_s);
    }
    else
        return (black);
}
void screen_blue(t_data *type)
{
    t_colour colour = {0, 0, 0};
    int i = 0;

    type->rsl.x = 0;
    type->rsl.y = 0;
    while (type->rsl.y < type->rsl.height)
    {
        type->rsl.x = 0;
        while (type->rsl.x < type->rsl.width)
        {
            camera_setting(type);
            ray(type);
            colour = coleur(type);
            type->colour.r = (int)colour.r;
            type->colour.g = (int)colour.g;
            type->colour.b = (int)colour.b;
            type->mlx.img_data[i] = _3til_lbabaha(&type->colour);
            // mlx_pixel_put(type->mlx.mlx_ptr, type->mlx.win_ptr, type->rsl.x, type->rsl.y, _3til_lbabaha(&type->colour));
            // type->mlx.img_data[type->rsl.y * type->mlx.size_line+ type->rsl.x * 4] = _3til_lbabaha(&type->colour);
            // type->mlx.img_data[type->rsl.y * type->mlx.size_line+ type->rsl.x * 4+0] = (unsigned char)type->colour.b;
            // type->mlx.img_data[type->rsl.y * type->mlx.size_line+ type->rsl.x * 4+1] = (unsigned char)type->colour.g;
            // type->mlx.img_data[type->rsl.y * type->mlx.size_line+ type->rsl.x * 4+2] = (unsigned char)type->colour.r;
            type->rsl.x++;
            i++;
        }
        type->rsl.y++;
    }
}

int _3til_lbabaha(t_colour *data)
{
    return ((data->r * 256 * 256) + (data->g * 256) + data->b);
}