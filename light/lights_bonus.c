/**
 * @file lights_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to calculate the normal at a point in 
 * the bonus part of the project.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "light.h"

t_vec3	ft_normal_at_bonus(t_shapes *s, t_point world_point)
{
	t_point	object_point;
	t_vec3	object_normal;
	t_vec3	world_normal;

	object_point = ft_multiply_matrix_tuple(s->inverted, world_point);
	object_normal = ft_vector(0, 0, 0);
	if (s->type == SPHERE)
		object_normal = ft_operations(object_point, '-', ft_point(0, 0, 0));
	else if (s->type == PLANE)
		object_normal = ft_vector(0, 1, 0);
	else if (s->type == CYLINDER)
		object_normal = ft_cylinder_normal_at(s, object_point);
	else if (s->type == CONE)
		object_normal = ft_cone_normal_at(s, object_point);
	else if (s->type == CUBE)
		object_normal = ft_cube_normal_at(object_point);
	else if (s->type == TRIANGLE)
		return (s->triangle->normal);
	world_normal = ft_multiply_matrix_tuple(ft_transpose_matrix(s->inverted), object_normal);
	world_normal.w = 0;
	return (ft_normalize(world_normal));
}
