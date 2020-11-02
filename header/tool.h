/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:46:40 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/02 14:47:42 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_H
#define TOOL_H

#include "minirt.h"

double ft_atod(const char *str);
int ft_2strlen(char **str);
t_colour r_g_b(char *r, char *g, char *b);
t_vector x_y_z(char *x, char *y, char *z);

#endif