/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:13:26 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 17:10:29 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_TOOLS_H
# define CHECK_TOOLS_H

# include "minirt.h"

int	check_numb(char *str);
int	check_double(char *str);
int	check_rotation(char *parc);
int	check_rgb(char *parc);
int	check_pos(char *parc);
int	check_vec_ort(char *parc);

#endif
