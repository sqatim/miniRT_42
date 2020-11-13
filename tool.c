/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:59:19 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/13 14:41:39 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double to_double(const char *str, int i, int signe, double resultat)
{
    double sub;
    double dix;
    double div;

    dix = 10;
    div = 0;

    i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        sub = str[i] - '0';
        div = div + sub / dix;
        dix *= 10;
        i++;
    }

    return ((div + resultat) * signe);
}

double ft_atod(const char *str)
{
    int i;
    int sign;
    double result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' || str[i] == '\n' || str[i] == '\v' || str[i] == '\t')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1 * sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    if (str[i] == '.')
        return (to_double(str, i, sign, result));
    else
        return (result * sign);
}

int ft_2strlen(char **str)
{
    int i;

    i = 0;
    while (str[i] != 0)
        i++;
    return (i);
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

int free_exit(t_data *type, int wich)
{
    t_objet *tmp_o;
    t_camera *tmp_c;
    t_light *tmp_l;

    while (type->objet != NULL)
    {
        tmp_o = type->objet->next;
        free(type->objet);
        type->objet = NULL;
        type->objet = tmp_o;
    }
    while (type->camera != NULL)
    {
        tmp_c = type->camera->next;
        free(type->camera);
        type->camera = NULL;
        type->camera = tmp_c;
    }
    while (type->light != NULL)
    {
        tmp_l = type->light->next;
        free(type->light);
        type->light = NULL;
        type->light = tmp_l;
    }
    exit(wich);
}
