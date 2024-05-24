/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:58:39 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/13 12:30:31 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_cube	*ft_create_cube(void)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (!cube)
		return (NULL);
	return (cube);
}

t_triangle	*ft_create_triangle(void)
{
	static int	id;
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	if (!triangle)
		return (NULL);
	triangle->id = id++;
	triangle->p1 = (t_point){0, 1, 0, 1};
	triangle->p2 = (t_point){-1, 0, 0, 1};
	triangle->p3 = (t_point){1, 0, 0, 1};
	triangle->e1 = ft_operations(triangle->p2, '-', triangle->p1);
	triangle->e2 = ft_operations(triangle->p3, '-', triangle->p1);
	triangle->normal = ft_normalize(ft_cross(triangle->e2, triangle->e1));
	return (triangle);
}
