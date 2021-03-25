/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_function_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 08:51:02 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/23 18:40:42 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void		bmp_file_header(t_data *type, int *fd)
{
	int file_size;
	int first_pix;

	file_size = 14 + 40 + 4 + (type->rsl.width * type->rsl.height) * 4;
	first_pix = 14 + 40 + 4;
	write(*fd, "BM", 2);
	write(*fd, &file_size, 4);
	write(*fd, "\0\0\0\0", 4);
	write(*fd, &first_pix, 4);
}

void		bmp_file_info_header(t_data *type, int *fd)
{
	int header_info_size;
	int plane_nbr;
	int count;

	header_info_size = 40;
	plane_nbr = 1;
	count = 0;
	write(*fd, &header_info_size, 4);
	write(*fd, &type->rsl.width, 4);
	write(*fd, &type->rsl.height, 4);
	write(*fd, &plane_nbr, 2);
	write(*fd, &type->mlx.bpp, 2);
	while (count < 28)
	{
		write(*fd, "\0", 1);
		count++;
	}
}

static void	copy_data(t_data *type, int *fd)
{
	int i;

	i = type->rsl.width * type->rsl.height;
	while (i > 0)
	{
		write(*fd, &type->mlx.img_data[i], 4);
		i--;
	}
}

void		pixel_data(t_data *type, int *fd)
{
	int i;
	int size_line;
	int save;
	int p;

	i = 0;
	type->mlx.size_line /= 4;
	while (i < type->rsl.height)
	{
		p = 0;
		size_line = type->mlx.size_line;
		while (p < size_line && p != size_line)
		{
			save = type->mlx.img_data[p + (i * type->mlx.size_line)];
			type->mlx.img_data[p + (i * type->mlx.size_line)] =
				type->mlx.img_data[size_line + (i * type->mlx.size_line - 1)];
			type->mlx.img_data[size_line + (i *
					type->mlx.size_line -
					1)] = save;
			p++;
			size_line--;
		}
		i++;
	}
	copy_data(type, fd);
}

int			create_bmp(t_data *type)
{
	int fd;

	fd = open("rt.bmp", O_CREAT | O_RDWR);
	bmp_file_header(type, &fd);
	bmp_file_info_header(type, &fd);
	pixel_data(type, &fd);
	return (1);
}
