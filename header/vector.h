/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:17:26 by thor              #+#    #+#             */
/*   Updated: 2020/03/30 20:12:46 by thor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include "minirt.h"

double vector_dot(t_vector v1, t_vector v2);
t_vector vector_sub(t_vector v1, t_vector v2);
t_vector vector_scal(double c, t_vector v);
t_vector vector_add(t_vector v1, t_vector v2);
t_vector vector_cross(t_vector v1, t_vector v2);
t_vector unit_vector(t_vector v);
double vector_length(t_vector v);
t_vector vector_prd(t_vector v1, t_vector v2);
t_vector make_pos(double x, double y, double z);

#endif