/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:22:00 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/19 12:04:14 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_BONUS_H
# define TRANSFORMATION_BONUS_H

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define BACK 1
# define AHEAD 13
# include "minirt_bonus.h"

void		trans_rot(t_data *type, t_objet *new_object, t_info object);
t_vector	rot_vector(t_vector vect_ort, t_vector angle);
void		rotation_r_l(t_data *type);
void		rotation_u_d(t_data *type);
void		rotation_a_b(t_data *type);
void		rotation(t_data *type);
void		translation_a_b(t_data *type);
void		translation_u_d(t_data *type);
void		translation_r_l(t_data *type);
void		transl_objet_x(t_data *type, double pos, int indice);
void		transl_objet_y(t_data *type, double pos, int indice);
void		transl_objet_z(t_data *type, double pos, int indice);
void		translation(t_data *type);
int			check_objet(int type);
void		check_xyz(t_data *type, int key);
int			check_trans_rot(t_data *type, int key);
int			check_direction(int key);
void		change_element(t_data *type);
int			hook_element(t_data *type, int key);
int			key_press(int keycode, t_data *type);
int			ft_close(t_data *type);

#endif
