/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:10:34 by thor              #+#    #+#             */
/*   Updated: 2020/11/14 14:39:36 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_element(t_data *type, char **parc, int check, int ligne_err)
{
	if (check == resolution_d)
		return (check_resolution(type, parc));
	else if (check == ambient_d)
		return (check_ambient(type, parc));
	else if (check == camera_d)
		return (check_camera(type, parc));
	else if (check == light_d)
		return (check_light(type, parc));
	else if (check == sphere_d)
		return (check_sphere(type, parc));
	else if (check == plane_d)
		return (check_plane(type, parc));
	else if (check == square_d)
		return (check_square(type, parc));
	else if (check == cylinder_d)
		return (check_cylinder(type, parc));
	else
		return (check_triangle(type, parc));
}

void	check_type(t_data *type, char **parc)
{
	if (ft_strnstr("R", parc[0], 2))
		type->parcing.check = resolution_d;
	else if (ft_strnstr("A", parc[0], 2))
		type->parcing.check = ambient_d;
	else if (ft_strnstr("c", parc[0], 2))
		type->parcing.check = camera_d;
	else if (ft_strnstr("l", parc[0], 2))
		type->parcing.check = light_d;
	else if (ft_strnstr("sp", parc[0], 3))
		type->parcing.check = sphere_d;
	else if (ft_strnstr("pl", parc[0], 3))
		type->parcing.check = plane_d;
	else if (ft_strnstr("sq", parc[0], 3))
		type->parcing.check = square_d;
	else if (ft_strnstr("cy", parc[0], 3))
		type->parcing.check = cylinder_d;
	else if (ft_strnstr("tr", parc[0], 3))
		type->parcing.check = triangle_d;
	else
		type->parcing.check = 0;
}
