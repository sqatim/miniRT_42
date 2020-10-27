/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:07:42 by thor              #+#    #+#             */
/*   Updated: 2020/10/27 17:41:18 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "minirt.h"
void translation_a_b(t_data *type);
void translation_u_d(t_data *type);
void translation_r_l(t_data *type);
void transl_objet_z(t_data *type, double pos, int indice);
void translation(t_data *type);

#endif