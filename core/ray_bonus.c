/**
 * @file ray_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File complementar to ray.c containing functions to calculate the color
 * of a ray. Only used in the bonus part of the project.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "core.h"
/**
 * @brief Calculate the color of a ray.
 * @param world The world.
 * @param r The ray.
 * @param remaining The remaining bounces.
 * @return t_color The color of the ray.
 */
t_color	ft_color_at_bonus(t_world *world, t_ray r, int remaining)
{
	t_intersections	*i;
	t_intersection	*hit;
	t_comps			*comps;
	t_color			c;
		t_list	*objects;

	i = NULL;

	objects = world->objects;
	while (objects)
	{
		ft_intersect_bonus(&i, objects->content, r);
		objects = objects->next;
	}
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
