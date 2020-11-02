/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 19:23:04 by thor              #+#    #+#             */
/*   Updated: 2020/11/02 14:49:43 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void parcing_tool(t_data *type, int indice, char *line)
{
    if (indice == resolution_d)
        parc_resl(type, line);
    else if (indice == ambient_d)
        parc_amb(type, line);
    else if (indice == camera_d)
        parc_camera(type, line);
    else if (indice == light_d)
        parc_light(type, line);
    else if (indice == camera_d)
        parc_camera(type, line);
    else if (indice == sphere_d)
        parc_sphere(type, line);
    else if (indice == plane_d)
        parc_plane(type, line);
    else if (indice == square_d)
        parc_square(type, line);
    else if (indice == cylinder_d)
        parc_cylinder(type, line);
    else if (indice == triangle_d)
        parc_triangle(type, line);
}

void parcing_check(t_data *type, char *line)
{
    int i;
    type->parcing.check = -1;
    type->parcing.indice = 0;
    char **parc = ft_space_split(line);

    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (ft_isalpha(line[i]))
    {
        check_type(type, parc);
        if (type->parcing.check == 0)
        {
            write(1, "t2akad man type line ", 21);
            ft_putnbr_fd(type->parcing.error, 1);
            exit(0);
        }
        else
            type->parcing.indice = check_element(parc, type->parcing.check, type->parcing.error);
    }
    else if (!ft_isalpha(line[i]) && line[i])
    {
        write(1, "t2akad man type line ", 21);
        exit(0);
    }
}

void parcing(t_data *type, char **av)
{
    int fd;
    char *line;
    char **parc;
    int r;

    fd = open(av[1], O_RDONLY);
    while ((r = get_next_line(fd, &line)) > 0)
    {
        type->parcing.error++;
        while ((line[0] == '\n' || line[0] == '\0') && r > 0)
        {
            type->parcing.error++;
            r = get_next_line(fd, &line);
        }
        if (r > 0)
        {
            parcing_check(type, line);
            parcing_tool(type, type->parcing.indice, line);
        }
    }
    if (r == 0)
    {
        parcing_check(type, line);
        parcing_tool(type, type->parcing.indice, line);
    }
    if (r == -1)
        exit(1);
}