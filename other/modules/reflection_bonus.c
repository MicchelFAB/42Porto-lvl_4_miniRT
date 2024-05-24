/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:05:28 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/13 11:50:33 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_reflected_color_bonus(t_world *world, t_comps *comps, int remaining)
{
	t_ray	reflect_ray;
	t_color	color;

	if (remaining <= 0)
		return (ft_color(0, 0, 0));
	if (comps->object->material.reflective == 0)
		return (ft_color(0, 0, 0));
	reflect_ray = ft_create_ray(comps->over_point, comps->reflectv);
	color = ft_color_at_bonus(world, reflect_ray, remaining - 1);
	return (ft_oper_specular(color, '*', comps->object->material.reflective));
}

t_color	ft_refracted_color_bonus(t_world *world, t_comps *comps, int remaining)
{
	double	n_ratio;
	t_vec3	dir;
	t_ray	refract_ray;
	t_color	color;

	if (remaining <= 0)
		return (ft_color(0, 0, 0));
	if (comps->object->material.transparency == 0)
		return (ft_color(0, 0, 0));
	n_ratio = comps->n1 / comps->n2;
	dir = ft_refract_dir(comps, n_ratio);
	if (ft_length(dir) == 0)
		return (ft_color(0, 0, 0));
	refract_ray = ft_create_ray(comps->under_point, dir);
	color = ft_oper_specular(ft_color_at_bonus(world, refract_ray, remaining
				- 1), '*', comps->object->material.transparency);
	return (color);
}
