/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:32 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/20 11:59:57 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	square(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 7)
		miss_or_out(type, SQUARE_D, 7);
	if (ft_2strlen(parc) >= 6)
	{
		if (check_pos(parc[5]) == 0)
			wrong_trans_rot(type, SQUARE_D, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 7)
	{
		if (check_rotation(parc[6]) == 0)
			wrong_trans_rot(type, SQUARE_D, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_square(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 5)
		return (miss_or_out(type, SQUARE_D, 1));
	else if (ft_2strlen(parc) > 5)
		square(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, SQUARE_D));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, SQUARE_D));
	else if (check_double(parc[3]) == 0 || ft_atod(parc[3]) < 0)
		ft_print_cont(type, "Error\nSquare", SQUARE_D, 0);
	else if (check_rgb(parc[4]) == 0)
		return (wrong_rgb(type, SQUARE_D));
	return (SQUARE_D);
}

static void	cylinder(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 8)
		miss_or_out(type, CYLINDER_D, 7);
	if (ft_2strlen(parc) >= 7)
	{
		if (check_pos(parc[6]) == 0)
			wrong_trans_rot(type, CYLINDER_D, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 8)
	{
		if (check_rotation(parc[7]) == 0)
			wrong_trans_rot(type, CYLINDER_D, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_cylinder(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 6)
		return (miss_or_out(type, CYLINDER_D, 1));
	else if (ft_2strlen(parc) > 6)
		cylinder(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, CYLINDER_D));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, CYLINDER_D));
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, CYLINDER_D));
	else if (check_double(parc[4]) == 0 || ft_atod(parc[4]) < 0)
		ft_print_cont(type, "Error\nCylinder", CYLINDER_D, 1);
	else if (check_double(parc[5]) == 0 || ft_atod(parc[5]) < 0)
		ft_print_cont(type, "Error\nCylinder", CYLINDER_D, 2);
	return (CYLINDER_D);
}
