/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:30:24 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/13 11:49:16 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

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
