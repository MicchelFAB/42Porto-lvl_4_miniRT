/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:51:22 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/19 17:47:55 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	ft_set_shape_transform(t_shapes *shapes, t_matrix transform)
{
	shapes->transform = transform;
	shapes->inverted = ft_create_invert_matrix(transform);
}

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

void	ft_add_shapes(t_list **lst, t_shapes *shapes)
{
	t_list	*new;

	new = ft_lstnew(shapes);
	if (!*lst)
		*lst = new;
	else
		ft_lstadd_back(lst, new);
}
