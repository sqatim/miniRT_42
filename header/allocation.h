/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 20:06:56 by thor              #+#    #+#             */
/*   Updated: 2020/03/28 03:17:47 by thor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_H
#define ALLOCATION_H

#include "minirt.h"

t_light *add_light(t_data *type, char **pos, double int_light,char **rgb);
t_camera *add_camera(t_data *type, char **pos, char **ort_vec,double fov);

#endif