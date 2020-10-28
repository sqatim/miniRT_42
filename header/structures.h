/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:13:36 by thor              #+#    #+#             */
/*   Updated: 2020/10/28 13:58:55 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct s_vector
{
    double x;
    double y;
    double z;
} t_vector;

typedef struct s_key
{
    int key;
    int type;
    int check;
    int rot_xyz;
    int tr_rt;
    int renitialise;
}               t_key;
typedef struct s_camera
{
    t_vector pos;
    t_vector ort_vec;
    double fov;
    t_vector pixel;
    t_vector r_dir;
    struct s_camera *previous;
    struct s_camera *next;
} t_camera;

typedef enum s_bool
{
    TRUE = 1,
    FALSE = 0
}           t_bool;


// typedef enum s_typeObj
// {
//     objet = 1,
//     camera = 2,
//     light = 3

// }           t_typeObj;

typedef struct s_colour
{
    double r;
    double g;
    double b;
} t_colour;

typedef struct s_objet
{
    int type;
    t_vector pos;
    t_vector pos1;
    t_vector pos2;
    double radius;
    t_colour colour;
    t_vector point;
    t_vector normal;
    t_vector v;
    t_vector reflection;
    t_vector light;
    t_vector view;
    double height;
    double t;
    double test;
    int i;
    struct s_objet *previous;
    struct s_objet *next;
} t_objet;

typedef struct s_tools
{
    int index;
    int type;
    int intersect;
    double dif;
    double shad;
    double dahs;
    int done;
} t_tools;

typedef struct s_ray
{
    t_vector origin;
    t_vector direction;
} t_ray;

typedef struct s_light
{
    t_vector pos;
    t_colour rgb_light;
    double int_light;
    struct s_light *previous;
    struct s_light *next;
} t_light;

typedef struct s_ambient
{
    t_colour rgb_amb;
    double int_amb;
} t_ambient;

typedef struct s_phong
{
    t_colour diffuse;
    t_colour specular;
    t_colour ambiant;

} t_phong;

typedef struct s_clo
{
    t_camera *camera;
    t_light *light;
    t_objet *objet;
}           t_clo;

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int *img_data;
    int size_line;
    int bpp;
    int *tab;
} t_mlx;

typedef struct s_resolution
{
    int x;
    int y;
    int width;
    int height;
    double half_height;
    double half_width;
}       t_resolution;

typedef struct s_data
{
    t_vector vector;
    t_objet *objet;
    t_tools tool;
    t_key key;
    t_ray ray;
    t_colour colour;
    t_mlx mlx;
    t_light *light;
    t_ambient ambient;
    t_camera *camera;
    t_resolution rsl;
    t_clo clo;
    t_phong phong;
    int i;
} t_data;

#endif
