/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:46:40 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 16:11:06 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_H
# define TOOL_H

# include "minirt.h"

double		ft_atod(const char *str);
int			ft_2strlen(char **str);
t_colour	r_g_b(char *r, char *g, char *b);
t_vector	x_y_z(char *x, char *y, char *z);
int			free_exit(t_data *type, int wich);
void		calcul_delta_cy(t_objet *objet, t_ray *ray, t_varcal *var);
void		witch_object(t_objet *objet, t_ray *ray, double *has_inter);
double		max(double a, double b);
double		min(double a, double b);

#endif
