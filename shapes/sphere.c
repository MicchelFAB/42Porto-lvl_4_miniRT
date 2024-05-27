/**
 * @file sphere.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to handle the sphere shape.
 * @version 0.1
 * @date 2024-05-24 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "minirt.h"
/**
 * @brief Function to initialize a new sphere object.
 * @param i 
 * @param s 
 * @param r 
 */
void	ft_sphere_intersections(t_intersections **i, t_shapes *s, t_ray r)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_vec3	sphere_to_ray;

	sphere_to_ray = ft_operations(r.origin, '-', ft_point(0, 0, 0));
	a = ft_dot(r.direction, r.direction);
	b = 2 * ft_dot(r.direction, sphere_to_ray);
	c = ft_dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return ;
	else
	{
		ft_add_sorted_intersection(i, s, (-b - sqrt(discriminant)) / (2 * a));
		ft_add_sorted_intersection(i, s, (-b + sqrt(discriminant)) / (2 * a));
	}
}
