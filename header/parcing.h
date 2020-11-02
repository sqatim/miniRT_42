/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:34:49 by thor              #+#    #+#             */
/*   Updated: 2020/11/02 14:50:40 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
#define PARCING_H

#include "minirt.h"

void parcing(t_data *type, char **av);
void parcing_check(t_data *type, char *line);
void parcing_tool(t_data *type, int indice, char *line);

#endif