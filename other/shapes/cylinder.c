/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:49:44 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/11 19:38:09 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bhask	ft_bhask_form_cy(t_ray ray)
{
	t_bhask	bhask;
	double	temp;

	bhask.a = ray.direction.x * ray.direction.x
		+ ray.direction.z * ray.direction.z;
	if (bhask.a == 0)
		return (bhask);
	bhask.b = 2 * ray.origin.x * ray.direction.x
		+ 2 * ray.origin.z * ray.direction.z;
	bhask.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	bhask.discriminant = bhask.b * bhask.b - 4 * bhask.a * bhask.c;
	if (bhask.discriminant < 0)
		return (bhask);
	bhask.t0 = (-bhask.b - sqrt(bhask.discriminant)) / (2 * bhask.a);
	bhask.t1 = (-bhask.b + sqrt(bhask.discriminant)) / (2 * bhask.a);
	if (bhask.t0 > bhask.t1)
	{
		temp = bhask.t0;
		bhask.t0 = bhask.t1;
		bhask.t1 = temp;
	}
	return (bhask);
}

void	ft_cylinder_intersections(t_intersections **i, t_shapes *s, t_ray ray)
{
	t_bhask	bhask;
	double	y0;
	double	y1;

	ft_cylinder_caps_intersections(i, s, ray);
	bhask = ft_bhask_form_cy(ray);
	if (bhask.discriminant < 0)
		return ;
	y0 = ray.origin.y + bhask.t0 * ray.direction.y;
	if (s->cylinder->minimum < y0 && y0 < s->cylinder->maximum)
		ft_add_sorted_intersection(i, s, bhask.t0);
	y1 = ray.origin.y + bhask.t1 * ray.direction.y;
	if (s->cylinder->minimum < y1 && y1 < s->cylinder->maximum)
		ft_add_sorted_intersection(i, s, bhask.t1);
}

bool	ft_check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (x * x + z * z <= 1);
}

void	ft_cylinder_caps_intersections(t_intersections **i, t_shapes *s,
		t_ray ray)
{
	double	t;

	if (s->cylinder->closed == false || ray.direction.y == 0)
		return ;
	t = (s->cylinder->minimum - ray.origin.y) / ray.direction.y;
	if (ft_check_cap(ray, t))
		ft_add_sorted_intersection(i, s, t);
	t = (s->cylinder->maximum - ray.origin.y) / ray.direction.y;
	if (ft_check_cap(ray, t))
		ft_add_sorted_intersection(i, s, t);
}

t_vec3	ft_cylinder_normal_at(t_shapes *cyl, t_point point)
{
	double	dist;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= cyl->cylinder->maximum - EPSILON)
		return ((t_vec3){0, 1, 0, 0});
	if (dist < 1 && point.y <= cyl->cylinder->minimum + EPSILON)
		return ((t_vec3){0, -1, 0, 0});
	return ((t_vec3){point.x, 0, point.z, 0});
}
