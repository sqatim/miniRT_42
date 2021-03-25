/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:00:01 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/23 17:33:14 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define PI 3.14159

# include "mlx.h"
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <float.h>
# include <unistd.h>
# include <fcntl.h>

# include "structures.h"
# include "tool.h"
# include "parcing.h"
# include "calcul.h"
# include "check.h"
# include "get_next_line.h"
# include "../libft/libft.h"

# define RESOLUTION_D 1
# define AMBIENT_D 2
# define CAMERA_D 3
# define LIGHT_D 4
# define SPHERE_D 5
# define PLANE_D 6
# define SQUARE_D 7
# define CYLINDER_D 8
# define TRIANGLE_D 9

void		check_type(t_data *type, char **parc);
int			check_element(t_data *type, char **parc, int check);
t_colour	coleur(t_data *type);
int			merge(t_colour *data);
void		minirt(t_data *type);
t_colour	shadows(t_data *type, t_objet *tmp);
double		ft_atod(const char *str);
char		**ft_space_split(char const *s);
void		ft_mlx(t_data *type, int wich);
int			key_press(int keycode, t_data *type);
int			ft_close(t_data *type);
int			mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif
