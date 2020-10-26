/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objet.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 18:45:15 by thor              #+#    #+#             */
/*   Updated: 2020/03/24 22:38:42 by thor             ###   ########.fr       */
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

#endif