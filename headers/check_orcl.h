/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_orcl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:28:17 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 17:12:10 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ORCL_H
# define CHECK_ORCL_H

# include "minirt.h"

int	check_sphere(t_data *type, char **parc);
int	check_plane(t_data *type, char **parc);
int	check_square(t_data *type, char **parc);
int	check_cylinder(t_data *type, char **parc);
int	check_triangle(t_data *type, char **parc);
int	check_resolution(t_data *type, char **parc);
int	check_ambient(t_data *type, char **parc);
int	check_light(t_data *type, char **parc);
int	check_camera(t_data *type, char **parc);

#endif
