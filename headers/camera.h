/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 19:54:13 by thor              #+#    #+#             */
/*   Updated: 2020/11/16 17:10:05 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "minirt.h"

void		ray(t_data *type);
void		half_w_h(t_data *type);
t_vector	calcul_pixel(t_data *type, t_vector left_corner,\
				t_vector u, t_vector v);
t_vector	mapper_pixel(t_data *type, t_vector u, t_vector v, t_vector n);
void		camera_setting(t_data *type);

#endif
