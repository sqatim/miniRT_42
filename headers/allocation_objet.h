/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_objet.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:11:12 by thor              #+#    #+#             */
/*   Updated: 2020/11/16 10:39:30 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_OBJET_H
# define ALLOCATION_OBJET_H

# include "minirt.h"

void	trans_rot(t_data *type, t_objet *new_object, t_info object);
t_objet	*add_sphere(t_data *type, t_info object);
t_objet	*add_plane(t_data *type, t_info object);
t_objet	*add_square(t_data *type, t_info object);
t_objet	*add_cylinder(t_data *type, t_info object);
t_objet	*add_triangle(t_data *type, t_info object);

#endif
