/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:10:34 by thor              #+#    #+#             */
/*   Updated: 2020/03/28 17:42:22 by thor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int element_miss(int type)
{
    if (type == resolution_d)
        write(1, "Resolution : miss element\n", 26);
    else if (type == ambient_d)
        write(1, "Ambient : miss element\n", 23);
    else if (type == light_d)
        write(1, "Light : miss element\n", 21);
    else if (type == camera_d)
        write(1, "Camera : miss element\n", 22);
    else if (type == sphere_d)
        write(1, "Sphere : miss element\n", 22);
    else if (type == plane_d)
        write(1, "Plane : miss element\n", 21);
    else if (type == square_d)
        write(1, "Square : miss element\n", 22);
    else if (type == cylinder_d)
        write(1, "Cylinder : miss element\n", 24);
    else if (type == triangle_d)
        write(1, "Triangle : miss element\n", 24);
    return (0);
}

int wrong_pos(int type)
{

    if (type == light_d)
        write(1, "Light : an error in pos\n", 24);
    else if (type == camera_d)
        write(1, "Camera : an error in pos\n", 25);
    else if (type == sphere_d)
        write(1, "Sphere : an error in pos\n", 25);
    else if (type == plane_d)
        write(1, "Plane : an error in pos\n", 24);
    else if (type == square_d)
        write(1, "Square : an error in pos\n", 25);
    else if (type == cylinder_d)
        write(1, "Cylinder : an error in pos\n", 27);
    else if (type == triangle_d)
        write(1, "Triangle : an error in pos\n", 27);
    return (0);
}
int wrong_vec_ort(int type)
{
    if (type == camera_d)
        write(1, "camera : an error in orientation vector\n", 40);
    else if (type == plane_d)
        write(1, "Plane : an error in orientation vector\n", 39);
    else if (type == square_d)
        write(1, "Square : an error in orientation vector\n", 40);
    else if (type == cylinder_d)
        write(1, "Cylinder : an error in orientation vector\n", 42);
    return (0);
}

int wrong_rgb(int type)
{
    if (type == ambient_d)
        write(1, "Ambient : an error in rgb\n", 26);
    else if (type == light_d)
        write(1, "Light : an error in rgb\n", 24);
    else if (type == sphere_d)
        write(1, "Sphere : an error in rgb\n", 25);
    else if (type == plane_d)
        write(1, "Plane : an error in rgb\n", 24);
    else if (type == square_d)
        write(1, "Square : an error in rgb\n", 25);
    else if (type == cylinder_d)
        write(1, "Cylinder : an error in rgb\n", 27);
    else if (type == triangle_d)
        write(1, "Triangle : an error in rgb\n", 27);
    return (0);
}

int check_numb(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) != 1)
            return (0);
        i++;
    }
    return (1);
}

int check_double(char *str)
{
    int i;
    int check;

    i = 0;
    check = 0;
    if (str[0] == '\0')
        return (0);
    if (str[0] == '-')
        i++;
    while (str[i])
    {
        if (ft_isdigit(str[i]) != 1 && str[i] != '.')
            return (0);
        if (str[i] == '.')
        {
            if (check == 1)
                return (0);
            check = 1;
        }
        i++;
    }
    return (1);
}
int err_write(int check, int element)
{
    if (check == 0)
    {
        if (element == 0)
            printf("%s\n", "check normal a sat");
        else if (element == 1)
            printf("%s\n", "check rgb a sat");
    }
    else
    {
        if (element == 0)
            printf("%s\n", "normal must be betwin [0,1]");
        else if (element == 1)
            printf("%s\n", "rgb must be betwin [0,255]");
    }
    return (0);
}
int check_rgb(char *parc)
{
    char **rgb;
    int check;

    rgb = ft_split(parc, ',');
    if (ft_2strlen(rgb) != 3)
        return (0);
    if ((check = check_double(rgb[0])) == 0 || (ft_atod(rgb[0]) < 0.0 || ft_atod(rgb[0]) > 255.0))
        return (0);
    if ((check = check_double(rgb[1])) == 0 || (ft_atod(rgb[1]) < 0.0 || ft_atod(rgb[1]) > 255.0))
        return (0);
    if ((check = check_double(rgb[2])) == 0 || (ft_atod(rgb[2]) < 0.0 || ft_atod(rgb[2]) > 255.0))
        return (0);
    return (1);
}

int check_pos(char *parc)
{
    char **pos;

    pos = ft_split(parc, ',');
    if (ft_2strlen(pos) != 3)
        return (0);
    if (check_double(pos[0]) == 0 || check_double(pos[1]) == 0 || check_double(pos[2]) == 0)
        return (0);
    return (1);
}
int check_vec_ort(char *parc)
{
    char **vec_ort;
    int check;

    vec_ort = ft_split(parc, ',');
    if (ft_2strlen(vec_ort) != 3)
        return (0);
    if ((check = check_double(vec_ort[0])) == 0 || (ft_atod(vec_ort[0]) < -1.0 || ft_atod(vec_ort[0]) > 1.0))
        return (0);
    if ((check = check_double(vec_ort[1])) == 0 || (ft_atod(vec_ort[1]) < -1.0 || ft_atod(vec_ort[1]) > 1.0))
        return (0);
    if ((check = check_double(vec_ort[2])) == 0 || (ft_atod(vec_ort[2]) < -1.0 || ft_atod(vec_ort[2]) > 1.0))
        return (0);
    return (1);
}
int check_resolution(char **parc)
{
    int i;
    i = 0;
    if (ft_2strlen(parc) != 3)
        return (element_miss(resolution_d));
     else if (check_numb(parc[1]) == 0 || check_numb(parc[2]) == 0)
    {
        if (check_numb(parc[1]) == 0)
            write(1, "Resolution : an error in width\n", 31);
        else if (check_numb(parc[2]) == 0)
            write(1, "Resolution : an error in height\n", 32);
        return (0);
    }
    return (resolution_d);
}

int check_ambient(char **parc)
{
    if (ft_2strlen(parc) != 3)
        return (element_miss(ambient_d));
    else if (check_double(parc[1]) == 0 || ft_atod(parc[1]) < 0)
    {
        write(1, "Ambient : an error in intensity\n", 32);
        return (0);
    }
    else if (check_rgb(parc[2]) == 0)
        return (wrong_rgb(ambient_d));
    return (ambient_d);
}

int check_light(char **parc)
{
    if (ft_2strlen(parc) != 4)
        return (element_miss(light_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(light_d));
    else if (check_double(parc[2]) == 0 || ft_atod(parc[2]) < 0)
    {
        write(1, "Light : an error in intensity\n", 30);
        return (0);
    }
    else if (check_rgb(parc[3]) == 0)
        return (wrong_rgb(light_d));
    return (light_d);
}

int check_sphere(char **parc)
{
    if (ft_2strlen(parc) != 4)
        return (element_miss(sphere_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(sphere_d));
    else if (check_double(parc[2]) == 0 || ft_atod(parc[2]) < 0)
    {
        write(1, "Sphere : an error in radius\n", 28);
        return (0);
    }
    else if (check_rgb(parc[3]) == 0)
        return (wrong_rgb(sphere_d));
    return (sphere_d);
}

int check_plane(char **parc)
{
    if (ft_2strlen(parc) != 4)
        return (element_miss(plane_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(plane_d));
    else if (check_vec_ort(parc[2]) == 0)
        return (wrong_vec_ort(plane_d));
    else if (check_rgb(parc[3]) == 0)
        return (wrong_rgb(plane_d));
    return (plane_d);
}

int check_square(char **parc)
{
    if (ft_2strlen(parc) != 5)
        return (element_miss(square_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(square_d));
    else if (check_vec_ort(parc[2]) == 0)
        return (wrong_vec_ort(square_d));
    else if (check_double(parc[3]) == 0 || ft_atod(parc[3]) < 0)
    {
        write(1, "Square : an error in height\n", 28);
        return (0);
    }
    else if (check_rgb(parc[4]) == 0)
        return (wrong_rgb(square_d));
    return (square_d);
}

int check_cylinder(char **parc)
{
    if (ft_2strlen(parc) != 6)
        return (element_miss(cylinder_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(cylinder_d));
    else if (check_vec_ort(parc[2]) == 0)
        return (wrong_vec_ort(cylinder_d));
    else if (check_rgb(parc[3]) == 0)
        return (wrong_rgb(cylinder_d));
    else if (check_double(parc[4]) == 0 || ft_atod(parc[4]) < 0)
    {
        write(1, "Cylinder : an error in radius\n", 30);
        return (0);
    }
    else if (check_double(parc[5]) == 0 || ft_atod(parc[5]) < 0)
    {
        write(1, "Cylinder : an error in height\n", 30);
        return (0);
    }
    return (cylinder_d);
}

int check_triangle(char **parc)
{
    if (ft_2strlen(parc) != 5)
        return (element_miss(triangle_d));
    else if (check_pos(parc[1]) == 0 || check_pos(parc[2]) == 0 || check_pos(parc[3]) == 0)
        return (wrong_pos(triangle_d));
    else if (check_rgb(parc[4]) == 0)
        return (wrong_rgb(triangle_d));
    return (triangle_d);
}

int check_camera(char **parc)
{
    if (ft_2strlen(parc) != 4)
        return (element_miss(camera_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(camera_d));
    else if (check_vec_ort(parc[2]) == 0)
        return (wrong_vec_ort(camera_d));
    else if (check_double(parc[3]) == 0 || (ft_atod(parc[3]) < 0 || ft_atod(parc[3]) > 180))
    {
        write(1, "camera : an error in fov\n", 30);
        return (0);
    }
    return (camera_d);
}
int check_element(char **parc, int check, int ligne_err)
{
    int k;
    if (check == resolution_d)
        return (check_resolution(parc));
    else if (check == ambient_d)
        return (check_ambient(parc));
    else if (check == camera_d)
        return (check_camera(parc));
    else if (check == light_d)
        return (check_light(parc));
    else if (check == sphere_d)
        return (check_sphere(parc));
    else if (check == plane_d)
        return (check_plane(parc));
    else if (check == square_d)
        return (check_square(parc));
    else if (check == cylinder_d)
        return (check_cylinder(parc));
    else if (check == triangle_d)
        return (check_triangle(parc));
    return (0);
}

int check_type(char **parc)
{
    if (ft_strnstr("R", parc[0], 2))
        return (resolution_d);
    else if (ft_strnstr("A", parc[0], 2))
        return (ambient_d);
    else if (ft_strnstr("c", parc[0], 2))
        return (camera_d);
    else if (ft_strnstr("l", parc[0], 2))
        return (light_d);
    else if (ft_strnstr("sp", parc[0], 3))
        return (sphere_d);
    else if (ft_strnstr("pl", parc[0], 3))
        return (plane_d);
    else if (ft_strnstr("sq", parc[0], 3))
        return (square_d);
    else if (ft_strnstr("cy", parc[0], 3))
        return (cylinder_d);
    else if (ft_strnstr("tr", parc[0], 3))
        return (triangle_d);
    else
        return (0);
}