/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:30:24 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/10 23:27:39 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

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
