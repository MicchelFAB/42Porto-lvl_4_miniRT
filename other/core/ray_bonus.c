/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:45:48 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/13 10:45:55 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_color	ft_color_at_bonus(t_world *world, t_ray r, int remaining)
{
	t_intersections	*i;
	t_intersection	*hit;
	t_comps			*comps;
	t_color			c;

	i = NULL;
	ft_world_intersections_b(&i, world, r);
	hit = ft_hit(i);
	if (hit)
	{
		comps = ft_prepare_computations_bonus(&i, hit, r);
		c = ft_shade_hit_bonus(world, comps, remaining);
		free(comps);
	}
	else
		c = ft_color(0, 0, 0);
	ft_free_intersections(&i);
	return (c);
}
