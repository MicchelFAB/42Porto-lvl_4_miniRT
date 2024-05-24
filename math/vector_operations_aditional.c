/**
 * @file vector_operations_aditional.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the additional vector operations.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "maths.h"
/**
 * @brief Negates a vector.
 * 
 * @param vec The vector.
 * @return t_vec3 The negated vector.
 */
t_vec3	ft_negate(t_vec3 vec)
{
	return ((t_vec3){-vec.x, -vec.y, -vec.z, -vec.w});
}
/**
 * @brief Calculates the length of a vector.
 * 
 * @param vec The vector.
 * @return double The length of the vector.
 */
double	ft_length(t_vec3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}
/**
 * @brief Normalizes a vector.
 * 
 * @param vec The vector.
 * @return t_vec3 The normalized vector.
 */
t_vec3	ft_normalize(t_vec3 vec)
{
	double	length;

	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return ((t_vec3){0, 0, 0, vec.w});
	length = ft_length(vec);
	return ((t_vec3){vec.x / length, vec.y / length, vec.z / length, vec.w});
}
