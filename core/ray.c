/**
 * @file ray.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing functions to create and manipulate rays.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "core.h"
/**
 * @brief Create a ray.
 * @param origin The origin of the ray.
 * @param direction The direction of the ray.
 * @return t_ray The created ray.
 */
t_ray	ft_create_ray(t_point origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}
/**
 * @brief Calculate the position of a ray at a given distance.
 * @param ray The ray.
 * @param t The distance.
 * @return t_point The position of the ray.
 */
t_point	ft_ray_position(t_ray ray, double t)
{
	return (ft_operations(ray.origin, '+', ft_oper_specular(ray.direction, '*', t)));
}
/**
 * @brief Transform a ray by a matrix.
 * @param ray The ray.
 * @param matrix The matrix.
 * @return t_ray The transformed ray.
 */
t_ray	ft_transform_ray(t_ray ray, t_matrix matrix)
{
	t_ray	r;

	r.origin = ft_multiply_matrix_tuple(matrix, ray.origin);
	r.direction = ft_multiply_matrix_tuple(matrix, ray.direction);
	return (r);
}
/**
 * @brief Calculate the color of a ray.
 * @param world The world.
 * @param r The ray.
 * @param remaining The remaining bounces.
 * @return t_color The color of the ray.
 */
t_color	ft_color_at(t_world *world, t_ray r, int remaining)
{
	t_intersections	*i;
	t_intersection	*hit;
	t_comps			*comps;
	t_color			c;
	t_list			*objects;

	i = NULL;
	objects = world->objects;
	while (objects)
	{
		ft_intersect(&i, objects->content, r);
		objects = objects->next;
	}
	hit = ft_hit(i);
	if (hit)
	{
		comps = ft_prepare_computations(&i, hit, r);
		c = ft_shade_hit(world, comps, remaining);
		free(comps);
	}
	else
		c = ft_color(0, 0, 0);
	ft_free_intersections(&i);
	return (c);
}
