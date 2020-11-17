/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:00:09 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/17 12:14:56 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

double		vector_length(t_vector v)
{
	double result;

	result = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (result);
}

t_vector	unit_vector(t_vector v)
{
	t_vector result;

	result.x = v.x / vector_length(v);
	result.y = v.y / vector_length(v);
	result.z = v.z / vector_length(v);
	return (result);
}

t_vector	vector_cross(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

t_colour	make_range(t_colour rgb)
{
	t_colour result;

	result.r = rgb.r / 255;
	result.g = rgb.g / 255;
	result.b = rgb.b / 255;
	return (result);
}

t_vector	make_pos(double x, double y, double z)
{
	t_vector result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}
