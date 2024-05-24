/**
 * @file shadow.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to calculate if a point is in shadow.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "light.h"
/**
 * @brief Check if a point is in shadow.
 * 
 * @param w The world.
 * @param light The light.
 * @param point The point.
 * @return true If the point is in shadow.\
 * @return false If the point is not in shadow.
 */
bool	ft_is_shadowed(t_world *w, t_light *light, t_point point)
{
	t_vec3			v;
	t_list			*objects;
	double			distance;
	t_vec3			direction;
	t_intersection	*hit;
	t_intersections	*i;

	i = NULL;
	v = ft_operations(light->position, '-', point);
	distance = ft_length(v);
	direction = ft_normalize(v);
	objects = w->objects;
	while (objects)
	{
		ft_intersect(&i, objects->content, ft_create_ray(point, direction));
		objects = objects->next;
	}
	hit = ft_hit(i);
	if (hit && hit->t < distance)
	{
		ft_free_intersections(&i);
		return (true);
	}
	ft_free_intersections(&i);
	return (false);
}
/**
 * @brief Calculate the color of the shadow.
 * 
 * @param in_shadow If the point is in shadow.
 * @param lighting The lighting.
 * @return t_color The color of the shadow.
 */
t_color	ft_shadow_color(bool in_shadow, t_lighting *lighting)
{
	t_color		color;

	if (in_shadow)
		color = lighting->amb;
	else
		color = ft_operations(ft_operations(lighting->amb, '+', lighting->diffuse), '+', lighting->specular);
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
