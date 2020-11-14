/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_w_wrong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:21:16 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/14 14:17:28 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	miss_or_out(t_data *type, int object, int wich)
{
	if (object == resolution_d)
		ft_print(type, "Resolution", wich);
	else if (object == ambient_d)
		ft_print(type, "Ambient", wich);
	else if (object == light_d)
		ft_print(type, "Light", wich);
	else if (object == camera_d)
		ft_print(type, "Camera", wich);
	else if (object == sphere_d)
		ft_print(type, "Sphere", wich);
	else if (object == plane_d)
		ft_print(type, "Plane", wich);
	else if (object == square_d)
		ft_print(type, "Square", wich);
	else if (object == cylinder_d)
		ft_print(type, "Cylinder", wich);
	else if (object == triangle_d)
		ft_print(type, "Triangle", wich);
	return (free_exit(type, 1));
}

int	wrong_pos(t_data *type, int object)
{
	if (object == light_d)
		ft_print(type, "Light", 2);
	else if (object == camera_d)
		ft_print(type, "Camera", 2);
	else if (object == sphere_d)
		ft_print(type, "Sphere", 2);
	else if (object == plane_d)
		ft_print(type, "Plane", 2);
	else if (object == square_d)
		ft_print(type, "Square", 2);
	else if (object == cylinder_d)
		ft_print(type, "Cylinder", 2);
	else if (object == triangle_d)
		ft_print(type, "Triangle", 2);
	return (free_exit(type, 1));
}

int	wrong_vec_ort(t_data *type, int object)
{
	if (object == camera_d)
		ft_print(type, "Camera", 3);
	else if (object == plane_d)
		ft_print(type, "Plane", 3);
	else if (object == square_d)
		ft_print(type, "Square", 3);
	else if (object == cylinder_d)
		ft_print(type, "Cylinder", 3);
	return (free_exit(type, 1));
}

int	wrong_rgb(t_data *type, int object)
{
	if (object == ambient_d)
		ft_print(type, "Ambient", 4);
	else if (object == light_d)
		ft_print(type, "Light", 4);
	else if (object == sphere_d)
		ft_print(type, "Sphere", 4);
	else if (object == plane_d)
		ft_print(type, "Plane", 4);
	else if (object == square_d)
		ft_print(type, "Square", 4);
	else if (object == cylinder_d)
		ft_print(type, "Cylinder", 4);
	else if (object == triangle_d)
		ft_print(type, "Triangle", 4);
	return (free_exit(type, 1));
}

int	wrong_trans_rot(t_data *type, int object, int wich)
{
	int i;

	if (wich == 1)
		i = 5;
	else
		i = 6;
	if (object == light_d)
		ft_print(type, "Light", i);
	else if (object == camera_d)
		ft_print(type, "Camera", i);
	else if (object == sphere_d)
		ft_print(type, "Sphere", i);
	else if (object == plane_d)
		ft_print(type, "Plane", i);
	else if (object == square_d)
		ft_print(type, "Square", i);
	else if (object == cylinder_d)
		ft_print(type, "Cylinder", i);
	else if (object == triangle_d)
		ft_print(type, "Triangle", i);
	return (free_exit(type, 1));
}
