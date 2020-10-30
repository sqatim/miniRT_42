/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 19:23:04 by thor              #+#    #+#             */
/*   Updated: 2020/10/30 13:03:46 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void parc_resl(t_data *type, char *line)
{
    char **res = ft_split(line, ' ');
    type->rsl.width = ft_atoi(res[1]);
    type->rsl.height = ft_atoi(res[2]);
}
t_colour r_g_b(char *r, char *g, char *b)
{
    t_colour extr;

    extr.r = ft_atod(r);
    extr.g = ft_atod(g);
    extr.b = ft_atod(b);

    return (extr);
}
t_vector x_y_z(char *x, char *y, char *z)
{
    t_vector extr;

    extr.x = ft_atod(x);
    extr.y = ft_atod(y);
    extr.z = ft_atod(z);

    return (extr);
}
void parc_amb(t_data *type, char *line)
{
    char **amb;
    char **rgb;

    amb = ft_split(line, ' ');
    rgb = ft_split(amb[2], ',');

    type->ambient.int_amb = ft_atod(amb[1]);
    type->ambient.rgb_amb = r_g_b(rgb[0], rgb[1], rgb[2]);
    type->ambient.rgb_amb = make_range(type->ambient.rgb_amb);
}

void parc_camera(t_data *type, char *line)
{
    char **camera;
    char **pos;
    char **ort_vec;
    double fov;

    camera = ft_split(line, ' ');
    pos = ft_split(camera[1], ',');
    ort_vec = ft_split(camera[2], ',');
    fov = ft_atod(camera[3]);

    type->camera = add_camera(type, pos, ort_vec, fov);
}

void parc_light(t_data *type, char *line)
{
    char **light;
    char **rgb;
    char **pos;
    double int_light;

    light = ft_split(line, ' ');
    pos = ft_split(light[1], ',');
    rgb = ft_split(light[3], ',');
    int_light = ft_atod(light[2]);

    type->light = add_light(type, pos, int_light, rgb);
}

void parc_sphere(t_data *type, char *line)
{
    char **sphere;
    char **pos;
    char **colour;
    double diametre;

    sphere = ft_split(line, ' ');
    pos = ft_split(sphere[1], ',');
    colour = ft_split(sphere[3], ',');
    diametre = ft_atod(sphere[2]);

    type->objet = add_sphere(type, pos, colour, diametre);
}

void parc_plane(t_data *type, char *line)
{
    char **plane;
    char **pos;
    char **vector;
    char **colour;

    plane = ft_split(line, ' ');
    pos = ft_split(plane[1], ',');
    vector = ft_split(plane[2], ',');
    colour = ft_split(plane[3], ',');

    type->objet = add_plane(type, pos, vector, colour);
}

void parc_square(t_data *type, char *line)
{
    char **square;
    char **pos;
    char **normal;

    square = ft_split(line, ' ');
    pos = ft_split(square[1], ',');
    normal = ft_split(square[2], ',');

    type->objet = add_square(type, pos, normal, square);
}

void parc_cylinder(t_data *type, char *line)
{
    char **cylinder;
    char **pos;
    char **v;

    cylinder = ft_split(line, ' ');
    pos = ft_split(cylinder[1], ',');
    v = ft_split(cylinder[2], ',');

    type->objet = add_cylinder(type, pos, v, cylinder);
}

void parc_triangle(t_data *type, char *line)
{
    char **triangle;
    char **pos;
    char **pos1;
    char **pos2;

    triangle = ft_split(line, ' ');
    pos = ft_split(triangle[1], ',');
    pos1 = ft_split(triangle[2], ',');
    type->objet = add_triangle(type, pos, pos1, triangle);
}
int parcing_check(char *line, int ligne_err)
{
    int i = 0;
    int check = -1;
    int f;
    char **parc = ft_split(line, ' ');
    if (ft_isalpha(line[0]))
        check = check_type(parc);
    if (check == 0)
    {
        write(1, "t2akad man type line ", 21);
        ft_putnbr_fd(ligne_err, 1);
        return (0);
    }
    else if (check != 0 && check != -1)
    {
        f = check_element(parc, check, ligne_err);
        return (f);
    }
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t')
        {
            write(1, "You must start with type\n", 25);
            return (0);
        }
        i++;
    }
    return (-1);
}
void parcing(t_data *type, char **av)
{

    int fd = open(av[1], O_RDONLY);
    char *line;
    char **parc;
    int r;
    int ligne_err = 0;
    int ss = -1;
    int k = 0;
    while ((r = get_next_line(fd, &line)) > 0 && k != 1)
    {
        ligne_err++;
        ss = parcing_check(line, ligne_err);
        if (ss == resolution_d)
            parc_resl(type, line);
        else if (ss == ambient_d)
            parc_amb(type, line);
        else if (ss == camera_d)
            parc_camera(type, line);
        else if (ss == light_d)
            parc_light(type, line);
        else if (ss == camera_d)
            parc_camera(type, line);
        else if (ss == sphere_d)
            parc_sphere(type, line);
        else if (ss == plane_d)
            parc_plane(type, line);
        else if (ss == square_d)
            parc_square(type, line);
        else if (ss == cylinder_d)
            parc_cylinder(type, line);
        else if (ss == triangle_d)
            parc_triangle(type, line);
        else if (ss == 0)
            exit(0);
        // if(r == 0)
        // {
        //     write(1,"bullshit\n",9);
        //     k = 1;
        // }
    }
    if (r == -1)
    {
        exit(1);
    }
}