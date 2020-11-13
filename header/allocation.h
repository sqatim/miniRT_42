/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 20:06:56 by thor              #+#    #+#             */
/*   Updated: 2020/11/13 11:49:40 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_H
#define ALLOCATION_H

#include "minirt.h"

t_light *add_light(t_data *type, t_info object);
t_camera *add_camera(t_data *type, t_info object);

#endif