/**
 * @file intersection_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the intersection functions. Complement to the main intersection file.
 * used for the bonus part of the project.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "modules.h"
/**
 * @brief Calls the intersections according to the shape.
 * 
 * @param i 
 * @param s 
 * @param r 
 */
void	ft_intersect_bonus(t_intersections **i, t_shapes *s, t_ray r)
{
	t_ray	ray;

	ray = ft_transform_ray(r, s->inverted);
	if (s->type == SPHERE)
		ft_sphere_intersections(i, s, ray);
	if (s->type == PLANE)
		ft_plane_intersections(i, s, ray);
	if (s->type == CYLINDER)
		ft_cylinder_intersections(i, s, ray);
	if (s->type == CONE)
		ft_cone_intersections(i, s, ray);
	if (s->type == CUBE)
		ft_cube_intersections(i, s, ray);
	if (s->type == TRIANGLE)
		ft_triangle_intersections(i, s, ray);
}
