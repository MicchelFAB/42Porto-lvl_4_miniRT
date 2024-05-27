/**
 * @file shapes.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File to handle the parsing of the shapes.
 * @version 0.1
 * @date 2024-05-24 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "minirt.h"
/**
 * @brief Function to select the shape to be created.
 * @param type 
 * @return t_shapes* 
 */
t_shapes	*ft_create_shape(int type)
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
	shapes->transform = ft_create_matrix(4, 4, YES);
	shapes->inverted = ft_create_matrix(4, 4, YES);
	shapes->material = ft_create_material();
	shapes->normal = ft_vector(0, 0, 0);
	return (shapes);
}
/**
 * @brief Function to set the shape transform an create its inverted matrix.
 * @param shapes 
 * @param transform 
 */
void	ft_set_shape_transform(t_shapes *shapes, t_matrix transform)
{
	shapes->transform = transform;
	shapes->inverted = ft_create_invert_matrix(transform);
}
/**
 * @brief Function to free the shapes.
 * @param shapes 
 */
void	ft_free_shapes(t_shapes *shapes)
{
	if (shapes->type == SPHERE)
		free(shapes->sphere);
	else if (shapes->type == PLANE)
		free(shapes->plane);
	else if (shapes->type == CYLINDER)
		free(shapes->cylinder);
	else if (shapes->type == CONE)
		free(shapes->cone);
	else if (shapes->type == CUBE)
		free(shapes->cube);
	else if (shapes->type == TRIANGLE)
		free(shapes->triangle);
	if (shapes->material.pattern.type == XPM)
		ft_free_canvas(shapes->material.pattern.xpm);
	free(shapes);
}
/**
 * @brief Function to add the shapes to a linked list.
 * @param lst 
 * @param shapes 
 */
void	ft_add_shapes(t_list **lst, t_shapes *shapes)
{
	t_list	*new;

	new = ft_lstnew(shapes);
	if (!*lst)
		*lst = new;
	else
		ft_lstadd_back(lst, new);
}
