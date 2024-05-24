/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:33:59 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/17 19:10:19 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

// Adds, subtracts or multiplies two vectors.
t_vec3	ft_operations(t_vec3 a, char op, t_vec3 b)
{
	double	w;

	w = a.w || b.w;
	if (a.w == 3 && b.w == 3)
		w = 3;
	if (op == '+')
		return ((t_vec3){a.x + b.x, a.y + b.y, a.z + b.z, w});
	if (op == '-')
	{
		if (a.w && b.w && a.w != 3)
			w = 0;
		return ((t_vec3){a.x - b.x, a.y - b.y, a.z - b.z, w});
	}
	if (op == '*')
		return ((t_vec3){a.x * b.x, a.y * b.y, a.z * b.z, w});
	return ((t_vec3){0, 0, 0, 0});
}

// Multiplies or divides a vector by a scalar.
t_vec3	ft_oper_specular(t_vec3 a, char op, double b)
{
	if (op == '+')
		return ((t_vec3){a.x + b, a.y + b, a.z + b, a.w});
	if (op == '*')
		return ((t_vec3){a.x * b, a.y * b, a.z * b, a.w});
	if (op == '/')
		return ((t_vec3){a.x / b, a.y / b, a.z / b, a.w});
	return ((t_vec3){0, 0, 0, 0});
}

// Multiplies each element of two vectors and adds the results.
double	ft_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// Calculates the perpendicular vector to two vectors.
t_vec3	ft_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y
		- a.y * b.x, a.w});
}

// Compares two doubles.
bool	ft_double_compare(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}
