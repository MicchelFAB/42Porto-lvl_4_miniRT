/**
 * @file patterns.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the pattern functions.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "modules.h"
/**
 * @brief Initializes a pattern.
 * @param pattern_type 
 * @param a 
 * @param b 
 * @return t_pattern 
 */
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
/**
 * @brief Sets the pattern transform.
 * @param pattern 
 * @param transform 
 */
void	ft_set_pattern_transform(t_pattern *pattern, t_matrix transform)
{
	pattern->transform = transform;
	pattern->inverted = ft_create_invert_matrix(transform);
}
/**
 * @brief Returns the color of the pattern at a given point.
 * @param pattern 
 * @param object 
 * @param world_point 
 * @return t_color 
 */
t_color	ft_pattern_at_shape(t_pattern pattern, t_shapes *object, t_point world_point)
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
/**
 * @brief Create a stripe pattern.
 * @param pattern 
 * @param point 
 * @return t_color 
 */
t_color	ft_stripe_at(t_pattern pattern, t_point point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (pattern.a);
	else
		return (pattern.b);
}
/**
 * @brief Create a gradient pattern.
 * @param pattern 
 * @param point 
 * @return t_color 
 */
t_color	ft_gradient_at(t_pattern pattern, t_point point)
{
	t_color	distance;
	double	fraction;

	distance = ft_operations(pattern.b, '-', pattern.a);
	fraction = point.x;
	return (ft_operations(pattern.a, '+', ft_oper_specular(distance, '*', fraction)));
}
