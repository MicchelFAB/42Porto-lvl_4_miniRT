/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:52:09 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/11 19:28:11 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
