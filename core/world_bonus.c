/**
 * @file world_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief This file is complementary to the world.c file. It contains the
 * functions that are used to calculate the intersections of the objects in the
 * world. Only used in the bonus part of the project.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "core.h"
/**
 * @brief Calculate the intersections of the objects in the world.
 * @param i The list of intersections.
 * @param world The world.
 * @param ray The ray.
 */
void	ft_world_intersections_b(t_intersections **i, t_world *world, t_ray ray)
{
	t_list	*objects;

	objects = world->objects;
	while (objects)
	{
		ft_intersect_bonus(i, objects->content, ray);
		objects = objects->next;
	}
}
