/**
 * @file cube_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to handle the cube shape.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "shapes.h"
/**
 * @brief Function to check the axis of the cube.
 * 
 * @param t 
 * @param origin 
 * @param direction 
 */
void	ft_check_axis(double *t, double origin, double direction)
{
	double	tmin_numerator;
	double	tmax_numerator;
	double	temp;

	tmin_numerator = -1 - origin;
	tmax_numerator = 1 - origin;
	if (fabs(direction) >= EPSILON)
	{
		t[0] = tmin_numerator / direction;
		t[1] = tmax_numerator / direction;
	}
	else
	{
		t[0] = tmin_numerator * INFINITY;
		t[1] = tmax_numerator * INFINITY;
	}
	if (t[0] > t[1])
	{
		temp = t[0];
		t[0] = t[1];
		t[1] = temp;
	}
}
/**
 * @brief Function to handle the cube intersections.
 * 
 * @param intersections 
 * @param cube 
 * @param ray 
 */
void	ft_cube_intersections(t_intersections **intersections, t_shapes *cube, t_ray ray)
{
	double	xt[2];
	double	yt[2];
	double	zt[2];
	double	tmin;
	double	tmax;

	ft_check_axis(xt, ray.origin.x, ray.direction.x);
	ft_check_axis(yt, ray.origin.y, ray.direction.y);
	ft_check_axis(zt, ray.origin.z, ray.direction.z);
	tmin = fmax(fmax(xt[0], yt[0]), zt[0]);
	tmax = fmin(fmin(xt[1], yt[1]), zt[1]);
	if (tmin > tmax)
		return ;
	ft_add_sorted_intersection(intersections, cube, tmin);
	ft_add_sorted_intersection(intersections, cube, tmax);
}
/**
 * @brief Function to calculate the normal of the cube.
 * 
 * @param world_point 
 * @return t_vec3 
 */
t_vec3	ft_cube_normal_at(t_point world_point)
{
	double	max;

	max = fmax(fabs(world_point.x), fmax(fabs(world_point.y), fabs(world_point.z)));
	if (max == fabs(world_point.x))
		return (ft_vector(world_point.x, 0, 0));
	else if (max == fabs(world_point.y))
		return (ft_vector(0, world_point.y, 0));
	return (ft_vector(0, 0, world_point.z));
}
