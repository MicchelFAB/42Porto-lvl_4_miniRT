/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:52:52 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/13 13:36:58 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

void	ft_set_triangle_points(t_triangle *t, t_point p1, t_point p2,
		t_point p3)
{
	t->p1 = p1;
	t->p2 = p2;
	t->p3 = p3;
	t->e1 = ft_operations(t->p2, '-', t->p1);
	t->e2 = ft_operations(t->p3, '-', t->p1);
	t->normal = ft_normalize(ft_cross(t->e2, t->e1));
}

t_vec3	ft_triangle_normal_at(t_triangle *t, t_point world_point)
{
	(void)world_point;
	return (t->normal);
}

void	ft_triangle_intersections(t_intersections **xs, t_shapes *s, t_ray r)
{
	t_vec3	dir_cross_e2;
	double	det;
	t_vec3	misc;
	t_vec3	p1_to_origin;
	t_vec3	origin_cross_e1;

	dir_cross_e2 = ft_cross(r.direction, s->triangle->e2);
	det = ft_dot(s->triangle->e1, dir_cross_e2);
	if (fabs(det) < EPSILON)
		return ;
	misc.x = 1 / det;
	p1_to_origin = ft_operations(r.origin, '-', s->triangle->p1);
	misc.w = misc.x * ft_dot(p1_to_origin, dir_cross_e2);
	if (misc.w < 0 || misc.w > 1)
		return ;
	origin_cross_e1 = ft_cross(p1_to_origin, s->triangle->e1);
	misc.y = misc.x * ft_dot(r.direction, origin_cross_e1);
	if (misc.y < 0 || (misc.w + misc.y) > 1)
		return ;
	misc.z = misc.x * ft_dot(s->triangle->e2, origin_cross_e1);
	return (ft_add_sorted_intersection(xs, s, misc.z));
}
