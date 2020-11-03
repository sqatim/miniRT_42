/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:10:34 by thor              #+#    #+#             */
/*   Updated: 2020/11/03 14:28:50 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_print(t_data *type, char *name, int number)
{
    ft_putstr_fd(name, 1);
    ft_putstr_fd(" : line ", 1);
    ft_putnbr_fd(type->parcing.error, 1);
    if (number == 1)
        ft_putstr_fd(" : miss element\n", 1);
    else if (number == 2)
        ft_putstr_fd(" : an error in pos\n", 1);
    else if (number == 3)
        ft_putstr_fd(" : an error in orientation vector\n", 1);
    else if (number == 4)
        ft_putstr_fd(" : an error in rgb\n", 1);
    else if (number == 5)
        ft_putstr_fd(" : an error in rgb\n", 1);
}
int element_miss(t_data *type, int object)
{
    if (object == resolution_d)
        ft_print(type, "Resolution", 1);
    else if (object == ambient_d)
        ft_print(type, "Ambient", 1);
    else if (object == light_d)
        ft_print(type, "Light", 1);
    else if (object == camera_d)
        ft_print(type, "Camera", 1);
    else if (object == sphere_d)
        ft_print(type, "Sphere", 1);
    else if (object == plane_d)
        ft_print(type, "Plane", 1);
    else if (object == square_d)
        ft_print(type, "Square", 1);
    else if (object == cylinder_d)
        ft_print(type, "Cylinder", 1);
    else if (object == triangle_d)
        ft_print(type, "Triangle", 1);
    exit(0);
}

int wrong_pos(t_data *type, int object)
{

    if (object == light_d)
        write(1, "Light : an error in pos\n", 24);
    else if (object == camera_d)
        write(1, "Camera : an error in pos\n", 25);
    else if (object == sphere_d)
        write(1, "Sphere : an error in pos\n", 25);
    else if (object == plane_d)
        write(1, "Plane : an error in pos\n", 24);
    else if (object == square_d)
        write(1, "Square : an error in pos\n", 25);
    else if (object == cylinder_d)
        write(1, "Cylinder : an error in pos\n", 27);
    else if (object == triangle_d)
        write(1, "Triangle : an error in pos\n", 27);
    exit(0);
}
int wrong_vec_ort(t_data *type, int object)
{
    ft_putnbr_fd(type->parcing.error, 1);
    if (object == camera_d)
        write(1, "camera : an error in orientation vector\n", 40);
    else if (object == plane_d)
        write(1, "Plane : an error in orientation vector\n", 39);
    else if (object == square_d)
        write(1, "Square : an error in orientation vector\n", 40);
    else if (object == cylinder_d)
        write(1, "Cylinder : an error in orientation vector\n", 42);
    exit(0);
}

int wrong_rgb(t_data *type, int object)
{
    if (object == ambient_d)
        write(1, "Ambient : an error in rgb\n", 26);
    else if (object == light_d)
        write(1, "Light : an error in rgb\n", 24);
    else if (object == sphere_d)
        write(1, "Sphere : an error in rgb\n", 25);
    else if (object == plane_d)
        write(1, "Plane : an error in rgb\n", 24);
    else if (object == square_d)
        write(1, "Square : an error in rgb\n", 25);
    else if (object == cylinder_d)
        write(1, "Cylinder : an error in rgb\n", 27);
    else if (object == triangle_d)
        write(1, "Triangle : an error in rgb\n", 27);
    ft_putnbr_fd(type->parcing.error, 1);
    exit(0);
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
int check_resolution(t_data *type, char **parc)
{
    int i;

    i = 0;
    if (ft_2strlen(parc) != 3)
        return (element_miss(type, resolution_d));
    else if (check_numb(parc[1]) == 0 || check_numb(parc[2]) == 0 || ft_atoi(parc[1]) == 0 || ft_atoi(parc[2]) == 0)
    {
        if (check_numb(parc[1]) == 0 || ft_atoi(parc[1]) == 0)
            write(1, "Resolution : an error in width\n", 31);
        else if (check_numb(parc[2]) == 0 || ft_atoi(parc[2]) == 0)
            write(1, "Resolution : an error in height\n", 32);
        exit(0);
    }
    if (type->parcing.r == 1)
    {
        write(1, "You must declare just one Resolution\n", 37);
        exit(0);
    }
    return (resolution_d);
}

int check_ambient(t_data *type, char **parc)
{
    if (ft_2strlen(parc) != 3)
        return (element_miss(type, ambient_d));
    else if (check_double(parc[1]) == 0 || (ft_atod(parc[1]) < 0 || ft_atod(parc[1]) > 1))
    {
        write(1, "Ambient : an error in intensity\n", 32);
        exit(0);
    }
    else if (check_rgb(parc[2]) == 0)
        return (wrong_rgb(type, ambient_d));
    if (type->parcing.a == 1)
    {
        write(1, "You must declare just one Ambient\n", 34);
        exit(0);
    }
    return (ambient_d);
}

int check_light(t_data *type, char **parc)
{
    if (ft_2strlen(parc) != 4)
        return (element_miss(type, light_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(type, light_d));
    else if (check_double(parc[2]) == 0 || (ft_atod(parc[2]) < 0 || ft_atod(parc[2]) > 1))
    {
        write(1, "Light : an error in intensity\n", 30);
        exit(0);
    }
    else if (check_rgb(parc[3]) == 0)
        return (wrong_rgb(type, light_d));
    return (light_d);
}

int check_sphere(t_data *type, char **parc)
{
    if (ft_2strlen(parc) != 4)
        return (element_miss(type, sphere_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(type, sphere_d));
    else if (check_double(parc[2]) == 0 || ft_atod(parc[2]) < 0)
    {
        write(1, "Sphere : an error in radius\n", 28);
        exit(0);
    }
    else if (check_rgb(parc[3]) == 0)
        return (wrong_rgb(type, sphere_d));
    return (sphere_d);
}

int check_plane(t_data *type, char **parc)
{
    if (ft_2strlen(parc) != 4)
        return (element_miss(type, plane_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(type, plane_d));
    else if (check_vec_ort(parc[2]) == 0)
        return (wrong_vec_ort(type, plane_d));
    else if (check_rgb(parc[3]) == 0)
        return (wrong_rgb(type, plane_d));
    return (plane_d);
}

int check_square(t_data *type, char **parc)
{
    if (ft_2strlen(parc) != 5)
        return (element_miss(type, square_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(type, square_d));
    else if (check_vec_ort(parc[2]) == 0)
        return (wrong_vec_ort(type, square_d));
    else if (check_double(parc[3]) == 0 || ft_atod(parc[3]) < 0)
    {
        write(1, "Square : an error in height\n", 28);
        ft_putnbr_fd(type->parcing.error, 1);
        exit(0);
    }
    else if (check_rgb(parc[4]) == 0)
        return (wrong_rgb(type, square_d));
    return (square_d);
}

int check_cylinder(t_data *type, char **parc)
{
    if (ft_2strlen(parc) != 6)
        return (element_miss(type, cylinder_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(type, cylinder_d));
    else if (check_vec_ort(parc[2]) == 0)
        return (wrong_vec_ort(type, cylinder_d));
    else if (check_rgb(parc[3]) == 0)
        return (wrong_rgb(type, cylinder_d));
    else if (check_double(parc[4]) == 0 || ft_atod(parc[4]) < 0)
    {
        write(1, "Cylinder : an error in radius\n", 30);
        ft_putnbr_fd(type->parcing.error, 1);
        exit(0);
    }
    else if (check_double(parc[5]) == 0 || ft_atod(parc[5]) < 0)
    {
        write(1, "Cylinder : an error in height\n", 30);
        ft_putnbr_fd(type->parcing.error, 1);
        exit(0);
    }
    return (cylinder_d);
}

int check_triangle(t_data *type, char **parc)
{
    if (ft_2strlen(parc) != 5)
        return (element_miss(type, triangle_d));
    else if (check_pos(parc[1]) == 0 || check_pos(parc[2]) == 0 || check_pos(parc[3]) == 0)
        return (wrong_pos(type, triangle_d));
    else if (check_rgb(parc[4]) == 0)
        return (wrong_rgb(type, triangle_d));
    return (triangle_d);
}

int check_camera(t_data *type, char **parc)
{
    if (ft_2strlen(parc) != 4)
        return (element_miss(type, camera_d));
    else if (check_pos(parc[1]) == 0)
        return (wrong_pos(type, camera_d));
    else if (check_vec_ort(parc[2]) == 0)
        return (wrong_vec_ort(type, camera_d));
    else if (check_double(parc[3]) == 0 || (ft_atod(parc[3]) < 0 || ft_atod(parc[3]) > 180))
    {
        write(1, "camera : an error in fov\n", 30);
        exit(0);
    }
    return (camera_d);
}
int check_element(t_data *type, char **parc, int check, int ligne_err)
{
    if (check == resolution_d)
        return (check_resolution(type, parc));
    else if (check == ambient_d)
        return (check_ambient(type, parc));
    else if (check == camera_d)
        return (check_camera(type, parc));
    else if (check == light_d)
        return (check_light(type, parc));
    else if (check == sphere_d)
        return (check_sphere(type, parc));
    else if (check == plane_d)
        return (check_plane(type, parc));
    else if (check == square_d)
        return (check_square(type, parc));
    else if (check == cylinder_d)
        return (check_cylinder(type, parc));
    else
        return (check_triangle(type, parc));
}

void check_type(t_data *type, char **parc)
{
    if (ft_strnstr("R", parc[0], 2))
        type->parcing.check = resolution_d;
    else if (ft_strnstr("A", parc[0], 2))
        type->parcing.check = ambient_d;
    else if (ft_strnstr("c", parc[0], 2))
        type->parcing.check = camera_d;
    else if (ft_strnstr("l", parc[0], 2))
        type->parcing.check = light_d;
    else if (ft_strnstr("sp", parc[0], 3))
        type->parcing.check = sphere_d;
    else if (ft_strnstr("pl", parc[0], 3))
        type->parcing.check = plane_d;
    else if (ft_strnstr("sq", parc[0], 3))
        type->parcing.check = square_d;
    else if (ft_strnstr("cy", parc[0], 3))
        type->parcing.check = cylinder_d;
    else if (ft_strnstr("tr", parc[0], 3))
        type->parcing.check = triangle_d;
    else
    {
        write(1, "You must start with type\n", 25);
        type->parcing.check = 0;
    }
}