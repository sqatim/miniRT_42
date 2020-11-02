/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_object.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:31:46 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/02 14:34:13 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_OBJECT_H
#define PARCING_OBJECT_H

#include "minirt.h"

void parc_sphere(t_data *type, char *line);
void parc_plane(t_data *type, char *line);
void parc_square(t_data *type, char *line);
void parc_cylinder(t_data *type, char *line);
void parc_triangle(t_data *type, char *line);

#endif