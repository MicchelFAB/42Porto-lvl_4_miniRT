/**
 * @file vector_operations.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the vector operations.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "maths.h"
/**
 * @brief Performs an operation between two vectors.
 * 
 * @param a The first vector.
 * @param op The operation.
 * @param b The second vector.
 * @return t_vec3 The result of the operation.
 */
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
/**
 * @brief Performs an operation between a vector and a double.
 * 
 * @param a The vector.
 * @param op The operation.
 * @param b The double.
 * @return t_vec3 The result of the operation.
 */
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
/**
 * @brief Calculates the dot product of two vectors.
 * 
 * @param a The first vector.
 * @param b The second vector.
 * @return double The dot product.
 */
double	ft_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
/**
 * @brief Calculates the cross product of two vectors.
 * 
 * @param a The first vector.
 * @param b The second vector.
 * @return t_vec3 The cross product.
 */
t_vec3	ft_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y
		- a.y * b.x, a.w});
}
/**
 * @brief Compares two doubles.
 * 
 * @param a The first double.
 * @param b The second double.
 * @return true If the doubles are equal.\
 * @return false If the doubles are different.
 */
bool	ft_double_compare(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}
