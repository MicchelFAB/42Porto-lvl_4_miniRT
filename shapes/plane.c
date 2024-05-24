/**
 * @file plane.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to handle the plane shape.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "minirt.h"
/**
 * @brief Function to handle the plane intersections.
 * 
 * @param i 
 * @param p 
 * @param r 
 */
void	ft_plane_intersections(t_intersections **i, t_shapes *p, t_ray r)
{
	double	t;

	if (fabs(r.direction.y) < EPSILON || ft_double_compare(0.0, r.direction.y))
		return ;
	t = -r.origin.y / r.direction.y;
	ft_add_sorted_intersection(i, p, t);
}
