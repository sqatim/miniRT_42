/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objet.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 18:45:15 by thor              #+#    #+#             */
/*   Updated: 2020/11/04 12:23:34 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_OBJET_H
#define HIT_OBJET_H

#include "minirt.h"

double hit_sphere(t_objet *objet, t_ray *ray);
double hit_plane(t_objet *objet, t_ray *ray);
double hit_square(t_objet *objet, t_ray *ray);
double hit_cylinder(t_objet *objet, t_ray *ray);
double hit_triangle(t_objet *objet, t_ray *ray);
int hit_objet2(t_data *type, t_ray *ombre, t_objet *tmp);

#endif