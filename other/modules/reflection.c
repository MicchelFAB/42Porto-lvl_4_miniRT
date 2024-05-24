/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:05:28 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/11 19:38:09 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_reflected_color(t_world *world, t_comps *comps, int remaining)
{
	t_ray	reflect_ray;
	t_color	color;

	if (remaining <= 0)
		return (ft_color(0, 0, 0));
	if (comps->object->material.reflective == 0)
		return (ft_color(0, 0, 0));
	reflect_ray = ft_create_ray(comps->over_point, comps->reflectv);
	color = ft_color_at(world, reflect_ray, remaining - 1);
	return (ft_oper_specular(color, '*', comps->object->material.reflective));
}

t_shapes	*ft_create_glass_sphere(void)
{
	t_shapes	*s;

	s = ft_create_shape(SPHERE);
	s->material.transparency = 1.0;
	s->material.refractive_index = 1.5;
	return (s);
}

t_vec3	ft_refract_dir(t_comps *comps, double n_ratio)
{
	double	cos_i;
	double	sin2_t;
	double	cos_t;
	t_vec3	dir;

	cos_i = ft_dot(comps->eyev, comps->normalv);
	sin2_t = n_ratio * n_ratio * (1 - cos_i * cos_i);
	if (sin2_t > 1)
		return (ft_color(0, 0, 0));
	cos_t = sqrt(1.0 - sin2_t);
	dir = ft_oper_specular(comps->normalv, '*', (n_ratio * cos_i - cos_t));
	dir = ft_operations(dir, '-', ft_oper_specular(comps->eyev, '*', n_ratio));
	return (dir);
}

t_color	ft_refracted_color(t_world *world, t_comps *comps, int remaining)
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
	color = ft_oper_specular(ft_color_at(world, refract_ray, remaining - 1),
			'*', comps->object->material.transparency);
	return (color);
}

double	ft_schlick(t_comps *comps)
{
	double	cos;
	double	r0;
	double	n;
	double	sin2_t;

	cos = ft_dot(comps->eyev, comps->normalv);
	if (comps->n1 > comps->n2)
	{
		n = comps->n1 / comps->n2;
		sin2_t = n * n * (1 - (cos * cos));
		if (sin2_t > 1)
			return (1.0);
		cos = sqrt(1.0 - sin2_t);
	}
	r0 = pow(((comps->n1 - comps->n2) / (comps->n1 + comps->n2)), 2);
	return (r0 + (1 - r0) * pow((1 - cos), 5));
}
