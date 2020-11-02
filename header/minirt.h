#ifndef MINIRT_H
#define MINIRT_H

#define PI 3.14159

#include "mlx.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <unistd.h>
#include <fcntl.h>

#include "structures.h"
#include "allocation.h"
#include "tool.h"
#include "parcing_object.h"
#include "parcing_rcl.h"
#include "parcing.h"
#include "hit_objet.h"
#include "allocation_objet.h"
#include "vector.h"
#include "camera.h"
#include "key_hook.h"
#include "translation.h"
#include "rotation.h"
#include "calcul_p_n.h"
#include "phong.h"
#include "colour.h"
#include "../GNL/get_next_line.h"
#include "../libft/libft.h"

#define resolution_d 1
#define ambient_d 2
#define camera_d 3
#define light_d 4
#define sphere_d 5
#define plane_d 6
#define square_d 7
#define cylinder_d 8
#define triangle_d 9

void check_type(t_data *type, char **parc);
int check_element(char **parc, int check, int ligne_err);

#define max(a, b) ((double)a >= (double)b ? (double)a : (double)b)
#define min(a, b) ((double)a <= (double)b ? (double)a : (double)b)

int key_hook(int key, t_data *type);

t_colour coleur(t_data *type);
int _3til_lbabaha(t_colour *data);
void screen_blue(t_data *type);

void objet(t_objet *objet);
t_colour colour_scal(double nbr, t_colour rgb);

void hit_objet(t_data *type, double *t1);
t_colour shadows(t_data *type, t_objet *tmp);

double ft_atod(const char *str);

char **ft_space_split(char const *s);

#endif