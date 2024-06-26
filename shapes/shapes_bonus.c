/**
 * @file shapes_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File to handle the parsing of the bonus shapes.
 * @version 0.1
 * @date 2024-05-24 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "shapes.h"
/**
 * @brief Function to select the shape to be created.
 * @param type 
 * @return t_shapes* 
 */
t_shapes	*ft_create_shape_bonus(int type)
{
	t_shapes	*shapes;

	shapes = malloc(sizeof(t_shapes));
	if (!shapes)
		return (NULL);
	shapes->type = type;
	if (type == SPHERE)
		shapes->sphere = ft_create_sphere();
	else if (type == PLANE)
		shapes->plane = ft_create_plane();
	else if (type == CYLINDER)
		shapes->cylinder = ft_create_cylinder();
	else if (type == CONE)
		shapes->cone = ft_create_cone();
	else if (type == CUBE)
		shapes->cube = ft_create_cube();
	else if (type == TRIANGLE)
		shapes->triangle = ft_create_triangle();
	shapes->transform = ft_create_matrix(4, 4, YES);
	shapes->inverted = ft_create_matrix(4, 4, YES);
	shapes->material = ft_create_material();
	shapes->normal = ft_vector(0, 0, 0);
	return (shapes);
}
