/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_criation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:33:09 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/10 23:33:34 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

// Creates a vector or point. If w is 1, it's a point. If w is 0, it's a vector.
t_vec3	ft_tuple(double x, double y, double z, double w)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return (vec);
}

// Creates a color.
t_color	ft_color(double r, double g, double b)
{
	return (ft_tuple(r, g, b, 3));
}

// Creates a point.
t_point	ft_point(double x, double y, double z)
{
	return (ft_tuple(x, y, z, 1));
}

// Creates a vector.
t_vec3	ft_vector(double x, double y, double z)
{
	return (ft_tuple(x, y, z, 0));
}
