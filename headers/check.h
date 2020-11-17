/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:28:17 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/17 12:54:37 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "minirt.h"

int		check_sphere(t_data *type, char **parc);
int		check_plane(t_data *type, char **parc);
int		check_square(t_data *type, char **parc);
int		check_cylinder(t_data *type, char **parc);
int		check_triangle(t_data *type, char **parc);
int		check_resolution(t_data *type, char **parc);
int		check_ambient(t_data *type, char **parc);
int		check_light(t_data *type, char **parc);
int		check_camera(t_data *type, char **parc);
int		check_numb(char *str);
int		check_double(char *str);
int		check_rotation(char *parc);
int		check_rgb(char *parc);
int		check_pos(char *parc);
int		check_vec_ort(char *parc);
int		miss_or_out(t_data *type, int object, int wich);
int		wrong_pos(t_data *type, int object);
int		wrong_vec_ort(t_data *type, int object);
int		wrong_rgb(t_data *type, int object);
int		wrong_trans_rot(t_data *type, int object, int wich);
void	ft_print(t_data *type, char *name, int number);
void	ft_print_cont(t_data *type, char *name, int object, int error);
void	print_error_type(t_data *type);

#endif
