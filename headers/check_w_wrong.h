/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_w_wrong.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:22:19 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 17:10:44 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_W_WRONG_H
# define CHECK_W_WRONG_H

# include "minirt.h"

int	miss_or_out(t_data *type, int object, int wich);
int	wrong_pos(t_data *type, int object);
int	wrong_vec_ort(t_data *type, int object);
int	wrong_rgb(t_data *type, int object);
int	wrong_trans_rot(t_data *type, int object, int wich);

#endif
