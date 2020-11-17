/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_w_wrong_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:21:16 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/17 12:14:56 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	miss_or_out(t_data *type, int object, int wich)
{
	if (object == RESOLUTION_D)
		ft_print(type, "Resolution", wich);
	else if (object == AMBIENT_D)
		ft_print(type, "Ambient", wich);
	else if (object == LIGHT_D)
		ft_print(type, "Light", wich);
	else if (object == CAMERA_D)
		ft_print(type, "Camera", wich);
	else if (object == SPHERE_D)
		ft_print(type, "Sphere", wich);
	else if (object == PLANE_D)
		ft_print(type, "Plane", wich);
	else if (object == SQUARE_D)
		ft_print(type, "Square", wich);
	else if (object == CYLINDER_D)
		ft_print(type, "Cylinder", wich);
	else if (object == TRIANGLE_D)
		ft_print(type, "Triangle", wich);
	return (free_exit(type, 1));
}

int	wrong_pos(t_data *type, int object)
{
	if (object == LIGHT_D)
		ft_print(type, "Light", 2);
	else if (object == CAMERA_D)
		ft_print(type, "Camera", 2);
	else if (object == SPHERE_D)
		ft_print(type, "Sphere", 2);
	else if (object == PLANE_D)
		ft_print(type, "Plane", 2);
	else if (object == SQUARE_D)
		ft_print(type, "Square", 2);
	else if (object == CYLINDER_D)
		ft_print(type, "Cylinder", 2);
	else if (object == TRIANGLE_D)
		ft_print(type, "Triangle", 2);
	return (free_exit(type, 1));
}

int	wrong_vec_ort(t_data *type, int object)
{
	if (object == CAMERA_D)
		ft_print(type, "Camera", 3);
	else if (object == PLANE_D)
		ft_print(type, "Plane", 3);
	else if (object == SQUARE_D)
		ft_print(type, "Square", 3);
	else if (object == CYLINDER_D)
		ft_print(type, "Cylinder", 3);
	return (free_exit(type, 1));
}

int	wrong_rgb(t_data *type, int object)
{
	if (object == AMBIENT_D)
		ft_print(type, "Ambient", 4);
	else if (object == LIGHT_D)
		ft_print(type, "Light", 4);
	else if (object == SPHERE_D)
		ft_print(type, "Sphere", 4);
	else if (object == PLANE_D)
		ft_print(type, "Plane", 4);
	else if (object == SQUARE_D)
		ft_print(type, "Square", 4);
	else if (object == CYLINDER_D)
		ft_print(type, "Cylinder", 4);
	else if (object == TRIANGLE_D)
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
	if (object == LIGHT_D)
		ft_print(type, "Light", i);
	else if (object == CAMERA_D)
		ft_print(type, "Camera", i);
	else if (object == SPHERE_D)
		ft_print(type, "Sphere", i);
	else if (object == PLANE_D)
		ft_print(type, "Plane", i);
	else if (object == SQUARE_D)
		ft_print(type, "Square", i);
	else if (object == CYLINDER_D)
		ft_print(type, "Cylinder", i);
	else if (object == TRIANGLE_D)
		ft_print(type, "Triangle", i);
	return (free_exit(type, 1));
}
