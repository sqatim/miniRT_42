/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:22:20 by sqatim            #+#    #+#             */
/*   Updated: 2020/10/26 14:40:46 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minirt.h"
#include "mlx.h"

static int check_objet(int type)
{
    if (type == sphere_d || type == plane_d || type == square_d || type == cylinder_d || type == triangle_d)
        return (1);
    return (0);
}
int hook_element(t_data *type, int key)
{
    if (key == 99)
    {
        type->key.type = camera_d;
        return (1);
    }
    if (key == 111) // objet
    {
        type->key.type = type->clo.objet->type;
        return (1);
    }
    if (key == 108)
    {
        type->key.type = light_d;
        return (1);
    }
    return (0);
}
int check_trans_rot(t_data *type, int key)
{
    if (key == 116) // translation
        type->key.tr_rt = 0;
    if (key == 114) // rotation
        type->key.tr_rt = 1;
    return (1);
}
int check_direction(t_data *type, int key)
{
    if (key == right)
        return (1);
    if (key == left)
        return (1);
    if (key == up)
        return (1);
    if (key == down)
        return (1);
    if (key == back)
        return (1);
    if (key == ahead)
        return (1);
    return (0);
}
void trans_rot(t_data *type)
{
    if (type->key.tr_rt == 0)
    {
        if (type->key.key == right || type->key.key == left)
            translation_r_l(type);
        if (type->key.key == up || type->key.key == down)
            translation_u_d(type);
        if (type->key.key == ahead || type->key.key == back)
            translation_a_b(type);
    }
    if (type->key.tr_rt == 1)
    {
        if (type->key.key == right || type->key.key == left)
            rotation_r_l(type);
        if (type->key.key == up || type->key.key == down)
            rotation_u_d(type);
        if (type->key.key == ahead || type->key.key == back)
        {
            rotation_a_b(type);
        }
    }
}
void change_element(t_data *type)
{

    if (type->key.key == 97)
    {
        if (type->key.type == camera_d && type->clo.camera->previous != NULL)
            type->clo.camera = type->clo.camera->previous;
        else if (check_objet(type->clo.objet->type) && type->clo.objet->previous != NULL)
            type->clo.objet = type->clo.objet->previous;
        else if (type->key.type == light_d && type->clo.light->previous != NULL)
            type->clo.light = type->clo.light->previous;
    }
    else if (type->key.key == 100)
    {
        if (type->key.type == camera_d && type->clo.camera->next != NULL)
            type->clo.camera = type->clo.camera->next;
        else if (check_objet(type->clo.objet->type) && type->clo.objet->next != NULL)
            type->clo.objet = type->clo.objet->next;
        else if (type->key.type == light_d && type->clo.light->next != NULL)
            type->clo.light = type->clo.light->next;
    }
}
int key_hook(int key, t_data *type)
{

    printf("%d\n", key);
    // if (hook_element(type, key)) // c
    //     type->key.check = 1;
    if (type->key.check == 1 && check_trans_rot(type, key))
        type->key.check = 1;
    if (type->key.check == 1 && check_direction(type, key))
    {
        type->key.key = key;
        trans_rot(type);
    }
    if (type->key.check == 1 && (key == 97 || key == 100)) // 97 == a && 100 == d
    {
        type->key.key = key;
        change_element(type);
    }
    if (key == 65307)
        exit(0);
    screen_blue(type);

     //mlx_key_hook(type->mlx.win_ptr, key_hook, type);
    mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr, type->mlx.img_ptr, 0, 0);

    return (0);
}

int create_bmp(t_data *type)
{
    int fd;
    int file_size;
    int first_pix;
    /*******/
    int header_info_size;
    int plane_nbr;
    int o_count;
    /*********/
    int i;
    int c;
    int size_line;
    /********/

    fd = open("sam.bmp", O_CREAT | O_RDWR);
    file_size = 14 + 40 + 4 + (type->rsl.width * type->rsl.height) * 4;
    first_pix = 14 + 40 + 4;
    header_info_size = 40;
    plane_nbr = 1;

    /*******/
    write(fd, "BM", 2);
    write(fd, &file_size, 4);
    write(fd, "\0\0\0\0", 4);
    write(fd, &first_pix, 4);
    /********/
    write(fd, &header_info_size, 4);
    write(fd, &type->rsl.width, 4);
    write(fd, &type->rsl.height, 4);
    write(fd, &plane_nbr, 2);
    write(fd, &type->mlx.bpp, 2);
    o_count = 0;
    while (o_count < 28)
    {
        write(fd, "\0", 1);
        o_count++;
    }
    i = type->rsl.width * type->rsl.height;
    int size_line2;
    int k;
    int save;

    type->mlx.size_line /= 4;
    i = 0;
    int j = 0;
    while (i < type->rsl.height)
    {
        c = 0;
        size_line2 = type->mlx.size_line;
        while (c < size_line2 && c != size_line2)
        {
            save = type->mlx.img_data[c + (i * type->mlx.size_line)];
            type->mlx.img_data[c + (i * type->mlx.size_line)] = type->mlx.img_data[size_line2 + (i * type->mlx.size_line - 1)];
            type->mlx.img_data[size_line2 + (i * type->mlx.size_line - 1)] = save;
            c++;
            size_line2 -= 1;
        }
        i++;
    }

    i = type->rsl.width * type->rsl.height;
    while (i > 0)
    {
        write(fd, &type->mlx.img_data[i], 4);
        i--;
    }
    return (1);
}

void ft_mlx(t_data *type)
{
    int bpp;
    int size_line;
    int endian;

    // if(!(type->mlx.mlx_ptr = mlx_init()))
    //     return (NULL);
    // if(!(type->mlx.img_ptr = mlx_new_image(type->mlx.mlx_ptr, type->rsl.width, type->rsl.height)))
    //     return (NULL);
    // if(!(type->mlx.tab = (int *)mlx_get_data_addr(type->mlx.img_ptr, &bpp, &size_line, &endian)))
    //     return (NULL);
    // if(!(type->mlx.win_ptr = mlx_new_window(type->mlx.mlx_ptr, type->rsl.width, type->rsl.height, "samir")))
    //     return (NULL);
    type->mlx.mlx_ptr = mlx_init();
    type->mlx.img_ptr = mlx_new_image(type->mlx.mlx_ptr, type->rsl.width, type->rsl.height);
    type->mlx.img_data = (int *)mlx_get_data_addr(type->mlx.img_ptr, &type->mlx.bpp, &type->mlx.size_line, &endian);

    screen_blue(type);
    type->mlx.win_ptr = mlx_new_window(type->mlx.mlx_ptr, type->rsl.width, type->rsl.height, "samir");
    mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr, type->mlx.img_ptr, 0, 0);
    mlx_key_hook(type->mlx.win_ptr, key_hook, type);
    // create_bmp(type);
    mlx_loop(type->mlx.mlx_ptr);
}

int main(int ac, char **av)
{
    t_data type;

    ft_bzero(&type, sizeof(t_data));
    parcing(&type, av);
    type.clo.objet = type.objet;
    type.clo.camera = type.camera;
    type.clo.light = type.light;
    // printf("|x ===> %f|\t|y ===> %f|\t|z ===> %f|\n", type.camera->ort_vec.x, type.camera->ort_vec.y, type.camera->ort_vec.z);
    ft_mlx(&type);

    // type.mlx.mlx_ptr = mlx_init();
    // type.mlx.img_ptr = mlx_new_image( type.mlx.mlx_ptr,type.rsl.width,type.rsl.height);
    // type.mlx.tab =(int *) mlx_get_data_addr(type.mlx.img_ptr,&bpp,&size_line,&endian);
    // screen_blue(&type);
    // type.mlx.win_ptr = mlx_new_window(type.mlx.mlx_ptr, type.rsl.width, type.rsl.height, "samir");
    // mlx_put_image_to_window(type.mlx.mlx_ptr,type.mlx.win_ptr,type.mlx.img_ptr,0,0);
    // // mlx_key_hook(type.mlx.win_ptr, key_hook, &type);
    // mlx_loop(type.mlx.mlx_ptr);
    return (0);
}
