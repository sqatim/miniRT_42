/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_p_n.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:08:26 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 17:08:33 by sqatim           ###   ########.fr       */
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
