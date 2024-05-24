/**
 * @file computations.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing functions to prepare computations and calculate the
 * surface color of an object.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "core.h"
/**
 * @brief Function to check and calculate if the ray is inside an object.
 * 
 * @param comps 
 * @param xs 
 * @param hit 
 */
void	ft_calculate_refracted_indices(t_comps *comps, t_intersections **xs,
		t_intersection *hit)
{
	t_intersections	*i;
	t_list			*containers;
	t_shapes		*shape;
	t_shapes	*last;

	i = *xs;
	containers = NULL;
	while (i)
	{
		if (i->content == hit)
		{
			if (containers)
				last = ft_lst_last(containers)->content;
			if (!containers)
				comps->n1 = (1.0);
			else
				comps->n1 = (last->material.refractive_index);
		}
		shape = ((t_intersection *)i->content)->object;
		if (ft_lst_contains(containers, shape) == true)
			ft_lst_remove(&containers, shape);
		else
			ft_lstadd_back(&containers, ft_lstnew(shape));
		if (i->content == hit)
		{
			if (containers)
				last = ft_lst_last(containers)->content;
			if (!containers)
				comps->n2 = (1.0);
			else
				comps->n2 = (last->material.refractive_index);
			ft_free_list(&containers);
			return ;
		}
		i = i->next;
	}
}
/**
 * @brief Prepare the computations for a hit intersection.
 * 
 * @param lst The list of intersections.
 * @param hit The hit intersection.
 * @param r The ray.
 * @return t_comps* The prepared computations.
 */
t_comps	*ft_prepare_computations(t_intersections **lst, t_intersection *hit,
		t_ray r)
{
	t_comps	*comps;

	comps = ft_calloc(1, sizeof(t_comps));
	if (!comps)
		return (NULL);
	comps->t = hit->t;
	comps->object = hit->object;
	comps->point = ft_operations(r.origin, '+', ft_oper_specular(r.direction, '*', comps->t));
	comps->eyev = ft_oper_specular(r.direction, '*', -1);
	comps->normalv = ft_normal_at(comps->object, comps->point);
	if (ft_dot(comps->normalv, comps->eyev) < 0)
	{
		comps->inside = true;
		comps->normalv = ft_oper_specular(comps->normalv, '*', -1);
	}
	else
		comps->inside = false;
	comps->over_point = ft_operations(comps->point, '+', ft_oper_specular(comps->normalv, '*', EPSILON));
	comps->under_point = ft_operations(comps->point, '-', ft_oper_specular(comps->normalv, '*', EPSILON));
	comps->reflectv = ft_operations(r.direction, '-', ft_oper_specular(comps->normalv, '*', 2 * ft_dot(r.direction, comps->normalv)));
	ft_calculate_refracted_indices(comps, lst, hit);
	return (comps);
}
/**
 * @brief Calculate the surface color of an object.
 * 
 * @param world The world.
 * @param comps The computations.
 * @return t_color The surface color.
 */
t_color	ft_surface(t_world *world, t_comps *comps)
{
	t_list	*temp;
	t_color	surface;
	bool	shadowed;

	surface = ft_operations(comps->object->material.color, '*', comps->object->material.ambient);
	temp = world->lights;
	while (temp)
	{
		shadowed = ft_is_shadowed(world, temp->content, comps->over_point);
		surface = ft_operations(surface, '+', ft_lighting(comps->object->material, comps, temp->content, shadowed));
		temp = temp->next;
	}
	return (surface);
}
/**
 * @brief Calculate the color of a hit intersection.
 * 
 * @param world The world.
 * @param comps The computations.
 * @param remaining The remaining reflections.
 * @return t_color The color of the hit intersection.
 */
t_color	ft_shade_hit(t_world *world, t_comps *comps, int remaining)
{
	bool		shadowed;
	double		reflectance;
	t_list		*temp;
	t_color		surface;
	t_ray		surface_ray;
	t_material	m;

	surface_ray.direction = ft_reflected_color(world, comps, remaining);
	surface_ray.origin = ft_refracted_color(world, comps, remaining);
	m = comps->object->material;
	surface = ft_operations(comps->object->material.color, '*', comps->object->material.ambient);
	temp = world->lights;
	while (temp)
	{
		shadowed = ft_is_shadowed(world, temp->content, comps->over_point);
		surface = ft_operations(surface, '+', ft_lighting(comps->object->material, comps, temp->content, shadowed));
		temp = temp->next;
	}
	if (m.reflective > 0 && m.transparency > 0)
	{
		reflectance = ft_schlick(comps);
		return (ft_operations(surface, '+', ft_operations(ft_oper_specular(surface_ray.direction, '*', reflectance), '+', ft_oper_specular(surface_ray.origin, '*', (1 - reflectance)))));
	}
	return (ft_operations(ft_operations(surface, '+', surface_ray.direction), '+',surface_ray.origin));
}
