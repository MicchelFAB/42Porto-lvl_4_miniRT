/**
 * @file cone_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to handle the cone shape.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "minirt.h"
/**
 * @brief Function to form the cone equation.
 * 
 * @param ray 
 * @return t_bhask 
 */
t_bhask	ft_bhask_form_cone(t_ray ray)
{
	t_bhask	bhask;
	double	temp;

	bhask.a = ray.direction.x * ray.direction.x - ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z;
	bhask.b = 2 * ray.origin.x * ray.direction.x - 2 * ray.origin.y * ray.direction.y + 2 * ray.origin.z * ray.direction.z;
	bhask.c = ray.origin.x * ray.origin.x - ray.origin.y * ray.origin.y	+ ray.origin.z * ray.origin.z;
	bhask.discriminant = bhask.b * bhask.b - 4 * bhask.a * bhask.c;
	if (bhask.discriminant < 0)
		return (bhask);
	bhask.t0 = (-bhask.b - sqrt(bhask.discriminant)) / (2 * bhask.a);
	bhask.t1 = (-bhask.b + sqrt(bhask.discriminant)) / (2 * bhask.a);
	if (bhask.t0 > bhask.t1)
	{
		temp = bhask.t0;
		bhask.t0 = bhask.t1;
		bhask.t1 = temp;
	}
	return (bhask);
}
/**
 * @brief Function to handle the cone intersections.
 * 
 * @param i 
 * @param s 
 * @param ray 
 */
void	ft_cone_intersections(t_intersections **i, t_shapes *s, t_ray ray)
{
	t_bhask	bhask;
	double	y0;
	double	y1;

	ft_cone_caps_intersections(i, s, ray);
	bhask = ft_bhask_form_cone(ray);
	if (bhask.a == 0)
	{
		if (bhask.b == 0)
			return ;
		ft_add_sorted_intersection(i, s, -bhask.c / (2 * bhask.b));
		return ;
	}
	if (bhask.discriminant < 0)
		return ;
	y0 = ray.origin.y + bhask.t0 * ray.direction.y;
	if (s->cone->minimum < y0 && y0 < s->cone->maximum)
		ft_add_sorted_intersection(i, s, bhask.t0);
	y1 = ray.origin.y + bhask.t0 * ray.direction.y;
	if (s->cone->minimum < y1 && y1 < s->cone->maximum)
		ft_add_sorted_intersection(i, s, bhask.t1);
}
/**
 * @brief Function to check the cone caps.
 * 
 * @param ray 
 * @param t 
 * @param range 
 * @return true 
 * @return false 
 */
bool	ft_check_cone_cap(t_ray ray, double t, double range)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (x * x + z * z <= range * range);
}
/**
 * @brief Function to handle the cone caps intersections.
 * 
 * @param i 
 * @param s 
 * @param ray 
 */
void	ft_cone_caps_intersections(t_intersections **i, t_shapes *s, t_ray ray)
{
	double	t;

	if (s->cone->closed == false || ray.direction.y == 0)
		return ;
	t = (s->cone->minimum - ray.origin.y) / ray.direction.y;
	if (ft_check_cone_cap(ray, t, s->cone->minimum))
		ft_add_sorted_intersection(i, s, t);
	t = (s->cone->maximum - ray.origin.y) / ray.direction.y;
	if (ft_check_cone_cap(ray, t, s->cone->maximum))
		ft_add_sorted_intersection(i, s, t);
}
/**
 * @brief Function to get the normal at the cone.
 * 
 * @param cone 
 * @param point 
 * @return t_vec3 
 */
t_vec3	ft_cone_normal_at(t_shapes *cone, t_point point)
{
	double	dist;
	double	max_range;
	double	min_range;
	double	y;

	dist = point.x * point.x + point.z * point.z;
	max_range = cone->cone->maximum * cone->cone->maximum;
	if (dist < max_range && point.y >= cone->cone->maximum - EPSILON)
		return ((t_vec3){0, 1, 0, 0});
	min_range = cone->cone->minimum * cone->cone->minimum;
	if (dist < min_range && point.y <= cone->cone->minimum + EPSILON)
		return ((t_vec3){0, -1, 0, 0});
	y = sqrt(dist);
	if (point.y > 0)
		y = -y;
	return ((t_vec3){point.x, y, point.z, 0});
}
