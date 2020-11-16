/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 02:11:35 by thor              #+#    #+#             */
/*   Updated: 2020/11/16 17:11:45 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOK_H
# define KEY_HOOK_H

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define BACK 1
# define AHEAD 13
# include "minirt.h"

int		check_objet(int type);
void	check_xyz(t_data *type, int key);
int		check_trans_rot(t_data *type, int key);
int		check_direction(int key);
void	change_element(t_data *type);
int		hook_element(t_data *type, int key);
int		key_press(int keycode, t_data *type);
int		ft_close(t_data *type);

#endif
