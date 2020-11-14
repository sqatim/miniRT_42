/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:32 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/14 13:57:34 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	square(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 7)
		miss_or_out(type, square_d, 7);
	if (ft_2strlen(parc) >= 6)
	{
		if (check_pos(parc[5]) == 0)
			wrong_trans_rot(type, square_d, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 7)
	{
		if (check_rotation(parc[6]) == 0)
			wrong_trans_rot(type, square_d, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_square(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 5)
		return (miss_or_out(type, square_d, 1));
	else if (ft_2strlen(parc) > 5)
		square(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, square_d));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, square_d));
	else if (check_double(parc[3]) == 0 || ft_atod(parc[3]) < 0)
		ft_print_cont(type, "Square", square_d, 0);
	else if (check_rgb(parc[4]) == 0)
		return (wrong_rgb(type, square_d));
	return (square_d);
}

static void	cylinder(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 8)
		miss_or_out(type, cylinder_d, 7);
	if (ft_2strlen(parc) >= 7)
	{
		if (check_pos(parc[6]) == 0)
			wrong_trans_rot(type, cylinder_d, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 8)
	{
		if (check_rotation(parc[7]) == 0)
			wrong_trans_rot(type, cylinder_d, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_cylinder(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 6)
		return (miss_or_out(type, cylinder_d, 1));
	else if (ft_2strlen(parc) > 6)
		cylinder(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, cylinder_d));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, cylinder_d));
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, cylinder_d));
	else if (check_double(parc[4]) == 0 || ft_atod(parc[4]) < 0)
		ft_print_cont(type, "Cylinder", cylinder_d, 1);
	else if (check_double(parc[5]) == 0 || ft_atod(parc[5]) < 0)
		ft_print_cont(type, "Cylinder", cylinder_d, 2);
	return (cylinder_d);
}
