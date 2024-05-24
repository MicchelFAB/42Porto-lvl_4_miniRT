/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:48:56 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/13 13:27:52 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_comps	*ft_prepare_computations_bonus(t_intersections **lst,
		t_intersection *hit, t_ray r)
{
	t_comps	*comps;

	comps = ft_calloc(1, sizeof(t_comps));
	if (!comps)
		return (NULL);
	comps->t = hit->t;
	comps->object = hit->object;
	comps->point = ft_ray_position(r, comps->t);
	comps->eyev = ft_oper_specular(r.direction, '*', -1);
	comps->normalv = ft_normal_at_bonus(comps->object, comps->point);
	if (ft_dot(comps->normalv, comps->eyev) < 0)
	{
		comps->inside = true;
		comps->normalv = ft_oper_specular(comps->normalv, '*', -1);
	}
	else
		comps->inside = false;
	comps->over_point = ft_operations(comps->point, '+',
			ft_oper_specular(comps->normalv, '*', EPSILON));
	comps->under_point = ft_operations(comps->point, '-',
			ft_oper_specular(comps->normalv, '*', EPSILON));
	comps->reflectv = ft_reflect(r.direction, comps->normalv);
	ft_calculate_refracted_indices(comps, lst, hit);
	return (comps);
}

t_color	ft_surface_bonus(t_world *world, t_comps *comps)
{
	t_list	*temp;
	t_color	surface;
	bool	shadowed;

	surface = ft_operations(comps->object->material.color, '*',
			comps->object->material.ambient);
	temp = world->lights;
	while (temp)
	{
		shadowed = ft_is_shadowed_b(world, temp->content, comps->over_point);
		surface = ft_operations(surface, '+',
				ft_lighting(comps->object->material, comps, temp->content,
					shadowed));
		temp = temp->next;
	}
	return (surface);
}

t_color	ft_shade_hit_bonus(t_world *world, t_comps *comps, int remaining)
{
	t_color		surface;
	t_color		reflected;
	t_color		refracted;
	t_material	m;
	double		reflectance;

	surface = ft_surface_bonus(world, comps);
	reflected = ft_reflected_color(world, comps, remaining);
	refracted = ft_refracted_color(world, comps, remaining);
	m = comps->object->material;
	if (m.reflective > 0 && m.transparency > 0)
	{
		reflectance = ft_schlick(comps);
		return (ft_operations(surface, '+',
				ft_operations(ft_oper_specular(reflected, '*', reflectance),
					'+', ft_oper_specular(refracted, '*', (1 - reflectance)))));
	}
	return (ft_operations(ft_operations(surface, '+', reflected), '+',
			refracted));
}
