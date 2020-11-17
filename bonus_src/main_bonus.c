/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:22:20 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/17 12:14:56 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_mlx(t_data *type, int wich)
{
	int endian;

	if (wich == 1)
	{
		type->mlx.mlx_ptr = mlx_init();
		type->mlx.img_ptr = mlx_new_image(type->mlx.mlx_ptr,\
			type->rsl.width, type->rsl.height);
		type->mlx.img_data = (int *)mlx_get_data_addr(type->mlx.img_ptr,\
			&type->mlx.bpp, &type->mlx.size_line, &endian);
	}
	else if (wich == 2)
	{
		type->mlx.win_ptr = mlx_new_window(type->mlx.mlx_ptr,\
			type->rsl.width, type->rsl.height, "miniRT");
		mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr,\
			type->mlx.img_ptr, 0, 0);
		mlx_hook(type->mlx.win_ptr, 2, 0, key_press, type);
		mlx_hook(type->mlx.win_ptr, 17, 0, ft_close, type);
		mlx_loop(type->mlx.mlx_ptr);
	}
}

void	clone(t_data *type)
{
	type->clone.objet = type->objet;
	type->clone.camera = type->camera;
	type->clone.light = type->light;
}

int		main(int ac, char **av)
{
	t_data type;

	ft_bzero(&type, sizeof(t_data));
	parcing(&type, av, ac);
	clone(&type);
	ft_mlx(&type, 1);
	minirt(&type);
	if (type.tool.bmp == 1)
		create_bmp(&type);
	else
		ft_mlx(&type, 2);
	return (0);
}
