/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:49:20 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/11 19:38:03 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
