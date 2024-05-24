/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:51:22 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/13 12:38:27 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

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
