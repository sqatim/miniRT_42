/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_objet.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:11:12 by thor              #+#    #+#             */
/*   Updated: 2020/10/19 14:23:56 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_OBJET_H
#define ALLOCATION_OBJET_H

#include "minirt.h"

t_objet *add_sphere(t_data *type, char **pos, char **colour, double diametre);
t_objet *add_plane(t_data *type, char **pos, char **normal, char **colour);
t_objet *add_square(t_data *type, char **pos, char **normal, char **square);
t_objet *add_cylinder(t_data *type, char **pos, char **normal, char **cylinder);
t_objet *add_triangle(t_data *type, char **pos, char **pos1, char **triangle);

#endif