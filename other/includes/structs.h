/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:28:44 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/16 18:42:16 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define MATRIX_SIZE 4
# define YES	1
# define NO		0

# include "libft.h"
# include "key_map.h"
# include <stdbool.h>
# include <math.h>

typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vec3;

typedef struct s_matrix
{
	int				rows;
	int				cols;
	double			data[MATRIX_SIZE][MATRIX_SIZE];
}					t_matrix;

typedef t_vec3		t_color;
typedef t_vec3		t_point;

typedef struct s_canvas
{
	int				width;
	int				height;
	t_color			**pixels;
}					t_canvas;

typedef struct s_ray
{
	t_point			origin;
	t_vec3			direction;
}					t_ray;

typedef struct s_lighting
{
	t_color			diffuse;
	t_color			specular;
	t_color			ef_color;
	t_vec3			lightv;
	t_color			amb;
	double			light_dot_normal;
	t_vec3			reflectv;
	double			reflect_dot_eye;
	double			factor;
	t_color			color;
}					t_lighting;

typedef struct s_light
{
	t_vec3			position;
	double			brightness;
	t_color			intensity;
	t_lighting		*lighting;
	bool			in_shadow;
}					t_light;

typedef enum e_style
{
	NONE,
	STRIPES,
	GRADIENT,
	RING,
	CHECKERS,
	XPM
}			t_style;

typedef struct s_pattern
{
	t_style		type;
	t_color		a;
	t_color		b;
	t_matrix	transform;
	t_matrix	inverted;
	t_canvas	xpm;
}					t_pattern;

typedef struct s_material
{
	t_color			color;
	t_color			ambient;
	double			diffuse;
	double			specular;
	double			shininess;
	t_pattern		pattern;
	double			reflective;
	double			transparency;
	double			refractive_index;
}					t_material;

typedef struct s_bhask
{
	double			a;
	double			b;
	double			c;
	double			discriminant;
	double			t0;
	double			t1;
}					t_bhask;

typedef struct s_sphere
{
	int				id;
	t_vec3			center;
	double			diameter;
}					t_sphere;

typedef struct s_plane
{
	int				id;
	t_vec3			point;
}					t_plane;

typedef struct s_cylinder
{
	int				id;
	double			minimum;
	double			maximum;
	t_vec3			center;
	double			diameter;
	double			height;
	t_vec3			normal;
	bool			closed;
}					t_cylinder;

typedef struct s_cone
{
	int				id;
	double			minimum;
	double			maximum;
	t_vec3			center;
	double			diameter;
	double			height;
	bool			closed;
}					t_cone;

typedef struct s_cube
{
	int				id;
	t_vec3			center;
	double			side;
}					t_cube;

typedef struct s_triangle
{
	int				id;
	t_point			p1;
	t_point			p2;
	t_point			p3;
	t_vec3			e1;
	t_vec3			e2;
	t_vec3			normal;
}					t_triangle;

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	CUBE,
	TRIANGLE
}					t_type;

typedef struct s_shapes
{
	t_type			type;
	union
	{
		t_sphere	*sphere;
		t_plane		*plane;
		t_cylinder	*cylinder;
		t_cone		*cone;
		t_cube		*cube;
		t_triangle	*triangle;
	};
	t_matrix		transform;
	t_matrix		inverted;
	t_material		material;
	t_vec3			normal;
}					t_shapes;

typedef struct s_intersection
{
	double			t;
	t_shapes		*object;
}					t_intersection;

typedef t_list		t_intersections;

typedef struct s_image
{
	int				line_length;
	int				bpp;
	int				endian;
	int				**color;
	void			*img;
	char			*addr;
}					t_image;

typedef struct s_comps
{
	double			t;
	t_shapes		*object;
	t_point			point;
	t_vec3			eyev;
	t_vec3			normalv;
	bool			inside;
	t_point			over_point;
	t_point			under_point;
	t_vec3			reflectv;
	double			n1;
	double			n2;
}					t_comps;

typedef struct s_amb
{
	double			ratio;
	t_vec3			color;
}					t_amb;

typedef struct s_camera
{
	int				hsize;
	int				vsize;
	t_matrix		transform;
	t_matrix		inverted;
	double			half_width;
	double			half_height;
	double			pixel_size;
	t_vec3			point;
	t_vec3			normalized;
	double			fov;
}					t_camera;

typedef struct s_scene
{
	char			*line;
	char			**split;
	t_camera		*camera;
	t_amb			ambient;
	t_shapes		*new;
	t_list			*objects;
	t_light			*lights;
	t_list			*lights_list;
	char			*msg_error;
	int				qtys[9];
	int				bonus_qtys[4];
}					t_scene;

typedef struct s_world
{
	char			**split;
	void			*mlx;
	void			*win;
	t_list			*objects;
	t_image			img;
	t_camera		*camera;
	t_canvas		canvas;
	t_list			*lights;
	t_camera		*zero;
	t_key_map		key;
}					t_world;

typedef struct s_area
{
	int				w_l;
	int				w_r;
	int				h_t;
	int				h_b;
}					t_area;

#endif