/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:36:06 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/17 12:37:27 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_BONUS_H
# define CALCUL_BONUS_H

# include "minirt_bonus.h"

void		sphere_p_n(t_data *type);
void		plane_p_n(t_data *type);
void		square_p_n(t_data *type);
void		cylinder_p_n(t_data *type);
void		triangle_p_n(t_data *type);
double		hit_sphere(t_objet *objet, t_ray *ray);
double		hit_plane(t_objet *objet, t_ray *ray);
double		hit_square(t_objet *objet, t_ray *ray);
void		calcul_delta_cy(t_objet *objet, t_ray *ray, t_varcal *var);
double		hit_cylinder(t_objet *objet, t_ray *ray);
double		hit_triangle(t_objet *objet, t_ray *ray);
void		hit_objet2(t_data *type, t_ray *ombre, t_objet *tmp);
void		ray(t_data *type);
void		half_w_h(t_data *type);
t_vector	calcul_pixel(t_data *type, t_vector left_corner,\
				t_vector u, t_vector v);
t_vector	mapper_pixel(t_data *type, t_vector u, t_vector v, t_vector n);
void		camera_setting(t_data *type);
t_colour	phong(t_data *type, t_colour shadow);

#endif
