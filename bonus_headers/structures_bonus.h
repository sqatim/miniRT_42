/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 21:13:36 by thor              #+#    #+#             */
/*   Updated: 2020/11/23 14:47:58 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

typedef struct	s_vector
{
	double x;
	double y;
	double z;
}				t_vector;

typedef struct	s_key
{
	int key;
	int type;
	int check;
	int rot_xyz;
	int tr_rt;
	int renitialise;
}				t_key;

typedef struct	s_varcal
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		u;
	double		v;
	double		t;
	double		t1;
	double		t2;
	t_vector	edge1;
	t_vector	edge2;
	t_vector	oc;
}				t_varcal;

typedef struct	s_camera
{
	t_vector		pos;
	t_vector		ort_vec;
	double			fov;
	t_vector		pixel;
	t_vector		n;
	t_vector		u;
	t_vector		v;
	t_vector		l;
	t_vector		r_dir;
	t_vector		translation;
	t_vector		rotation;
	struct s_camera	*previous;
	struct s_camera	*next;
}				t_camera;

typedef struct	s_colour
{
	double r;
	double g;
	double b;
}				t_colour;

typedef struct	s_info
{
	char	**pos;
	char	**pos1;
	char	**pos2;
	char	**colour;
	char	**vector;
	double	radius;
	double	height;
	char	**translation;
	char	**rotation;
	double	fov;
	double	int_light;
}				t_info;

typedef struct	s_objet
{
	int				type;
	t_vector		pos;
	t_vector		pos1;
	t_vector		pos2;
	double			radius;
	t_colour		colour;
	t_vector		point;
	t_vector		normal;
	t_vector		v;
	t_vector		reflection;
	t_vector		light;
	t_vector		view;
	t_vector		translation;
	t_vector		rotation;
	double			height;
	double			t;
	double			test;
	int				i;
	struct s_objet	*previous;
	struct s_objet	*next;
}				t_objet;

typedef struct	s_shadow
{
	double	degre;
	double	intersect;
}				t_shadow;

typedef struct	s_tools
{
	int		index;
	int		type;
	int		intersect;
	int		bmp;
	int		tran_rot;
}				t_tools;

typedef struct	s_parcing
{
	int	check;
	int	indice;
	int	error;
	int	r;
	int	a;
	int c;
}				t_parcing;

typedef struct	s_ray
{
	t_vector	origin;
	double		lenght;
	t_vector	direction;
}				t_ray;

typedef struct	s_light
{
	t_vector		pos;
	t_colour		rgb_light;
	double			int_light;
	t_vector		translation;
	struct s_light	*previous;
	struct s_light	*next;
}				t_light;

typedef struct	s_ambient
{
	t_colour	rgb_amb;
	double		int_amb;
}				t_ambient;

typedef struct	s_phong
{
	t_colour	diffuse;
	t_colour	specular;
	t_colour	ambiant;
}				t_phong;

typedef struct	s_clone
{
	t_camera	*camera;
	t_light		*light;
	t_objet		*objet;
}				t_clone;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_data;
	int		size_line;
	int		bpp;
	int		*tab;
}				t_mlx;

typedef struct	s_resolution
{
	int		x;
	int		y;
	int		width;
	int		height;
	double	half_height;
	double	half_width;
}				t_resolution;

typedef struct	s_data
{
	t_vector		vector;
	t_objet			*objet;
	t_tools			tool;
	t_key			key;
	t_ray			ray;
	t_colour		colour;
	t_mlx			mlx;
	t_light			*light;
	t_ambient		ambient;
	t_camera		*camera;
	t_resolution	rsl;
	t_clone			clone;
	t_phong			phong;
	t_parcing		parcing;
	t_shadow		shad;
}				t_data;

#endif
