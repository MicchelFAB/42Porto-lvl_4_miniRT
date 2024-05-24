/**
 * @file world.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing functions to create and manipulate the world.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "core.h"
/**
 * @brief Create a world.
 * 
 * @return t_world* The created world.
 */
t_world	*ft_create_world(void)
{
	t_world	*world;

	world = ft_calloc(1, sizeof(t_world));
	if (!world)
		return (NULL);
	world->key = (t_key_map){0};
	world->objects = NULL;
	world->lights = NULL;
	return (world);
}
/**
 * @brief Function to free the world.
 * 
 * @param world 
 */
void	ft_free_world(t_world *world)
{
	t_list	*tmp;

	while (world->objects)
	{
		tmp = world->objects;
		world->objects = world->objects->next;
		ft_free_shapes((t_shapes *)(tmp->content));
		free(tmp);
	}
	while (world->lights)
	{
		tmp = world->lights;
		world->lights = world->lights->next;
		free(tmp);
	}
	free(world);
}
/**
 * @brief Function to calculate the intersections of the objects in the world.
 * 
 * @param i 
 * @param world 
 * @param ray 
 */
void	ft_world_intersections(t_intersections **i, t_world *world, t_ray ray)
{
	t_list	*objects;

	objects = world->objects;
	while (objects)
	{
		ft_intersect(i, objects->content, ray);
		objects = objects->next;
	}
}
