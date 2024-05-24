/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:07:27 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/13 10:44:31 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

bool	ft_is_shadowed_b(t_world *w, t_light *light, t_point point)
{
	t_vec3			v;
	double			distance;
	t_vec3			direction;
	t_intersection	*hit;
	t_intersections	*i;

	i = NULL;
	v = ft_operations(light->position, '-', point);
	distance = ft_length(v);
	direction = ft_normalize(v);
	ft_world_intersections_b(&i, w, ft_create_ray(point, direction));
	hit = ft_hit(i);
	if (hit && hit->t < distance)
	{
		ft_free_intersections(&i);
		return (true);
	}
	ft_free_intersections(&i);
	return (false);
}
