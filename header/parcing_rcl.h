/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_rcl.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:39:02 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/02 14:40:07 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_RCL_H
#define PARCING_RCL_H

#include "minirt.h"

void parc_resl(t_data *type, char *line);
void parc_amb(t_data *type, char *line);
void parc_camera(t_data *type, char *line);
void parc_light(t_data *type, char *line);

#endif