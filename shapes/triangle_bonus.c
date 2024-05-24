/**
 * @file triangle_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to handle the triangle shape.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "shapes.h"
/**
 * @brief Function to initialize a new triangle object.
 * 
 * @param t 
 * @param p1 
 * @param p2 
 * @param p3 
 */
void	ft_set_triangle_points(t_triangle *t, t_point p1, t_point p2, t_point p3)
{
	t->p1 = p1;
	t->p2 = p2;
	t->p3 = p3;
	t->e1 = ft_operations(t->p2, '-', t->p1);
	t->e2 = ft_operations(t->p3, '-', t->p1);
	t->normal = ft_normalize(ft_cross(t->e2, t->e1));
}
/**
 * @brief Function to get the normal of the triangle at a given point.
 * 
 * @param t 
 * @param world_point 
 * @return t_vec3 
 */
t_vec3	ft_triangle_normal_at(t_triangle *t, t_point world_point)
{
	(void)world_point;
	return (t->normal);
}
/**
 * @brief Function to handle the triangle intersections.
 * 
 * @param xs 
 * @param s 
 * @param r 
 */
void	ft_triangle_intersections(t_intersections **xs, t_shapes *s, t_ray r)
{
	t_vec3	dir_cross_e2;
	double	det;
	t_vec3	misc;
	t_vec3	p1_to_origin;
	t_vec3	origin_cross_e1;

	dir_cross_e2 = ft_cross(r.direction, s->triangle->e2);
	det = ft_dot(s->triangle->e1, dir_cross_e2);
	if (fabs(det) < EPSILON)
		return ;
	misc.x = 1 / det;
	p1_to_origin = ft_operations(r.origin, '-', s->triangle->p1);
	misc.w = misc.x * ft_dot(p1_to_origin, dir_cross_e2);
	if (misc.w < 0 || misc.w > 1)
		return ;
	origin_cross_e1 = ft_cross(p1_to_origin, s->triangle->e1);
	misc.y = misc.x * ft_dot(r.direction, origin_cross_e1);
	if (misc.y < 0 || (misc.w + misc.y) > 1)
		return ;
	misc.z = misc.x * ft_dot(s->triangle->e2, origin_cross_e1);
	return (ft_add_sorted_intersection(xs, s, misc.z));
}
