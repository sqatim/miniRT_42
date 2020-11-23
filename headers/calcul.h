/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:08:26 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/23 12:04:34 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_H
# define CALCUL_H

# include "minirt.h"

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
void		hit_objet(t_data *type, double *t1);
void		ray(t_data *type);
void		half_w_h(t_data *type);
void		calcul_pixel(t_data *type);
void		mapper_pixel(t_data *type);
void		camera_setting(t_data *type);
t_colour	phong(t_data *type, t_colour shadow);

#endif
