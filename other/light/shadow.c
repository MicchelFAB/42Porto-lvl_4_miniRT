/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:07:27 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/20 11:40:42 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

bool	ft_is_shadowed(t_world *w, t_light *light, t_point point)
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
	ft_world_intersections(&i, w, ft_create_ray(point, direction));
	hit = ft_hit(i);
	if (hit && hit->t < distance)
	{
		ft_free_intersections(&i);
		return (true);
	}
	ft_free_intersections(&i);
	return (false);
}

t_color	ft_shadow_color(bool in_shadow, t_lighting *lighting)
{
	t_color		color;

	if (in_shadow)
		color = lighting->amb;
	else
		color = ft_operations(ft_operations(lighting->amb, '+',
					lighting->diffuse), '+', lighting->specular);
	return (color);
}

void	ft_add_lights(t_list **lst, t_light *light)
{
	t_list	*new;

	new = ft_lstnew(light);
	if (!*lst)
		*lst = new;
	else
		ft_lstadd_back(lst, new);
}

int	ft_chk_file(char *file)
{
	if (ft_strnrcmp(file, ".rt", 3) != 0 || ft_strnrcmp(file, "/.rt", 4) == 0
		|| strlen(file) < 4)
		return (1);
	return (0);
}
