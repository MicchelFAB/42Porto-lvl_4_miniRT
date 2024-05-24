/**
 * @file create_objs.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief  File with functions to create objects for the project.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "minirt.h"
/**
 * @brief Function to initialize a new cylinder object.
 * 
 * @return t_cylinder* 
 */
t_cylinder	*ft_create_cylinder(void)
{
	static int	id;
	t_cylinder	*cyl;

	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
		return (NULL);
	cyl->id = id++;
	cyl->minimum = -INFINITY;
	cyl->maximum = INFINITY;
	cyl->closed = false;
	return (cyl);
}
/**
 * @brief Function to initialize a new plane object.
 * 
 * @return t_plane* 
 */
t_plane	*ft_create_plane(void)
{
	static int	id;
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->id = id++;
	return (plane);
}
/**
 * @brief Function to initialize a new sphere object.
 * 
 * @return t_sphere* 
 */
t_sphere	*ft_create_sphere(void)
{
	static int	id;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->id = id++;
	return (sphere);
}
