/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:10:34 by thor              #+#    #+#             */
/*   Updated: 2020/11/16 13:14:59 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_element(t_data *type, char **parc, int check)
{
	if (check == RESOLUTION_D)
		return (check_resolution(type, parc));
	else if (check == AMBIENT_D)
		return (check_ambient(type, parc));
	else if (check == CAMERA_D)
		return (check_camera(type, parc));
	else if (check == LIGHT_D)
		return (check_light(type, parc));
	else if (check == SPHERE_D)
		return (check_sphere(type, parc));
	else if (check == PLANE_D)
		return (check_plane(type, parc));
	else if (check == SQUARE_D)
		return (check_square(type, parc));
	else if (check == CYLINDER_D)
		return (check_cylinder(type, parc));
	else
		return (check_triangle(type, parc));
}

void	check_type(t_data *type, char **parc)
{
	if (ft_strnstr("R", parc[0], 2))
		type->parcing.check = RESOLUTION_D;
	else if (ft_strnstr("A", parc[0], 2))
		type->parcing.check = AMBIENT_D;
	else if (ft_strnstr("c", parc[0], 2))
		type->parcing.check = CAMERA_D;
	else if (ft_strnstr("l", parc[0], 2))
		type->parcing.check = LIGHT_D;
	else if (ft_strnstr("sp", parc[0], 3))
		type->parcing.check = SPHERE_D;
	else if (ft_strnstr("pl", parc[0], 3))
		type->parcing.check = PLANE_D;
	else if (ft_strnstr("sq", parc[0], 3))
		type->parcing.check = SQUARE_D;
	else if (ft_strnstr("cy", parc[0], 3))
		type->parcing.check = CYLINDER_D;
	else if (ft_strnstr("tr", parc[0], 3))
		type->parcing.check = TRIANGLE_D;
	else
		type->parcing.check = 0;
}
