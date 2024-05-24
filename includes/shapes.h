/**
 * @file shapes.h
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief Include file for the shapes functions.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SHAPES_H
# define SHAPES_H

# include "minirt.h"

/***********CREATE*OBJECTS***********/

t_cylinder	*ft_create_cylinder(void);
t_plane		*ft_create_plane(void);
t_sphere	*ft_create_sphere(void);

/***********CREATE*OBJECTS*BONUS***********/
t_cone		*ft_create_cone(void);
t_cube		*ft_create_cube(void);
t_triangle	*ft_create_triangle(void);

/***********CYLINDER***********/
t_bhask		ft_bhask_form_cy(t_ray ray);
void		ft_cylinder_intersections(t_intersections **i, t_shapes *s,
				t_ray ray);
bool		ft_check_cap(t_ray ray, double t);
void		ft_cylinder_caps_intersections(t_intersections **i, t_shapes *s,
				t_ray ray);
t_vec3		ft_cylinder_normal_at(t_shapes *cyl, t_point point);

/***********PLANE***********/
void		ft_plane_intersections(t_intersections **i, t_shapes *p, t_ray r);

/***********SPHERE***********/
void		ft_sphere_intersections(t_intersections **i, t_shapes *s, t_ray r);

/**********CONE*BONUS***********/
t_bhask		ft_bhask_form_cone(t_ray ray);
void		ft_cone_intersections(t_intersections **i, t_shapes *s, t_ray ray);
bool		ft_check_cone_cap(t_ray ray, double t, double range);
void		ft_cone_caps_intersections(t_intersections **i, t_shapes *s,
				t_ray ray);
t_vec3		ft_cone_normal_at(t_shapes *cone, t_point point);

/**********CUBE*BONUS***********/
void		ft_check_axis(double *t, double origin, double direction);
void		ft_cube_intersections(t_intersections **intersections,
				t_shapes *cube, t_ray ray);
t_vec3		ft_cube_normal_at(t_point world_point);

/**********TRIANGLE*BONUS***********/
void		ft_set_triangle_points(t_triangle *t, t_point p1, t_point p2,
				t_point p3);
t_vec3		ft_triangle_normal_at(t_triangle *t, t_point world_point);
void		ft_triangle_intersections(t_intersections **xs, t_shapes *s,
				t_ray r);

/***********SHAPES***********/
t_shapes	*ft_create_shape(int type);
void		ft_set_shape_transform(t_shapes *shapes, t_matrix transform);
void		ft_free_shapes(t_shapes *shapes);
void		ft_add_shapes(t_list **lst, t_shapes *shapes);

/***********SHAPES*BONUS***********/
t_shapes	*ft_create_shape_bonus(int type);

#endif