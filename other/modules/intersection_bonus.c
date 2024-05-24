/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:56:13 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/13 14:50:43 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

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
