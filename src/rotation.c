/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 12:22:12 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 10:12:35 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	convert_to_radian(t_vector angle)
{
	angle.x = angle.x * (PI / 180);
	angle.y = angle.y * (PI / 180);
	angle.z = angle.z * (PI / 180);
	return (angle);
}

t_vector	rot_vector(t_vector vect_ort, t_vector angle)
{
	t_vector vect;

	vect = vect_ort;
	angle = convert_to_radian(angle);
	vect_ort.y = vect.y * cos(angle.x) - vect.z * sin(angle.x);
	vect_ort.z = vect.y * sin(angle.x) + vect.z * cos(angle.x);
	vect = vect_ort;
	vect_ort.z = vect.z * cos(angle.y) - vect.x * sin(angle.y);
	vect_ort.x = vect.z * sin(angle.y) + vect.x * cos(angle.y);
	vect = vect_ort;
	vect_ort.x = vect.x * cos(angle.z) - vect.y * sin(angle.z);
	vect_ort.y = vect.x * sin(angle.z) + vect.y * cos(angle.z);
	vect_ort = unit_vector(vect_ort);
	return (vect_ort);
}
