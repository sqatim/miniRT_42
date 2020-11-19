/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:46:40 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/19 12:04:23 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_BONUS_H
# define TOOL_BONUS_H

# include "minirt_bonus.h"

double		ft_atod(const char *str);
int			ft_2strlen(char **str);
t_colour	r_g_b(char *r, char *g, char *b);
t_vector	x_y_z(char *x, char *y, char *z);
int			free_exit(t_data *type, int wich);
void		calcul_delta_cy(t_objet *objet, t_ray *ray, t_varcal *var);
void		witch_object(t_objet *objet, t_ray *ray, double *has_inter);
double		max(double a, double b);
double		min(double a, double b);
double		vector_dot(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_scal(double c, t_vector v);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_cross(t_vector v1, t_vector v2);
t_vector	unit_vector(t_vector v);
double		vector_length(t_vector v);
t_vector	vector_prd(t_vector v1, t_vector v2);
t_vector	make_pos(double x, double y, double z);
t_colour	colour_add(t_colour v1, t_colour v2);
t_colour	colour_prd(t_colour col1, t_colour col2);
t_colour	colour_scal(double nbr, t_colour rgb);
t_vector	get_color(t_data *type, int nbrbonds);
t_colour	min_max(t_colour rgb);
t_colour	make_number(double nbr);
t_colour	make_range(t_colour rgb);
int			create_bmp(t_data *type);

#endif
