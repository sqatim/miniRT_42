/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:46:19 by thor              #+#    #+#             */
/*   Updated: 2020/03/30 19:58:51 by thor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
#define COLOUR_H

#include "minirt.h"

t_colour colour_add(t_colour v1, t_colour v2);
t_colour colour_prd(t_colour col1, t_colour col2);
t_colour colour_scal(double nbr, t_colour rgb);
t_vector get_color(t_data *type, int nbrbonds);
t_colour min_max(t_colour rgb);
t_colour make_number(t_colour rgb, double nbr);
t_colour make_range(t_colour rgb);

#endif