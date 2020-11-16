/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:00:01 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 13:15:30 by sqatim           ###   ########.fr       */
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
# include "bmp_function.h"
# include "allocation.h"
# include "tool.h"
# include "parcing_object.h"
# include "parcing_rcl.h"
# include "parcing.h"
# include "hit_objet.h"
# include "hit_function.h"
# include "allocation_objet.h"
# include "check_tools.h"
# include "check_orcl.h"
# include "check_w_wrong.h"
# include "print_error.h"
# include "vector.h"
# include "camera.h"
# include "key_hook.h"
# include "translation.h"
# include "rotation.h"
# include "rotation_bonus.h"
# include "calcul_p_n.h"
# include "phong.h"
# include "colour.h"
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
# define max(a, b) ((double)a >= (double)b ? (double)a : (double)b)
# define min(a, b) ((double)a <= (double)b ? (double)a : (double)b)

void		check_type(t_data *type, char **parc);
int			check_element(t_data *type, char **parc, int check);
int			key_hook(int key, t_data *type);
t_colour	coleur(t_data *type);
int			merge(t_colour *data);
void		minirt(t_data *type);
void		objet(t_objet *objet);
t_colour	colour_scal(double nbr, t_colour rgb);
void		hit_objet(t_data *type, double *t1);
t_colour	shadows(t_data *type, t_objet *tmp);
double		ft_atod(const char *str);
char		**ft_space_split(char const *s);

#endif
