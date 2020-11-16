/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_p_n.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:20:49 by thor              #+#    #+#             */
/*   Updated: 2020/03/24 23:39:31 by thor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_P_N_H
# define CALCUL_P_N_H

# include "minirt.h"

void	sphere_p_n(t_data *type);
void	plane_p_n(t_data *type);
void	square_p_n(t_data *type);
void	cylinder_p_n(t_data *type);
void	triangle_p_n(t_data *type);

#endif
