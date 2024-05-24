/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_aditional.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:34:03 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/11 17:36:12 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

// Creates a vector in the opposite direction (basically 
//ft_oper_specular(vec, '*', -1).
t_vec3	ft_negate(t_vec3 vec)
{
	return ((t_vec3){-vec.x, -vec.y, -vec.z, -vec.w});
}

// Calculates the length of a vector (AKA magnitude).
double	ft_length(t_vec3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

// Normalizes a vector, which means it makes the vector have a length of 1.
t_vec3	ft_normalize(t_vec3 vec)
{
	double	length;

	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return ((t_vec3){0, 0, 0, vec.w});
	length = ft_length(vec);
	return ((t_vec3){vec.x / length, vec.y / length, vec.z / length, vec.w});
}
