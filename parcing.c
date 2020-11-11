/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 19:23:04 by thor              #+#    #+#             */
/*   Updated: 2020/11/11 12:12:38 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void parcing_tool(t_data *type, int indice, char *line)
{
	if (indice == resolution_d)
		parc_resl(type, line);
	else if (indice == ambient_d)
		parc_amb(type, line);
	else if (indice == camera_d)
		parc_camera(type, line);
	else if (indice == light_d)
		parc_light(type, line);
	else if (indice == camera_d)
		parc_camera(type, line);
	else if (indice == sphere_d)
		parc_sphere(type, line);
	else if (indice == plane_d)
		parc_plane(type, line);
	else if (indice == square_d)
		parc_square(type, line);
	else if (indice == cylinder_d)
		parc_cylinder(type, line);
	else if (indice == triangle_d)
		parc_triangle(type, line);
}

void parcing_check(t_data *type, char *line)
{
	int i;
	char **parc;

	i = 0;
	parc = ft_space_split(line);
	type->parcing.check = -1;
	type->parcing.indice = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_isalpha(line[i]))
	{
		check_type(type, parc);
		if (type->parcing.check == 0)
		{
			write(1, "t2akad man type line ", 21);
			ft_putnbr_fd(type->parcing.error, 1);
			free_exit(type, 1);
		}
		else
			type->parcing.indice = check_element(type,
												 parc, type->parcing.check, type->parcing.error);
	}
	else if (!ft_isalpha(line[i]) && line[i])
	{
		write(1, "t2akad man type line ", 21);
		free_exit(type, 1);
	}
}

char *ft_str_in_str(const char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2[j])
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			j = 1;
			while (s2[j] && s2[j] == s1[i + j])
				j++;
			if (!s2[j] && !s1[i + j])
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}

void read_line(t_data *type, int fd)
{
	int r;
	char *line;

	while ((r = get_next_line(fd, &line)) > 0)
	{
		type->parcing.error++;
		parcing_check(type, line);
		parcing_tool(type, type->parcing.indice, line);
	}
	if (r == 0)
	{
		type->parcing.error++;
		parcing_check(type, line);
		parcing_tool(type, type->parcing.indice, line);
	}
	if (r == -1)
		exit(1);
}

void parcing(t_data *type, char **av, int ac)
{
	int fd;
	char *line;
	char **parc;
	int r;

	fd = open(av[1], O_RDONLY);
	if (ac == 2 || ac == 3)
	{
		if (ac == 3)
		{
			if (ft_strlen(av[2]) != 5 || (!(ft_strnstr(av[2], "-save", 5))))
			{
				ft_putstr_fd("check argument 2", 1);
				exit(1);
			}
			type->tool.bmp = 1;
		}
		if (fd == -1)
		{
			ft_putstr_fd("File not found", 1);
			exit(1);
		}
		if (ft_str_in_str(av[1], ".rt"))
			read_line(type, fd);
		else
		{
			ft_putstr_fd("File is not format \".rt\"", 1);
			exit(1);
		}
		if (type->parcing.r == 0)
		{
			ft_putstr_fd("Resolution not found\n", 1);
			free_exit(type, 1);
		}
	}
	else
	{
		if (ac == 1)
			ft_putstr_fd("Argument missing\n", 1);
		else
			ft_putstr_fd("Argument out limit\n", 1);
		exit(1);
	}
}
