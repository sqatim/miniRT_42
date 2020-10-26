/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:34:49 by thor              #+#    #+#             */
/*   Updated: 2020/03/25 20:19:12 by thor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
#define PARCING_H

#include "minirt.h"

void parcing(t_data *type, char **av);
void parc_cylinder(t_data *type, char *line);
void parc_square(t_data *type, char *line);
void parc_plane(t_data *type, char *line);
void parc_sphere(t_data *type, char *line);
void parc_light(t_data *type, char *line);
void parc_amb(t_data *type, char *line);
void parc_resl(t_data *type, char *line);
void parc_triangle(t_data *type, char *line);


#endif