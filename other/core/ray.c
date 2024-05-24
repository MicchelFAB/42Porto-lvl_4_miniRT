/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:45:48 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/10 18:33:40 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

// This function creates a ray with an origin and a direction.
t_ray	ft_create_ray(t_point origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

// This function returns the position of the ray at a certain distance t.
t_point	ft_ray_position(t_ray ray, double t)
{
	t_point	position;

	position = ft_operations(ray.origin, '+', ft_oper_specular(ray.direction,
				'*', t));
	return (position);
}

// Returns a new ray that is now multiplied by the matrix. Wherever transforma-
// tion you want from the sphere, you can apply the inverse of that to the ray.
t_ray	ft_transform_ray(t_ray ray, t_matrix matrix)
{
	t_ray	r;

	r.origin = ft_multiply_matrix_tuple(matrix, ray.origin);
	r.direction = ft_multiply_matrix_tuple(matrix, ray.direction);
	return (r);
}

t_color	ft_color_at(t_world *world, t_ray r, int remaining)
{
	t_intersections	*i;
	t_intersection	*hit;
	t_comps			*comps;
	t_color			c;

	i = NULL;
	ft_world_intersections(&i, world, r);
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
