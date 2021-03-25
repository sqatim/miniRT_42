/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:03:50 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/23 17:28:21 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# define PI 3.14159

# include "mlx.h"
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <float.h>
# include <unistd.h>
# include <fcntl.h>

# include "structures_bonus.h"
# include "check_bonus.h"
# include "tool_bonus.h"
# include "parcing_bonus.h"
# include "transformation_bonus.h"
# include "calcul_bonus.h"
# include "get_next_line_bonus.h"
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
int			mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif
