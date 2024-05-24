/**
 * @file vector_criation.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to create vectors, points and colors.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "maths.h"
/**
 * @brief Creates a tuple.
 * @param x The x value.
 * @param y The y value.
 * @param z The z value.
 * @param w The w value.
 * @return t_vec3 The tuple.
 */
t_vec3	ft_tuple(double x, double y, double z, double w)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return (vec);
}
/**
 * @brief Creates a color.
 * @param r The red value.
 * @param g The green value.
 * @param b The blue value.
 * @return t_color The color.
 */
t_color	ft_color(double r, double g, double b)
{
	return (ft_tuple(r, g, b, 3));
}
/**
 * @brief Creates a point.
 * @param x The x value.
 * @param y The y value.
 * @param z The z value.
 * @return t_point The point.
 */
t_point	ft_point(double x, double y, double z)
{
	return (ft_tuple(x, y, z, 1));
}
/**
 * @brief Creates a vector.
 * @param x The x value.
 * @param y The y value.
 * @param z The z value.
 * @return t_vec3 The vector.
 */
t_vec3	ft_vector(double x, double y, double z)
{
	return (ft_tuple(x, y, z, 0));
}
