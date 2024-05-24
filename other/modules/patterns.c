/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:55:31 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/19 17:49:55 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

t_pattern	ft_create_pattern(int pattern_type, t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.type = pattern_type;
	pattern.a = a;
	pattern.b = b;
	pattern.transform = ft_create_matrix(4, 4, YES);
	pattern.inverted = ft_create_matrix(4, 4, YES);
	pattern.xpm = (t_canvas){0};
	return (pattern);
}

void	ft_set_pattern_transform(t_pattern *pattern, t_matrix transform)
{
	pattern->transform = transform;
	pattern->inverted = ft_create_invert_matrix(transform);
}

t_color	ft_pattern_at_shape(t_pattern pattern, t_shapes *object,
		t_point world_point)
{
	t_point	object_point;
	t_point	pattern_point;

	object_point = ft_multiply_matrix_tuple(object->inverted, world_point);
	pattern_point = ft_multiply_matrix_tuple(pattern.inverted, object_point);
	if (pattern.type == STRIPES)
		return (ft_stripe_at(pattern, pattern_point));
	else if (pattern.type == GRADIENT)
		return (ft_gradient_at(pattern, pattern_point));
	else if (pattern.type == RING)
		return (ft_ring_at(pattern, object->type, pattern_point));
	else if (pattern.type == CHECKERS)
		return (ft_checkers_at(pattern, pattern_point));
	else if (pattern.type == XPM)
	{
		if (object->type == PLANE)
			return (ft_xpm_at_plane(pattern, pattern_point));
		else if (object->type == SPHERE)
			return (ft_xpm_at_sphere(pattern, pattern_point));
		return (ft_xpm_at(pattern, pattern_point));
	}
	return (ft_color(0, 0, 0));
}

t_color	ft_stripe_at(t_pattern pattern, t_point point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (pattern.a);
	else
		return (pattern.b);
}

t_color	ft_gradient_at(t_pattern pattern, t_point point)
{
	t_color	distance;
	double	fraction;

	distance = ft_operations(pattern.b, '-', pattern.a);
	fraction = point.x;
	return (ft_operations(pattern.a, '+', ft_oper_specular(distance, '*',
				fraction)));
}
