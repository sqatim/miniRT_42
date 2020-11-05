/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_function.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:53:15 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/05 11:56:21 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_FUNCTION_H
#define HIT_FUNCTION_H

#include "minirt.h"


double	hit_sphere(t_objet *objet, t_ray *ray);
double	hit_plane(t_objet *objet, t_ray *ray);
double	hit_square(t_objet *objet, t_ray *ray);
void	calcul_delta_cy(t_objet *objet, t_ray *ray, t_varCal *var);
double	hit_cylinder(t_objet *objet, t_ray *ray);
double	hit_triangle(t_objet *objet, t_ray *ray);

#endif