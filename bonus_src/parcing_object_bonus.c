/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_object_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:29:08 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/17 12:14:56 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	parc_sphere(t_data *type, char *line)
{
	char	**sphere;
	t_info	object;

	sphere = ft_space_split(line);
	object.pos = ft_split(sphere[1], ',');
	object.colour = ft_split(sphere[3], ',');
	object.radius = ft_atod(sphere[2]);
	if (type->tool.tran_rot > 0)
		object.translation = ft_split(sphere[4], ',');
	type->objet = add_sphere(type, object);
}

void	parc_plane(t_data *type, char *line)
{
	char	**plane;
	t_info	object;

	plane = ft_space_split(line);
	object.pos = ft_split(plane[1], ',');
	object.vector = ft_split(plane[2], ',');
	object.colour = ft_split(plane[3], ',');
	if (type->tool.tran_rot > 0)
	{
		object.translation = ft_split(plane[4], ',');
		if (type->tool.tran_rot == 2)
			object.rotation = ft_split(plane[5], ',');
	}
	type->objet = add_plane(type, object);
}

void	parc_square(t_data *type, char *line)
{
	char	**square;
	t_info	object;

	square = ft_space_split(line);
	object.pos = ft_split(square[1], ',');
	object.vector = ft_split(square[2], ',');
	object.height = ft_atod(square[3]);
	object.colour = ft_split(square[4], ',');
	if (type->tool.tran_rot > 0)
	{
		object.translation = ft_split(square[5], ',');
		if (type->tool.tran_rot == 2)
			object.rotation = ft_split(square[6], ',');
	}
	type->objet = add_square(type, object);
}

void	parc_cylinder(t_data *type, char *line)
{
	char	**cylinder;
	t_info	object;

	cylinder = ft_space_split(line);
	object.pos = ft_split(cylinder[1], ',');
	object.vector = ft_split(cylinder[2], ',');
	object.colour = ft_split(cylinder[3], ',');
	object.radius = ft_atod(cylinder[4]);
	object.height = ft_atod(cylinder[5]);
	if (type->tool.tran_rot > 0)
	{
		object.translation = ft_split(cylinder[6], ',');
		if (type->tool.tran_rot == 2)
			object.rotation = ft_split(cylinder[7], ',');
	}
	type->objet = add_cylinder(type, object);
}

void	parc_triangle(t_data *type, char *line)
{
	char	**triangle;
	t_info	object;

	triangle = ft_space_split(line);
	object.pos = ft_split(triangle[1], ',');
	object.pos1 = ft_split(triangle[2], ',');
	object.pos2 = ft_split(triangle[3], ',');
	object.colour = ft_split(triangle[4], ',');
	if (type->tool.tran_rot > 0)
	{
		object.translation = ft_split(triangle[5], ',');
		if (type->tool.tran_rot == 2)
			object.rotation = ft_split(triangle[6], ',');
	}
	type->objet = add_triangle(type, object);
}
