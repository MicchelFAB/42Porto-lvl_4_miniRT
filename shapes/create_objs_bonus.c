/**
 * @file create_objs_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File with functions to create objects for the bonus part of the project.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "minirt.h"
/**
 * @brief Function to initialize a new cone object.
 * 
 * @return t_cone* 
 */
t_cone	*ft_create_cone(void)
{
	static int	id;
	t_cone		*cone;

	cone = malloc(sizeof(t_cone));
	if (!cone)
		return (NULL);
	cone->id = id++;
	cone->minimum = -INFINITY;
	cone->maximum = INFINITY;
	cone->closed = false;
	return (cone);
}
/**
 * @brief Function to initialize a new cube
 * 
 * @return t_cube* 
 */
t_cube	*ft_create_cube(void)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (!cube)
		return (NULL);
	return (cube);
}
/**
 * @brief Function to initialize a new triangle object.
 * 
 * @return t_triangle* 
 */
t_triangle	*ft_create_triangle(void)
{
	static int	id;
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	if (!triangle)
		return (NULL);
	triangle->id = id++;
	triangle->p1 = ft_point(0, 1, 0);
	triangle->p2 = ft_point(-1, 0, 0);
	triangle->p3 = ft_point(1, 0, 0);
	triangle->e1 = ft_operations(triangle->p2, '-', triangle->p1);
	triangle->e2 = ft_operations(triangle->p3, '-', triangle->p1);
	triangle->normal = ft_normalize(ft_cross(triangle->e2, triangle->e1));
	return (triangle);
}
